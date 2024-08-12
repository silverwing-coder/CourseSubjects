import mediapipe as mp
import cv2

# imgWidth, imgHeight = 600, 480
imgWidth = 600
imgHeight = 480

capture = cv2.VideoCapture(0)

capture.set(3, imgWidth)
capture.set(4, imgHeight)

face_detect_module = mp.solutions.face_detection
face_dector = face_detect_module.FaceDetection()
face_drawer = mp.solutions.drawing_utils

while True:
    ret, image = capture.read()
    image = cv2.flip(image, 1)

    imgRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    faces = face_dector.process(imgRGB)

    if faces.detections:
        for id, face in enumerate(faces.detections):
            face_drawer.draw_detection(image, face)

            detection_score = face.score

            face_relative_box = face.location_data.relative_bounding_box
            imgHeight, imgWidth, imgChannel = image.shape

            face_box = int(face_relative_box.xmin*imgWidth), int(face_relative_box.ymin*imgHeight), \
                       int(face_relative_box.width*imgWidth), int(face_relative_box.height*imgHeight)

            cv2.rectangle(image, face_box, (255, 0, 255), 2)
    cv2.imshow('IMAGE', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()

