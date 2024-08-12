from djitellopy import Tello
import cv2
from time import sleep
import numpy as np
import KeyPressModule as kp

# Create a Drone object for operation
# drone = Tello()
# drone.connect()
# print(drone.get_battery())

############## PARAMETERS ######################
fwd_speed = 117/10 # Forward speed in cm/s
ang_speed = 360/10 # Angular speed in degrees/s
interval = 0.25

dist_interval = fwd_speed*interval
ang_interval = ang_speed*interval
################################################

x, y = 300, 300
angle = 0
yaw = 0

# Turn on drone camera
# drone.streamon()
# frame = drone.get_frame_read()

# Start keyPressModule to listen Key press status
kp.init()


def getKeyboardInput():
    #
    # frame = drone.get_frame_read().frame
    # cv2.resize(frame, (300, 200))
    # cv2.imshow('DRONE', frame)

    lr, fb, ud, yv = 0, 0, 0, 0
    speed = 50
    distance = 0

    if kp.getKey("LEFT"):
        lr = -speed
        distance = dist_interval
        angle = -180
    elif kp.getKey("RIGHT"):
        lr = speed
        distance = -dist_interval
        angle = 180

    if kp.getKey("UP"):
        fb = speed
        distance = dist_interval
        angle = -270
    elif kp.getKey("DOWN"):
        fb = -speed
        distance = -dist_interval
        angle = -90

    if kp.getKey("w"):
        ud = speed
    elif kp.getKey("s"):
        ud = -speed

    if kp.getKey("a"):
        yv = speed
        yaw += ang_interval
    elif kp.getKey("d"):
        yv = -speed
        yaw -= ang_interval

    # if kp.getKey("e"): drone.takeoff()
    if kp.getKey("q"):
        # drone.land()
        exit(0)

    return [lr, fb, ud, yv]

# drone.takeoff()


def drawPoints(image):
    cv2.circle(image, (x, y), 5, (0, 0, 255), cv2.FILLED)

while True:

    vals = getKeyboardInput()
    # drone.send_rc_control(vals[0], vals[1], vals[2], vals[3])
    # sleep(0.05)

    image = np.zeros((600, 600, 3), np.uint8)
    drawPoints(image)
    cv2.imshow('IMAGE', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

