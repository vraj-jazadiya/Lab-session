class Employee:
    
    def __init__(self):
        self.emp_no = 101
        
    def set_emp_name(self):
        self.emp_name = "vraj"
    
    def del_emp_name(self):
        del self.emp_name
        
emp = Employee()

emp.set_emp_name()

emp.emp_salary = 5000

print(emp.__dict__)

print("Employee Number:", emp.emp_no)
print("Employee Name:", emp.emp_name)
print("Employee Salary:", emp.emp_salary)



emp.del_emp_name()

del emp.emp_salary

print("\nAfter deleting emp_name and emp_salary:")
print(emp.__dict__)
