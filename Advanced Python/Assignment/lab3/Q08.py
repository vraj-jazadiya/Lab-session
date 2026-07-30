#Operator Overloading

#Example: 1

class A:
    def __init__(self, a):
        self.a = a

    #Addition of two obj

    def __add__(self, o):
        return self.a + o.a

ob1 = A(10)
ob2 = A(20)
ob3 = A("Dhyey")
ob4 = A("Patel")

print(ob1 + ob2)
print(ob3 + ob4)

#Example: 2

class complex:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    #Addition of two objects

    def __add__(self, other):
        return self.a + other.a, self.b + other.b

    def __str__(self):
        return self.a, self.b

Ob1 = complex(1, 2)
Ob2 = complex(2, 3)
Ob3 = Ob1 + Ob2
print(Ob3)