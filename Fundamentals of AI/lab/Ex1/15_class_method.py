class Point:
    def __init__(self , x=0,y=0):
        self.x = x
        self.y = y
        
    def add_points(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Point(x,y)
    
P1 = Point(1,2)
P2 = Point(3,4)

p3 = P1.add_points(P2)

print((p3.x , p3.y))