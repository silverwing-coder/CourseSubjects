import math

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def getArea(self):
        return self.radius * self.radius * math.pi

#
# circleA = Circle(10)
# circleB = Circle(20)
# circleC = Circle(30)
#
# print(circleA.radius)
# print(circleA.getArea())
# print(circleB.radius)
# print(circleB.getArea())
# print(circleC.radius)
# print(circleC.getArea())