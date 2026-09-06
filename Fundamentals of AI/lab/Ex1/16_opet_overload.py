class Person:
    def __init__(self,name , age):
        self.name = self.name
        self.age = self.age
        
    def __lt__(self, other):
        return self.age < other.age
    
    
p1 = Person("ALice" , 20)
p2 = Person("Bob" , 30)


print(p1 < p2)
print(p2 < p1)
