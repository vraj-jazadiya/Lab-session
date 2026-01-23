public class threeDArray {

    public static void main(String[] args) {

        int[][][] mtx3d = {
                { { 1, 2 }, { 3, 4 } },
                { { 5, 6 }, { 7, 8 } }
        };

        System.out.println("3D Matrix is:");

        for (int i = 0; i < mtx3d.length; i++) {
            System.out.println("Layer " + (i + 1) + ":");
            for (int j = 0; j < mtx3d[i].length; j++) {
                for (int k = 0; k < mtx3d[i][j].length; k++) {
                    System.out.print(mtx3d[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}