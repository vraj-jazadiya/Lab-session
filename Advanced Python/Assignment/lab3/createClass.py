# Create a class Employee class that contains emp_name,emp_department,emp_salary as variables.
# Add display() that display details of employee.
# Create another class UpdateEmp which contains one method updateinfo() that modify salary and department of employee.[Here this method receive object of Employee class]


class Employee:
    emp_name,emp_department,emp_salary = "NA","NA",0
    
    def __init__(self,name,dprt , salary):
        self.emp_name = name
        self.emp_department = dprt
        self.emp_salary = salary
    
    def display(self):
        print("Name       :", self.emp_name)
        print("Department :", self.emp_department)
        print("Salary     :", self.emp_salary)
        
    
    
class UpdateEmp:
    def updateinfo(self,emp):
        emp.emp_department = input("Enter New Department: ")
        emp.emp_salary = float(input("Enter New Salary: "))
        
        
name = input("Enter Employee Name: ")
department = input("Enter Department: ")
salary = float(input("Enter Salary: "))

emp = Employee(name, department, salary)

print("\nBefore Update")
emp.display()

up = UpdateEmp()
up.updateinfo(emp)

print("\nAfter Update")
emp.display()