package LeetCode;
class Solution {
	public int lengthOfLastWord(String s) {
		String[] splits = s.split(" ");
		int lastIndex = splits.length - 1;
		return splits[lastIndex].length();
	}
}