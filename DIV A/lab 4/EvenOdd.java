import java.util.Scanner;

public class EvenOdd {
    
    public static void checkEvenOdd(int num) {
        if (num % 2 == 0) {
            System.out.println(num + " is an EVEN num.");
        } else {
            System.out.println(num + " is an ODD num.");
        }
    }
    
    public static String getEvenOddStatus(int num) {
        return (num % 2 == 0) ? "EVEN" : "ODD";
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("===== Even or Odd num Checker =====\n");
        System.out.print("Enter a num: ");
        
        int input_num = scanner.nextInt();
        
        System.out.println("\nResult:");
        checkEvenOdd(input_num);
        
        System.out.println("Status: " + getEvenOddStatus(input_num));
        
        System.out.println("\n===== Additional Examples =====");
        checkEvenOdd(5);
        checkEvenOdd(10);
        checkEvenOdd(23);
        checkEvenOdd(100);
        
        scanner.close();
    }
}
