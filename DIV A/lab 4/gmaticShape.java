enum Shape {
    CIRCLE("Circle", 0),
    SQUARE("Square", 4),
    RECTANGLE("Rectangle", 4),
    TRIANGLE("Triangle", 3),
    PENTAGON("Pentagon", 5),
    HEXAGON("Hexagon", 6),
    OCTAGON("Octagon", 8);

    private final String shapeName;
    private final int sides;

    Shape(String shapeName, int sides) {
        this.shapeName = shapeName;
        this.sides = sides;
    }

    public String getShapeName() {
        return shapeName;
    }

    public int getSides() {
        return sides;
    }

    public String describe() {
        if (sides == 0) {
            return shapeName + " is a curved shape with no sides.";
        } else {
            return shapeName + " is a polygon with " + sides + " sides.";
        }
    }
}

public class gmaticShape {
    public static void main(String[] args) {
        System.out.println("=== Geometric Shapes ===\n");
        for (Shape shape : Shape.values()) {
            System.out.println(shape.describe());
        }

        System.out.println("\n=== Specific Shapes ===");
        System.out.println("Shape: " + Shape.TRIANGLE.getShapeName() + 
                          ", Sides: " + Shape.TRIANGLE.getSides());
        System.out.println("Shape: " + Shape.HEXAGON.getShapeName() + 
                          ", Sides: " + Shape.HEXAGON.getSides());

        Shape myShape = Shape.SQUARE;
        System.out.println("\nMy shape is: " + myShape.describe());
    }
}
