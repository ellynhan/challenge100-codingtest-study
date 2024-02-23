// https://school.programmers.co.kr/learn/courses/30/lessons/72410
class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase();
        new_id = new_id.replaceAll("[^a-z0-9\\-_.]", "");
        new_id = new_id.replaceAll("[.]{2,}", ".");
        new_id = new_id.replaceAll("^[.]|[.]$", "");
        if (new_id.length() == 0) new_id = new_id + "a";
        if (new_id.length() >= 16) {
            new_id = new_id.substring(0, 15);
            new_id = new_id.replaceAll("[.]$", "");
        }
        while (new_id.length() <= 2) new_id += new_id.charAt(new_id.length() - 1);
        return new_id;
    }
}
