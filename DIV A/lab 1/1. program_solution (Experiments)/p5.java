public class p5 {

    public static void main(String args[]) {

        System.out.println();
        System.out.println("FOR LOOP");

        for (int a = 1; a <= 5; a++) {
            System.out.println("value of a=" + a);
            System.out.println("");
        }

        System.out.println("WHILE LOOP");
        int i = 1;
        while (i <= 5) {
            System.out.println("args=" + i);
            System.out.println("");
            i++;
        }

        System.out.println("DO .. WHILE LOOP");
        int j = 1;
        do {
            System.out.println("args=" + j);
            System.out.println("");
            j++;
        } while (j <= 5);

    }
}
