class Person:
    
    class DOB:
        def __init__(self, dd, mm, yyyy):
            self.dd = dd
            self.mm = mm
            self.yyyy = yyyy

        def display(self):
            print("DOB :", self.dd, "/", self.mm, "/", self.yyyy, sep="")
            
    def __init__(self, name, dd, mm, yyyy):
        self.name = name
        self.dob = Person.DOB(dd, mm, yyyy)

    def display(self):
        print("Name :", self.name)
        self.dob.display()
        
        
name = input("Enter Name: ")
dd = int(input("Enter Day: "))
mm = int(input("Enter Month: "))
yyyy = int(input("Enter Year: "))

p = Person(name, dd, mm, yyyy)

print("\nPerson Details")
p.display()