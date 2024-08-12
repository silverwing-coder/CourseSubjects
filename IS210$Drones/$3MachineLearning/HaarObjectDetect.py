import cv2

cascade_face = cv2.CascadeClassifier('HaarFiles/haarcascade_frontalface_alt.xml')
cascade_eye = cv2.CascadeClassifier('HaarFiles/haarcascade_eye.xml')
# cascade_eye_glass = cv2.CascadeClassifier('HaarFiles/haarcascade_eye_tree_eyeglasses.xml')

# imgGBR = cv2.imread('ImgFiles/faces.jpg')
# imgGBR = cv2.imread('ImgFiles/faces2.jpeg')
# imgGray = cv2.cvtColor(imgGBR, cv2.COLOR_BGR2GRAY)
#
# faces = cascade_face.detectMultiScale(imgGray, 1.08, 5)
# eyes = cascade_eye.detectMultiScale(imgGray, 1.08, 5)
# for (x, y, w, h) in faces:
#     imgGBR = cv2.rectangle(imgGBR, (x, y), (x+w, y+h), (255, 0, 0), 2)
#
# for (x, y, w, h) in eyes:
#     imgGBR = cv2.circle(imgGBR, (x+w//2, y+h//2), 10, (0, 255, 0), 2)
#
# # cv2.namedWindow('FACES')
# cv2.imshow('FACES', imgGBR)
# cv2.waitKey(0)

# capture = cv2.VideoCapture(0)
capture = cv2.VideoCapture('MovieClips/TwoPeople.mp4')

while True:
    success, imgBGR = capture.read()

    width = int(imgBGR.shape[1] * 0.5)
    height = int(imgBGR.shape[0] * 0.5)
    imgResized = cv2.resize(imgBGR, dsize=(width, height))

    imgGray = cv2.cvtColor(imgResized, cv2.COLOR_BGR2GRAY)

    faces = cascade_face.detectMultiScale(imgGray, 1.08, 5)
    for (x, y, w, h) in faces:
        imgBGR = cv2.rectangle(imgResized, (x, y), (x+w, y+w), (0, 255, 0), 3)
    eyes = cascade_eye.detectMultiScale(imgGray, 1.08, 5)
    for (x, y, w, h) in eyes:
        imgBGR = cv2.rectangle(imgResized, (x, y), (x + w, y + w), (255, 255, 0), 3)

    cv2.imshow('VIDEO', imgResized)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()





