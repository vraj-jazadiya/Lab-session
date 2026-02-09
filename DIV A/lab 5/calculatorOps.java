class Calculator {
    double num1;
    double num2;

    double add() {
        return num1 + num2;
    }

    double subtract() {
        return num1 - num2;
    }
}

class advanceCalc extends Calculator {
    double multi() {
        return num1 * num2;
    }

    double div() {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            System.out.println("Cannot divide by zero");
            return 0; // or throw an exception
        }
    }
}

public class calculatorOps {

    public static void main(String[] args) {
        System.out.println("Code started");
        Calculator calc = new Calculator();
        calc.num1 = 10;
        calc.num2 = 5;
        System.out.println("Addition: " + calc.add());
        System.out.println("Subtraction: " + calc.subtract());
        advanceCalc advCalc = new advanceCalc();
        advCalc.num1 = 10;
        advCalc.num2 = 5;
        System.out.println("Multiplication: " + advCalc.multi());
        System.out.println("Division: " + advCalc.div());
    }

}