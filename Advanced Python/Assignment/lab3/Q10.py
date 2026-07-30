# 10.	Create one Employee class and one Workingdays class
# a.	In Employee class pass name of employee and salary within constructor.
# b.	In Workingday class pass total working days of month  within constructor.
# c.	Now find monthly salary by overloading * operator.

class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary

class Workingdays:
    def __init__(self, total_days):
        self.total_days = total_days

    def __mul__(self, other):
        if isinstance(other, Employee):
            return self.total_days * other.salary
        return NotImplemented

# Example usage:
employee = Employee("Raghav", 500)
working_days = Workingdays(20)
monthly_salary = working_days * employee
print(f"Monthly Salary of {employee.name} is: {monthly_salary}")