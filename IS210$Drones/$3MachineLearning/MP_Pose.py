import mediapipe as mp
import cv2

imgWidth = 600
imgHeight = 480

capture = cv2.VideoCapture(0)

capture.set(3, imgWidth)
capture.set(4, imgHeight)

pose_detect_module = mp.solutions.pose
pose_dector = pose_detect_module.Pose(static_image_mode=False, model_complexity=1,
                                      smooth_landmarks=True, min_detection_confidence=0.5,
                                      min_tracking_confidence=0.5)
pose_drawer = mp.solutions.drawing_utils

while True:
    ret, image = capture.read()
    image = cv2.flip(image, 1)

    imgRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    pose = pose_dector.process(imgRGB)

    if pose.pose_landmarks:
        pose_drawer.draw_landmarks(image, pose.pose_landmarks, pose_detect_module.POSE_CONNECTIONS)

    cv2.imshow('IMAGE', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()

