// https://school.programmers.co.kr/learn/courses/30/lessons/64064/solution_groups?language=java
import java.util.Stack;
import java.util.Set;
import java.util.HashSet;

class Solution {
    private static Set<Set<String>> possibleCases = new HashSet<> ();

    private Stack<String> getFilters(String[] banned_id) {
        Stack<String> filters = new Stack<> ();
        for (int i = 0; i < banned_id.length; i++) {
            filters.push(banned_id[i].replace("*", "."));
        }
        return filters;
    }

    private void getPossibleCases(Set<String> idList, String[] user_id, Stack<String> filters, int length) {
        if (filters.isEmpty()) {
            if (idList.size() == length) possibleCases.add(new HashSet<>(idList));
            return;
        }

        String filter = filters.peek();
        for (String id : user_id) {
            if (idList.contains(id)) continue;
            if (id.matches(filter)) {
                idList.add(id);
                filters.pop();

                getPossibleCases(idList, user_id, filters, length);

                idList.remove(id);
                filters.push(filter);
            }
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        Set<String> idList = new HashSet<> ();
        Stack<String> filters = getFilters(banned_id);
        getPossibleCases(idList, user_id, filters, filters.size());
        return possibleCases.size();
    }
}
