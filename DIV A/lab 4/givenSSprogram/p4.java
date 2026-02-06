class p4 {

    enum Enums {
        X, Y, Z;

        {
            System.out.println(1);
        }

        static {
            System.out.println(2);
        }

        private Enums() {
            System.out.println(3);
        }
    }

    public static void main(String[] args) {
        Enums en = Enums.Y;
        System.out.println(en);
    }
}
