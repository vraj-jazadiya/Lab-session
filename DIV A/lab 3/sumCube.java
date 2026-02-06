public class sumCube {

    static void calculate(int n) {
        int sum = n + n;
        int cube = n * n * n;

        System.out.println("Sum: " + sum);
        System.out.println("Cube: " + cube);
    }

    public static void main(String[] args) {
        calculate(5);
    }
}
