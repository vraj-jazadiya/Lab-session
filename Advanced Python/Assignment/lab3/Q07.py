# 7.	rCeate a one class Test that contains constructor and destructor.
# a.	Now create one list object that contains 4 objects of Test class.                        
#   list = [Test(),Test(),Test(),Test()]
# b.	Now del list object and check how many times constructor and destructor will be called.

class Test:
    def __init__(self):
        print("Object Initialization...")

    def __del__(self):
        print("Performing clean up activities...")

list = [Test(), Test(), Test(), Test()]
del list