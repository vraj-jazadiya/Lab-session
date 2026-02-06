public class Emp {
    enum Gender {
        MALE,
        FEMALE
    }

    public static void main(String[] args) {
        
            int eid = 107;
            String name = "krish";

        System.out.println("eid = " + eid);
        System.out.println("ename = " + name);

            Gender gender_select=Gender.MALE;
            System.out.println("Gender = " + gender_select);

    }
}