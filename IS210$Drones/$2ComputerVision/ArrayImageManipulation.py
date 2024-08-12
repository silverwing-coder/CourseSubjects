import cv2 as cv
import numpy as np
import random
import os
from matplotlib import pyplot as plt

# randByteArray = bytearray(os.urandom(100))
# print(randByteArray)
# npArray = np.array(randByteArray)
# print((npArray))
# grayImage = npArray.reshape(10, 10)
# print(grayImage)

# randArray1 = []
# for i in range(40):
#     randCol = []
#     for j in range(30):
#         x = random.randint(0, 255)
#         randCol.append(x)
#     randArray1.append(randCol)
#     randCol = []
# cv.imshow('GRAY', randArray1)
# print(randArray1)

randArray = np.random.randint(255, size=120000, dtype=np.uint8)
print(type(randArray))
grayImage = randArray.reshape(300, 400)
# grayImage = np.random.randint(255, size=(300, 400), dtype=np.uint8)
cv.imshow("GRAY", grayImage)

rgbImage = randArray.reshape(100, 400, 3)
cv.imshow("RGB", rgbImage)

# image = np.random.randint(255, size=(300, 300))
# cv.imshow("IMAGE", grayImage)

print(ord('A'))

cv.waitKey(0)
