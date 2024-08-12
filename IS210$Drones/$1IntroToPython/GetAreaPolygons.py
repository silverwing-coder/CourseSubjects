import math

class GetArea:
    def __init__(self, name):
        self.name = name

    def getCircleArea(self, radius):
        return radius * radius * math.pi

    def getRectArea(self, side1, side2):
        return side1 * side2

    def getTriArea(self, height, base):
        return (height * base)/2