public class primeCheckflag {

    static void checkPrime(int n) {
        boolean flag = true;

        if (n <= 1)
            flag = false;

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            System.out.println("Prime Number");
        else
            System.out.println("Not Prime Number");
    }

    public static void main(String[] args) {
        checkPrime(7);
    }
}
