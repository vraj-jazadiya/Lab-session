
import java.util.Scanner;

class Qtwo_mtx_multi {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter r of first matrix: ");
        int r1 = sc.nextInt();
        System.out.print("Enter c of first matrix: ");
        int c1 = sc.nextInt();

        System.out.print("Enter r of second matrix: ");
        int r2 = sc.nextInt();
        System.out.print("Enter c of second matrix: ");
        int c2 = sc.nextInt();

        if (c1 != r2) {
            System.out.println("Matrix multi not possible");
            return;
        }

        int[][] a = new int[r1][c1];
        int[][] b = new int[r2][c2];
        int[][] mul = new int[r1][c2];

        System.out.println("Enter x of 1st matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        System.out.println("Enter x of 2nd matrix:");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                b[i][j] = sc.nextInt();
            }
        }

        // multi
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    mul[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        System.out.println("multi Matrix:");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                System.out.print(mul[i][j] + " ");
            }
            System.out.println();
        }
    }
}
