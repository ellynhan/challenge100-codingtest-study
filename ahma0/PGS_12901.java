
import java.time.DayOfWeek;
import java.time.LocalDate;

public class Solution {

    static String arr[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    public String solution(int a, int b) {
        LocalDate localDate = LocalDate.of(2016, a, b);
        DayOfWeek dayOfWeek = localDate.getDayOfWeek();

        return arr[dayOfWeek.getValue() - 1];
    }

}