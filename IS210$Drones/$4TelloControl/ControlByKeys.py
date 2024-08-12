from djitellopy import Tello
import cv2
from time import sleep
import KeyPressModule as kp

# Create a Drone object for operation
# drone = Tello()
# drone.connect()
# print(drone.get_battery())

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

    if kp.getKey("LEFT"):
        lr = -speed
    elif kp.getKey("RIGHT"):
        lr = speed

    if kp.getKey("UP"):
        fb = speed
    elif kp.getKey("DOWN"):
        fb = -speed

    if kp.getKey("w"):
        ud = speed
    elif kp.getKey("s"):
        ud = -speed

    if kp.getKey("a"):
        yv = speed
    elif kp.getKey("d"):
        yv = -speed

    if kp.getKey("q"):
        # drone.land()
        exit(0)

    return [lr, fb, ud, yv]

# drone.takeoff()

while True:

    vals = getKeyboardInput()
    print(vals[0], "-", vals[1], "-", vals[2], "-", vals[3])

    # drone.send_rc_control(vals[0], vals[1], vals[2], vals[3])
    sleep(0.05)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

