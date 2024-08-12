import cv2
import math

def getFaceMeshTargetTracking(image, lms):
    distSum = 0
    leftSum = 0
    rightSum = 0
    centerX, centerY = image.shape[1]//2, image.shape[0]//2
    for landmark in lms:
        id, lmx, lmy = landmark[0], landmark[1], landmark[2]
        if id == 0:
            continue
        elif id == 1:
             centerX, centerY = lmx, lmy
             cv2.circle(image, (lmx, lmy), 10, (255, 255, 0), 3)

        if id == 10 or id == 152 or id == 103 or id == 332 or id == 227 or id == 454 \
                or id == 136 or id == 365 or id == 149 or id == 378 or id == 172 or id == 364\
                or id == 215 or id == 435 or id == 67 or id == 297 or id == 54 or id == 284\
                or id == 176 or id == 400 or id == 215 or id == 435 or id == 147 or id == 376:
            dist = math.sqrt(math.pow(lmx-centerX, 2) + math.pow(lmy-centerY, 2))
            distSum += dist

        if id == 54 or id == 227 or id == 137 or id == 172 or id == 150:
            dist = math.sqrt(math.pow(lmx-centerX, 2) + math.pow(lmy-centerY, 2))
            leftSum += dist
        elif id == 284 or id == 447 or id == 323 or id == 397 or id == 379:
            dist = math.sqrt(math.pow(lmx-centerX, 2) + math.pow(lmy-centerY, 2))
            rightSum += dist

    distAvg = int(distSum/24)
    leftAvg = int(leftSum/5)
    rightAvg = int(rightSum/5)

    # print(distAvg*distAvg*math.pi)
    # cv2.rectangle(image, (centerX-distAvg, centerY-distAvg), (centerX+distAvg, centerY+distAvg), (255, 0, 255), 2)
    if distAvg > 0:
        cv2.circle(image, (centerX, centerY), distAvg, (255, 0, 255), 2)
        cv2.line(image, (int(centerX-distAvg*0.8), centerY), (int(centerX+distAvg*0.8), centerY), (255, 0, 255), 2, 1)
        cv2.line(image, (centerX, int(centerY-distAvg*0.8)), (centerX, int(centerY+distAvg*0.8)), (255, 0, 255),  2, 1)

    if leftAvg > rightAvg * 1.8:
        turnMode = "right"
        turnRate = leftAvg/rightAvg
    elif rightAvg > leftAvg * 1.8:
        turnMode = "left"
        turnRate = rightAvg/leftAvg
    else:
        turnMode = ""
        turnRate = 0


    if turnMode == "right":#rightTurnMode:
        cv2.putText(image, "TURN RIGHT: "+str(format(turnRate, ".2f")), (10, 60), cv2.FONT_HERSHEY_PLAIN, 1.5, (255, 255, 0), 2)
    elif turnMode == "left":#leftTurnMode:
        cv2.putText(image, "TURN LEFT: "+str(format(turnRate, ".2f")), (10, 60), cv2.FONT_HERSHEY_PLAIN, 1.5, (255, 255, 0), 2)

    # image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # cv2.imshow("Target Detection", image)

    return distAvg*distAvg*math.pi, turnMode, turnRate, centerX, centerY


def trackTargetFace(targetSize, turnMode, turnRate, centerX, centerY, fbRange, dampingFactor,
                    imgWidth, imgHeight):

    if turnMode == 'left':
        lrSpeed = int(turnRate * 8)
    elif turnMode == 'right':
        lrSpeed = int(-turnRate * 8)
    else:
        lrSpeed = 0

    # fbSpeed = 0
    if targetSize >= fbRange[0] and targetSize <= fbRange[1]:
        fbSpeed = 0
    elif targetSize > fbRange[1]:
        fbSpeed = -10 - int((targetSize-fbRange[1])*0.002)
    elif targetSize < fbRange[0]:
        fbSpeed = 10 + int((fbRange[0]-targetSize)*0.002)

    elError = (centerY+60) - imgHeight//2
    udSpeed = int(-elError * 0.2)

    azError = -(centerX - imgWidth//2)
    yawSpeed = int(dampingFactor[0]*azError + dampingFactor[1]*azError)

    return lrSpeed, fbSpeed, udSpeed, yawSpeed

