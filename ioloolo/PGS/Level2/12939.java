import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(String s) {
        IntSummaryStatistics statics = Stream.of(s.split("\\s+"))
                .map(Integer::parseInt)
                .mapToInt(x->x)
                .summaryStatistics();

        return String.format("%d %d", statics.getMin(), statics.getMax());
    }
}