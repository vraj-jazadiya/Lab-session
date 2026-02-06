public class p7 {

    public static void main(String[] args) {

        int x = 1, y = 2, z;
        char c = 'a';   // a = addition, d = division, m = multiplication, s = subtraction

        switch (c) {

            case 'a':
                z = x + y;
                System.out.println("Addition = " + z);
                break;

            case 'd':
                z = x / y;
                System.out.println("Division = " + z);
                break;

            case 'm':
                z = x * y;
                System.out.println("Multiplication = " + z);
                break;

            case 's':
                z = x - y;
                System.out.println("Subtraction = " + z);
                break;

            default:
                System.out.println("Not a valid input");
        }
    }
}
