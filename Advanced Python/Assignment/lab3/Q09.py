# 9.	Create one BCA class that contains constructor with one arguments no of students.
# a.	Now create two reference variable fybca and sybca.
# b.	Now try to add fybca and sybca that display total no of students in BCA.
# c.	Now create one more reference variable tybca and now add all three objects fybca+sybca+tybca that display total no of students available in BCA department.
# d.	Print meaningful information for reference variable.

class BCA:
    def __init__(self, no_of_students):
        self.no_of_students = no_of_students

    def __add__(self, other):
        return BCA(self.no_of_students + other.no_of_students)

    def __str__(self):
        return f"Total Students = {self.no_of_students}"


fybca = BCA(120)
sybca = BCA(130)
tybca = BCA(140)

print("FYBCA :", fybca)
print("SYBCA :", sybca)
print("TYBCA :", tybca)

total1 = fybca + sybca
print("\nFYBCA + SYBCA =", total1)

total2 = fybca + sybca + tybca
print("FYBCA + SYBCA + TYBCA =", total2)