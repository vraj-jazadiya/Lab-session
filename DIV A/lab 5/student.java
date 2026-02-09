class Student {
    int Rollno;
    String Name;

    Student() {
        Rollno = 1;
        Name = "Student1";
    }

    Student(int Rollno, String Name) {
        this.Rollno = Rollno;
        this.Name = Name;
    }

    void display() {
        System.out.println("Student RollNo : " + Rollno);
        System.out.println("student name : " + Name);
    }
}

public class student {
    public static void main(String[] args) {
        System.out.println();

        Student st1 = new Student();
        st1.display();
        System.out.println();
        Student st2 = new Student(69, "vraj");
        st2.display();
    }
}
