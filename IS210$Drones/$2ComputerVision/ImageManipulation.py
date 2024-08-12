import cv2

imgBGR = cv2.imread("ImageFiles/faces.jpg")
# cv2.imshow("ORIGINAL IMG", imgBGR)

imgGray = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2GRAY)
# cv2.imshow("GRAY IMG", imgGray)
#
# imgHSV = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2HSV)
# cv2.imshow("HSV IMG", imgHSV)

# imgAverage = cv2.blur(imgBGR, (5, 5))
# cv2.imshow('AVERAGE BLUR', imgAverage)
#
# imgGaussan = cv2.GaussianBlur(imgBGR, (5, 5), cv2.BORDER_DEFAULT)
# cv2.imshow('GAUSSIAN BLUR', imgGaussan)

# imgDilated = cv2.dilate(imgGray, (3, 3), iterations=3)
# cv2.imshow('DILATED', imgDilated)
#
# imgErode = cv2.erode(imgGray, (3, 3), iterations=3)
# cv2.imshow('ERODE', imgErode)
#
# imgCanny = cv2.Canny(imgGray, 50, 10)
# cv2.imshow('CANNY', imgCanny)
#
# edgeSobelX = cv2.Sobel(imgGray, cv2.CV_64F, 1, 0, ksize=5)
# cv2.imshow('SobelX', edgeSobelX)
# cv2.waitKey(0)
# edgeSobelY = cv2.Sobel(imgGray, cv2.CV_64F, 0, 1, ksize=5)
# cv2.imshow('SobelY', edgeSobelY)
# cv2.waitKey(0)
# edgeSobelXY = cv2.Sobel(imgGray, cv2.CV_64F, 1, 1, ksize=5)
# cv2.imshow('SobelXY', edgeSobelXY)
# cv2.waitKey(0)

cv2.waitKey(0)
cv2.destroyAllWindows()