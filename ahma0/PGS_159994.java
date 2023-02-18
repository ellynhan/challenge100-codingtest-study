import java.io.IOException;

public class Solution {

    public static String solution (String[] cards1, String[] cards2, String[] goal) {
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < goal.length; i++) {

            if(cards1[cnt1].equals(goal[i]))
                cnt1 = (cnt1 < cards1.length - 1)? cnt1 + 1: cnt1;
            else if(cards2[cnt2].equals(goal[i]))
                cnt2 = (cnt2 < cards2.length - 1)? cnt2 + 1: cnt2;
            else return "No";

        }

        return "Yes";
    }
}