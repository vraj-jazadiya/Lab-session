class Student:

    def __init__(self, name, roll_no, total_marks):
        self.name = name
        self.roll_no = roll_no
        self.total_marks = total_marks

    def display(self):
        print("Student Name:", self.name)
        print("Roll Number:", self.roll_no)
        print("Total Marks:", self.total_marks)

    def grade(self):
        if self.total_marks >= 90:
            print("Grade: A")
        elif self.total_marks >= 75:
            print("Grade: B")
        elif self.total_marks >= 60:
            print("Grade: C")
        elif self.total_marks >= 50:
            print("Grade: D")
        else:
            print("Grade: F")


s = Student("Vraj", 101, 85)

s.display()

s.grade()




