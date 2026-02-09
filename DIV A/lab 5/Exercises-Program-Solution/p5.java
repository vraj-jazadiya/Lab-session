public class p5 {

    public static void main(String[] args) {

        Department d1 = new Department(101, "IT");

        d1.display();
    }
}

class Department {

    int dept_id;
    String dept_name;

    Department(int id, String dname) {
        dept_id = id;
        dept_name = dname;

    }

    void display() {

        System.out.println("dept id=" + dept_id);
        System.out.println("dept name=" + dept_name);

    }
}