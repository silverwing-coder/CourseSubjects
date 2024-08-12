import cv2

face_cascade_face = cv2.CascadeClassifier('HaarFiles/haarcascade_frontalface_alt.xml')
face_cascade_eye = cv2.CascadeClassifier('HaarFiles/haarcascade_eye.xml')
face_cascade_eye_glass = cv2.CascadeClassifier('HaarFiles/haarcascade_eye_tree_eyeglasses.xml')

# imgGBR = cv2.imread('ImageFiles/faces2.jpeg')
# imgGray = cv2.cvtColor(imgGBR, cv2.COLOR_BGR2GRAY)
#
# faces = face_cascade_face.detectMultiScale(imgGray, 1.08, 5)
# eyes = face_cascade_eye.detectMultiScale(imgGray, 1.08, 5)
# for (x, y, w, h) in faces:
#     imgGBR = cv2.rectangle(imgGBR, (x, y), (x+w, y+h), (255, 0, 0), 2)
# for (x, y, w, h) in eyes:
#     imgGBR = cv2.circle(imgGBR, (x+w//2, y+h//2), 10, (0, 255, 0), 2)
#
# # cv2.namedWindow('FACES')
# cv2.imshow('FACES', imgGBR)
# cv2.waitKey(0)

capture = cv2.VideoCapture(1)

while True:
    success, imgGBR = capture.read()
    imgGray = cv2.cvtColor(imgGBR, cv2.COLOR_BGR2GRAY)

    faces = face_cascade_face.detectMultiScale(imgGray, 1.08, 5)
    # eyes = face_cascade_eye.detectMultiScale(imgGray, 1.08, 5)
    eyes = face_cascade_eye_glass.detectMultiScale(imgGray, 1.08, 5)
    for (x, y, w, h) in faces:
        imgGBR = cv2.rectangle(imgGBR, (x, y), (x+w, y+h), (255, 0, 0), 2)
    for (x, y, w, h) in eyes:
        imgGBR = cv2.circle(imgGBR, (x+w//2, y+h//2), 10, (0, 255, 0), 2)

    # cv2.namedWindow('FACES')
    cv2.imshow('FACES', imgGBR)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()