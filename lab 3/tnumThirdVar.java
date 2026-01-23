public class tnumThirdVar {

    static void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;

        System.out.println("After Swap:");
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }

    public static void main(String[] args) {
        swap(10, 20);
    }
}
