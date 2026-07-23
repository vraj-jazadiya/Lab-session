class Person:

    class DOB:

        def __init__(self, dd, mm, yyyy):
            self.dd = dd
            self.mm = mm
            self.yyyy = yyyy

        def display(self):
            print("DOB:", self.dd, "/", self.mm, "/", self.yyyy)

    def __init__(self, name, dd, mm, yyyy):
        self.name = name

        self.dob = Person.DOB(dd, mm, yyyy)

    def display(self):
        print("Name:", self.name)
        self.dob.display()


p = Person("Vraj", 10, 5, 1947)

p.display()
