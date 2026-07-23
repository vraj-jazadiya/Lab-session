
class Test:

    def __init__(self):
        self.a = 10
        self.b = 20
        self.c = 30
        self.d = 40

t1 = Test()
t2 = Test()

del t1.a

print("Instance variables of t1:")
print(t1.__dict__)

print("\nInstance variables of t2:")
print(t2.__dict__)

