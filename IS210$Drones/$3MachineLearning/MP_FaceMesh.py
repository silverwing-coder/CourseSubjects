import mediapipe as mp
import cv2

# imgWidth, imgHeight = 600, 480
imgWidth = 600
imgHeight = 480

capture = cv2.VideoCapture(0)

capture.set(3, imgWidth)
capture.set(4, imgHeight)

face_mesh_module = mp.solutions.face_mesh
mesh_detector = face_mesh_module.FaceMesh(static_image_mode=False, max_num_faces=1,
                                          min_detection_confidence=0.5, min_tracking_confidence=0.5)
mesh_drawer = mp.solutions.drawing_utils
draw_spec = mesh_drawer.DrawingSpec(thickness=1, circle_radius=1)

while True:
    ret, image = capture.read()
    image = cv2.flip(image, 1)

    imgRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    face_mesh = mesh_detector.process(imgRGB)

    if face_mesh.multi_face_landmarks:
        for face_lms in face_mesh.multi_face_landmarks:
            mesh_drawer.draw_landmarks(image, face_lms, face_mesh_module.FACE_CONNECTIONS, draw_spec, draw_spec)

    cv2.imshow('MESH', image)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()

