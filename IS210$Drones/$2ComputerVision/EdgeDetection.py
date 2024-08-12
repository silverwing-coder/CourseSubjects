import cv2

imgBGR = cv2.imread("ImageFiles/GoTable.jpg")

imgGray = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2GRAY)
cv2.imshow('Gray', imgGray)
cv2.waitKey(0)

medianBlur = cv2.medianBlur(imgGray, 7)
cv2.imshow('MEDIAN', medianBlur)
cv2.waitKey(0)
#
# edgeLaplacian = cv2.Laplacian(imgGray, cv2.CV_BU, ksize=5)
# cv2.imshow('Laplacian', edgeLaplacian)
# cv2.waitKey(0)

edgeSobelX = cv2.Sobel(imgGray, cv2.CV_64F, 1, 0, ksize=5)
cv2.imshow('SobelX', edgeSobelX)
cv2.waitKey(0)
edgeSobelY = cv2.Sobel(imgGray, cv2.CV_64F, 0, 1, ksize=5)
cv2.imshow('SobelY', edgeSobelY)
cv2.waitKey(0)
edgeSobelXY = cv2.Sobel(imgGray, cv2.CV_64F, 1, 1, ksize=5)
cv2.imshow('SobelXY', edgeSobelXY)
cv2.waitKey(0)

edgeCanny = cv2.Canny(imgGray, 100, 200)
cv2.imshow('Canny', edgeCanny)
cv2.waitKey(0)



