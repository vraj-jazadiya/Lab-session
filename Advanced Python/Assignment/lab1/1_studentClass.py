class Student:
    """This is a Student class to store student details.

    Attributes:
        name (str): The name of the student.
        rollno (int): The roll number of the student.
        marks (int): The marks obtained by the student.
    """
    
    def __init__(self, name, rollno, marks):

        self.name = name
        self.rollno = rollno
        self.marks = marks
        print(f"Student {self.name} created.")

    def talk(self):
        """Prints the details of the student.
        Also checks the memory address of 'self' within the method.
        """

        print(f"Hello My Name is: {self.name}")
        print(f"My Rollno is: {self.rollno}")
        print(f"My Marks are: {self.marks}")
        print(f"Memory address of 'self' inside talk() method: {id(self)}")

s1 = Student("Vraj" , 69 , 100)
s1.talk()

# Printing class documentation
print("\n--- Class Documentation ---")
print(Student.__doc__)
print(Student.talk.__doc__)
