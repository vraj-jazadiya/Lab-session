class Mathoperation:

    @staticmethod
    def sum(a, b):
        return a + b

    @staticmethod
    def product(a, b):
        return a * b

    @staticmethod
    def average(a, b, c):
        return (a + b + c) / 3


print("Sum:", Mathoperation.sum(10, 20))
print("Sum:", Mathoperation.sum(100, 200))

print("Product:", Mathoperation.product(5, 4))
print("Product:", Mathoperation.product(10, 20))

print("Average:", Mathoperation.average(10, 20, 30))
print("Average:", Mathoperation.average(50, 60, 70))

