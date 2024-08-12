import mediapipe as mp
import cv2

imgWidth = 600
imgHeight = 480

capture = cv2.VideoCapture(0)

capture.set(3, imgWidth)
capture.set(4, imgHeight)

hand_detect_module = mp.solutions.hands
hand_dector = hand_detect_module.Hands()
hand_drawer = mp.solutions.drawing_utils

while True:
    ret, image = capture.read()
    image = cv2.flip(image, 1)

    imgRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    hands = hand_dector.process(imgRGB)

    if hands.multi_hand_landmarks:
        for hand_landmarks in hands.multi_hand_landmarks:
            hand_drawer.draw_landmarks(image, hand_landmarks, hand_detect_module.HAND_CONNECTIONS)

    cv2.imshow('IMAGE', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()

