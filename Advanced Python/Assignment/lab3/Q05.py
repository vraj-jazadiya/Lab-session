# 5.	Destructor :
# Example :
#  import time
# class Test:
#     def __init__(self):
#         print("Object Initialization...") 
#     def __del__(self): 
#         print("Performing clean up activities...")
        
# t1=Test() 
# t1=None
# time.sleep(5)
# print(“End of Application….”)

import time

class Test:
    def __init__(self):
        print("Object Initialization...")

    def __del__(self):
        print("Performing clean up activities..")

t1 = Test()
t1 = None       
time.sleep(5)
print("End of Application....")