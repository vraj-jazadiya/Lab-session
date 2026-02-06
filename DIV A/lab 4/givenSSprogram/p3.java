public class p3 {
    public enum Direction {
        NORTH, SOUTH, EAST, WEST
    }

    public static void main(String[] args) {
        for(Direction dir : Direction.values()) {
            System.out.println(dir);
        }

        Direction dir_value = Direction.valueOf("SOUTH");
        System.out.println("Direction: " + dir_value);

        System.out.println("Ordinal of South: " + dir_value.ordinal());
    }
}
