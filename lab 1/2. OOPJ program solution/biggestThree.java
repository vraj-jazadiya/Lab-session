import java.util.Scanner;

public class biggestThree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        if (a > b && a > c) {
            System.out.println("Biggest is " + a);
        } else if (b > c) {
            System.out.println("Biggest is " + b);
        } else {
            System.out.println("Biggest is " + c);
        }
    }
}