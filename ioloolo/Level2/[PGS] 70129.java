class Solution {
    public int[] solution(String s) {
        int cnt1 = 0;
        int cnt2 = 0;

        while (!s.equals("1")) {
            cnt1++;
            cnt2 += countZero(s);

            s = Integer.toBinaryString(s.replaceAll("0", "").length());
        }

        return new int[] {cnt1, cnt2};
    }

    public int countZero(String str) {
        int cnt = 0;

        for (char c : str.toCharArray()) {
            if (c == '0') {
                cnt++;
            }
        }

        return cnt;
    }
}