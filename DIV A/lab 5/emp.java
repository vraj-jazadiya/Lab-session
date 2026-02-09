class Employee{
    int EmpId;
    String EmpName;
    String Department;
    Double Salary;

    Employee(int EmpId, String EmpName, String Department, Double Salary){
        this.EmpId = EmpId;
        this.EmpName = EmpName;
        this.Department = Department;
        this.Salary = Salary;
    }

    void display(){
        System.out.println("Employee ID: " + EmpId);
        System.out.println("Employee Name: " + EmpName);
        System.out.println("Department: " + Department);
        System.out.println("Salary: " + Salary);
    }

    
}

public class emp{
    public static void main(String[] args) {
        System.out.println("code started");

        Employee emp1  = new Employee(291056,"xyz", "Sales", 50000.0);

        emp1.display();
    }
}