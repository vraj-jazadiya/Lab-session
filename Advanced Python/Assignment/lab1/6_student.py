
class Student:

    # inside class
    clg_name = "ABC College"

    def __init__(self):
        # inside constructor
        Student.class_name = "BCA"

    def set_faculty_name(self):
        # instance method
        Student.faculty_name = "Computer Science"


# object reference
s = Student()

# call instance method
s.set_faculty_name()

#outside the class
Student.teacher_name = "Mr. Sharma"


print("Static variables using __dict__:")
print(Student.__dict__)

print("\nStatic variable values:")
print("College Name:", Student.clg_name)
print("Class Name:", Student.class_name)
print("Faculty Name:", Student.faculty_name)
print("Teacher Name:", Student.teacher_name)


del Student.clg_name
del Student.class_name
del Student.faculty_name
del Student.teacher_name


print("\nAfter deleting all static variables:")
print(Student.__dict__)

