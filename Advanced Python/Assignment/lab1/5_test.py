
class Test:

    def __init__(self):
        self.a = 10
        self.b = 20


t1 = Test()
t2 = Test()

t1.a = 100
t1.b = 200

print("Instance variables of t1:")
print(t1.__dict__)

print("\nInstance variables of t2:")
print(t2.__dict__)
