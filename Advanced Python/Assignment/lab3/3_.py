class FOS:
    class BCA_Dept:
        Department = "BCA"
        count=0
        
        def __init__(self):
            FOS.BCA_Dept.count+=1
            
        def total_admission(self):
            print("Department :", self.Department)
            print("Total Admission :", FOS.BCA_Dept.count)
            
        def display(self):
            print(self.count)
            
            
    class Chemistry_Dept:
        count=0
        Department = "Chemistry"
        
        def __init__(self):
            FOS.Chemistry_Dept.count+=1
        
        def total_admission(self):
                    print("Department :", self.Department)
                    print("Total Admission :", FOS.Chemistry_Dept.count)
            
        def display(self):
            print(self.count)
            print(self.Department)
            
            
    class Maths_Dept:
        count=0
        Department = "Maths"

        def __init__(self):
            FOS.Maths_Dept.count+=1
        
        def total_admission(self):
                    print("Department :", self.Department)
                    print("Total Admission :", FOS.Maths_Dept.count)
            
        def display(self):
            print(self.count)
            print(self.Department)
    