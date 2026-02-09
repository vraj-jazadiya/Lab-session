public class p8 {
    public static void main(String[] args) {
        data d1= new data();
        d1.m2();
    }
}

class data {
    void m1() {
        System.out.println("calling m1 function");
    }

    void m2() {
        System.out.println("calling m2 function");
        this.m1();
    }
}
