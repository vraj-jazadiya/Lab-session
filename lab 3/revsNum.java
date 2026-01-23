public class revsNum {

    static void reverse(int n) {
        int rev = 0;

        while (n != 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }

        System.out.println("Reverse: " + rev);
    }

    public static void main(String[] args) {
        reverse(1234);
    }
}
