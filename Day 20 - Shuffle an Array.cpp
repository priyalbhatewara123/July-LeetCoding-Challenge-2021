/*
Using Fisher-Yates shuffle Algorithm
https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
*/

class Solution {
	vector<int> original;
public:
	Solution(vector<int>& nums) {
		for (int n : nums)
			original.push_back(n);
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> random = original;
		int n = random.size();
		for (int i = n - 1; i >= 0; i--) {
			int j = rand() % (i + 1);

			swap(random[i], random[j]);
		}

		return random;
	}
};