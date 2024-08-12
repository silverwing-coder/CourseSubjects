# Main module of Drone Demonstration Project for the new students in Carolina University.
# Package employed : opencv-contrib-python, mediapipe
# Developed by Sangmork Park. July-2021.

from MainModuleFunctions import *

import djitellopy
# import FaceMeshModule
import cv2
import mediapipe as mp

imgWidth, imgHeight =640, 480
dampingFactor = [0.1, 0.05, 0]
# correctionFactor = 10
fbRange = [7500, 8500]

def getFaceLandmarks(image, mode):

    static_image_mode = False
    max_num_faces = 1
    min_detection_confidence = 0.5
    min_tracking_confidence = 0.5

    mesh_detect_module = mp.solutions.face_mesh
    mesh_detector = mesh_detect_module.FaceMesh(static_image_mode, max_num_faces,
                                                min_detection_confidence, min_tracking_confidence)

    face_meshes = mesh_detector.process(image)
    # face_meshes = self.__mesh_detector.process(image)

    ih, iw, ic = image.shape
    face_landmarks = []
    if face_meshes.multi_face_landmarks:
        for id, face_lms in enumerate(face_meshes.multi_face_landmarks):
            for id, lm in enumerate(face_lms.landmark):
                cx, cy = int(lm.x * iw), int(lm.y * ih)
                face_landmarks.append((id, cx, cy))

    return face_landmarks


def main():

    # drone = djitellopy.Tello()
    # drone.connect()
    # print(drone.get_battery())
    #
    # drone.streamon()
    # drone.takeoff()
    #
    # drone.move_up(50)

    # meshDetector = FaceMeshModule.FaceMeshDetector()
    capture = cv2.VideoCapture(0)

    while True:

        # image = drone.get_frame_read().frame
        ret, image = capture.read()
        # print(len(image))
        image = cv2.resize(image, (imgWidth, imgHeight))
        image = cv2.flip(image, 1)
        imageRGB = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        # face_lms = meshDetector.getFaceLandmarks(imageRGB, False)
        face_lms = getFaceLandmarks(imageRGB, False)

        if len(face_lms) < 10:
            # drone.send_rc_control(0, 0, 0, 5)
            print("No lms")

        else:
            targetSize, turnMode, turnRate, centerX, centerY = getFaceMeshTargetTracking(imageRGB, face_lms)
            # print(targetSize)

            fbRange = [7500, 8500]
            lrSpeed, fbSpeed, udSpeed, yawSpeed = trackTargetFace(targetSize, turnMode, turnRate, centerX, centerY,
                                                                      fbRange, dampingFactor, imgWidth, imgHeight)
            print(lrSpeed, fbSpeed, udSpeed, yawSpeed)
            # drone.send_rc_control(int(lrSpeed), int(fbSpeed), int(udSpeed), int(yawSpeed))

        imageRGB = cv2.cvtColor(imageRGB, cv2.COLOR_BGR2RGB)
        cv2.imshow("Target Detection", imageRGB)

        if cv2.waitKey(1) == ord('q'):
            break

    # capture.release()
    # drone.land()
    # drone.streamoff()
    cv2.destroyAllWindows()

#
if __name__ == '__main__':
    main()