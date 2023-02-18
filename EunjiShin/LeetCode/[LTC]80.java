package LeetCode;

class Solution {
	public int removeDuplicates(int[] nums) {
		int size = nums.length - 1;
		int index = 2;
		for (int i = 2; i <= size; i++) {
			if (nums[i] != nums[index - 2]) {
				nums[index] = nums[i];
				index++;
			}
		}

		return index;
	}
}