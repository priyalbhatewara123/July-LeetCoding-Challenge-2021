/*
Method 1:
Time Complexity - O(n)
Space Complexity - O(n)
*/

class Solution {
public:
	int partitionDisjoint(vector<int>& nums) {
		int n = nums.size();

		int leftMax[n];
		int rightMax[n];

		int lm = nums[0] , rm = nums[n - 1];

		for (int i = 0; i < n; i++) {
			lm = max(lm, nums[i]);
			leftMax[i] = lm;

			rm = min(rm, nums[n - 1 - i]);
			rightMax[n - 1 - i] = rm;
		}

		int ans = 1;
		for (int i = 0; i < n - 1; i++) {
			if (leftMax[i] <= rightMax[i + 1]) {
				ans = i + 1;
				break;
			}
		}
		return ans;
	}
};

/*
Method 2:
Time Complexity - O(n)
Space Complexity - O(1)
*/

int partitionDisjoint(vector<int>& nums) {
	int n = nums.size();
	int maxUntilI = nums[0];
	int maxInLeftPartition = nums[0];
	int partitionIdx = 0;

	for (int i = 1; i < n; i++) {
		maxUntilI = max(maxUntilI, nums[i]);

		if (nums[i] < maxInLeftPartition) {
			maxInLeftPartition = maxUntilI;
			partitionIdx = i;
		}
	}

	return partitionIdx + 1;
}