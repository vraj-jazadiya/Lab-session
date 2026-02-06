public class mtxThreeD {
    public static void main(String[] args) {
        int[][] mtx3d = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        System.out.println("3D Matrix is:");

        for (int i = 0; i < mtx3d.length; i++) {
            for (int j = 0; j < mtx3d[i].length; j++) {
                System.out.print(mtx3d[i][j] + " ");
            }
            System.out.println();
        }
    }
}
