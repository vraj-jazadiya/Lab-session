# 6.	Create a one class Test that contains constructor and destructor.
# a.	Now create four reference variable  t1,t2,t3,t4 that points to Test class.
# b.	Print no of reference variable .
# c.	Now delete t1 and t3 and check whether destructor is called or not.
# d.	Now delete t2 and t4 and check whether destructor is called or not.

class Test:
    def __init__(self):
        print("Onbject Initialization...")
    def __del__(self):
        print("Performing clean up activities...")

t1 = Test()
t2 = t1
t3 = t1
t4 = t1

print("Number of reference variables:", 4)
del t1
del t3

print("Deleted t1 and t3. Destructor should not be called yet.")
del t2
del t4
print("Deleted t2 and t4. Destructor should be called now.")