public class traverselOfMtx {


    public static void main(String[] args) {
        int[][] mtx = new int[2][2];

        mtx[0][0] = 1;
        mtx[0][1] = 2;
        mtx[1][0] = 3;
        mtx[1][1] = 4;

        for (int i = 0; i < mtx.length; i++) {
            for (int j = 0; j < mtx[i].length; j++) {
                System.out.print(mtx[i][j] + " ");
            }
            System.out.println();
        }
    }

}
