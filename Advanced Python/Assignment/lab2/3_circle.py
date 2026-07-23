
class Circle:

    def __init__(self, radius):
        self.radius = radius

    def area(self):
        area = 3.14 * self.radius * self.radius
        print("Area of Circle:", area)

    def circumference(self):
        circumference = 2 * 3.14 * self.radius
        print("Circumference of Circle:", circumference)


c = Circle(5)

c.area()

c.circumference()
