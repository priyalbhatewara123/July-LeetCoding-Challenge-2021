/*
Solution 1 : Recursion
Time Complexity = O(log(n))
Space Complexity = O(log(n)) due to recursion call stack
*/

class Solution {
	int search(vector<int>& nums , int l , int r) {
		if (l == r)
			return l;
		int mid = (l + r) / 2;
		if (nums[mid] > nums[mid + 1])
			return search(nums, l, mid);
		else
			return search(nums, mid + 1, r);
	}

public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		return search(nums, 0, n - 1);
	}
};

/*
Solution 2 : Iterative approach
Time Complexity = O(log(n))
Space Complexity = O(1)
*/

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;

		while (l < r) {
			int mid = (l + r) / 2;
			if (nums[mid] > nums[mid + 1])
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};