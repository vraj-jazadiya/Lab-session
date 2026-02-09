public class p6
{
    public static void main(String[] args) {

        Student s1 = new Student();
        s1.display();
        Student s2 = new Student(104, "b1");
        s2.display();

    }
}

class Student {
    int id;
    String name;

    Student() {

        id = 101;
        name = "a1";
    }

    public Student(int i, String n) {
        id = i;
        name = n;
    }

    void display() {

        System.out.println("id=" + id);
        System.out.println("name=" + name);
    }
}