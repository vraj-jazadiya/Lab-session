class Student1:

    def set_name(self, name):
        self.name = name

    def set_roll_no(self, roll_no):
        self.roll_no = roll_no

    def set_total_marks(self, total_marks):
        self.total_marks = total_marks

    def get_name(self):
        return self.name

    def get_roll_no(self):
        return self.roll_no

    def get_total_marks(self):
        return self.total_marks

    def display(self):
        print("Student Name:", self.get_name())
        print("Roll Number:", self.get_roll_no())
        print("Total Marks:", self.get_total_marks())

    def grade(self):
        marks = self.get_total_marks()

        if marks >= 90:
            print("Grade: A")
        elif marks >= 75:
            print("Grade: B")
        elif marks >= 60:
            print("Grade: C")
        elif marks >= 50:
            print("Grade: D")
        else:
            print("Grade: F")


s = Student1()

s.set_name("Vraj")
s.set_roll_no(101)
s.set_total_marks(85)

s.display()

s.grade()