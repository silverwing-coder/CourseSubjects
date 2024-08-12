import cv2
import numpy as np

randomArray = np.random.randint(255, size=120000, dtype=np.uint8)
# print(randomArray)
grayImage = randomArray.reshape(300, 400)
cv2.imshow('GRAY IMG', grayImage)

gbrImage = randomArray.reshape(100, 400, 3)
cv2.imshow('GBR IMG', gbrImage)

cv2.waitKey(0)