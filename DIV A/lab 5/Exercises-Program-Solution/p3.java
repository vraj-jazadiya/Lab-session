public class p3 {
    int length;
    int width;

    void rect_data(int l, int w) {
        length = l;
        width = w;

    }

    void area() {
        System.out.println(length * width);
    }

    public static void main(String[] args) {

        p3 r1 = new p3();
        p3 r2 = new p3();

        r1.rect_data(11, 5);
        r2.rect_data(3, 15);

        r1.area();
        r2.area();
    }
}
