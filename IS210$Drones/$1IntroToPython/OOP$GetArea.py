import math
class GetArea:
    def __init__(self, name):
        self.name = name

    def getCircleArea(self, radius):
        return math.pi * radius * radius

    def getRectangleArea(self, side1, side2):
        return side1 * side2


def main():
    objectGetArea = GetArea("Calculate Areas")
    print(objectGetArea.name)

    cirArea = objectGetArea.getCircleArea(10)
    print(cirArea)

    rectArea = objectGetArea.getRectangleArea(20, 20)
    print(rectArea)

if __name__ == '__main__':
    main()