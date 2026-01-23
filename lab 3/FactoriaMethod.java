public class FactoriaMethod {

    static void factorial(int n) {
        long fact = 1;
        for (int i = 1; i <= n; i++)
            fact *= i;

        System.out.println("Factorial: " + fact);
    }

    public static void main(String[] args) {
        factorial(5);
    }
}
