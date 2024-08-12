import cv2

# capture = cv2.VideoCapture("MovieClips/TwoPeople.mp4")
capture = cv2.VideoCapture(0)

if capture.isOpened() ==  False:
    print("Error in opening the movie clip")

while capture.isOpened():
    succsss, imgBGR = capture.read()

    # width = int(imgBGR.shape[1] * 0.5)
    # height = int(imgBGR.shape[0] * 0.5)
    # imgResized = cv2.resize(imgBGR, dsize=(width, height))

    # cv2.imshow('MOVIE', imgBGR)
    grayImg = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2GRAY)
    cv2.imshow('GRAY', grayImg)
    # cv2.imwrite("")
    #
    # imgCanny = cv2.Canny(imgBGR, 50, 10)
    # cv2.imshow('MOVIE', imgCanny)

    if cv2.waitKey(1) & 0xFF == ord('c'):
        org_img = imgBGR
        # This code is for saving original image
        cv2.imwrite("org_img.jpg", org_img)

        gray_img = cv2.cvtColor(org_img, cv2.COLOR_BGR2GRAY)
        # This statement is for s
        cv2.imwrite("gray_img.jpg", gray_img)
        hsv_img = cv2.cvtColor(org_img, cv2.COLOR_BGR2HSV)
        cv2.imwrite("hsv_img.jpg", hsv_img)



    #     ##########
    #     Implement to get blur filtered and edge filtered images and saves it to ...1
    #     1. averageBlur_img.jpg
        avgBlurImg = cv2.blur(gray_img, (5, 5))
        cv2.imwrite("averageBlur_img.jpg", avgBlurImg)
    #     2. GaussianBlur_img.jpg
        GauBlurImg = cv2.GaussianBlur(gray_img, (5, 5), cv2.BORDER_DEFAULT)
        cv2.imwrite("GaussianBlur_img.jpg", GauBlurImg)

    #     3. sobelXY_img.jpg

    #     4. canny_img.jpg


    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()


