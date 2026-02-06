public class swapNum {
    
    public static void swapnums(int num1, int num2) {
        System.out.println("before swapping:");
        System.out.println("1st num: " + num1);
        System.out.println("2nd num: " + num2);
        
        int temp;
        
        temp = num1;      
        num1 = num2;      
        num2 = temp;      
        
        System.out.println("\nafter swapping:");
        System.out.println("1st num: " + num1);
        System.out.println("2nd num: " + num2);
    }
    
    public static void swapnums(double num1, double num2) {
        System.out.println("\nbefore swapping (Double):");
        System.out.println("1st num: " + num1);
        System.out.println("2nd num: " + num2);
        
        double temp;
        
        temp = num1;
        num1 = num2;
        num2 = temp;
        
        System.out.println("\nafter swapping (Double):");
        System.out.println("1st num: " + num1);
        System.out.println("2nd num: " + num2);
    }
    
    public static void main(String[] args) {
        System.out.println("===== swapping nums Using Third Variable =====\n");
        
        System.out.println("--- swapping Integers ---");
        swapnums(10, 20);
        
        System.out.println("\n--- swapping Doubles ---");
        swapnums(15.5, 25.3);
        
        System.out.println("\n--- Another Example with Integers ---");
        swapnums(100, 200);
    }
}
