enum DaysOfWeek {
    MONDAY("Monday"),
    TUESDAY("Tuesday"),
    WEDNESDAY("Wednesday"),
    THURSDAY("Thursday"),
    FRIDAY("Friday"),
    SATURDAY("Saturday"),
    SUNDAY("Sunday");

    private final String dayName;

    DaysOfWeek(String dayName) {
        this.dayName = dayName;
    }

    public String getDayName() {
        return dayName;
    }
}

public class dayOfWeek {
    public static void main(String[] args) {
        System.out.println("Days of the Week:");
        for (DaysOfWeek day : DaysOfWeek.values()) {
            System.out.println(day.ordinal() + 1 + ". " + day.getDayName() + " (" + day.name() + ")");
        }

        System.out.println("\nSpecific Days:");
        System.out.println("First day: " + DaysOfWeek.MONDAY.getDayName());
        System.out.println("Last day: " + DaysOfWeek.SUNDAY.getDayName());

        DaysOfWeek today = DaysOfWeek.FRIDAY;
        System.out.println("\nToday is: " + today.getDayName());
    }
}
