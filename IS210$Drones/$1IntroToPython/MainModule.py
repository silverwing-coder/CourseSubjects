from ClassCircle import Circle
from GetAreaPolygons import GetArea

# circleA = ClassCircle.Circle(15)
# circleA = Circle(15)
# print(circleA.radius)
# print(circleA.getArea())

calulator = GetArea("GetAreaClass")

areaCircle = calulator.getCircleArea(10)
areaRect = calulator.getRectArea(10, 30)
areaTri = calulator.getTriArea(10, 30)

print("Circle:", areaCircle, ", Rect:", areaRect, ", Tri:", areaTri)
