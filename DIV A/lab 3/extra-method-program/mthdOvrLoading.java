public class mthdOvrLoading {

    static int add(int x, int y) {

        return x + y;
    }

    static float add(float x, float y) {
        return x + y;
    }

    public static void main(String[] args) {
        int a = 10;
        float b = 20.9f;
        System.out.println(add(a, b));
    }
}
