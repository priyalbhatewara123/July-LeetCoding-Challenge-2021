class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int diff = INT_MAX, n = nums.size() , sum = 0;
        for (int i = 0; i < n - 2 && diff != 0; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];

                if (abs(target - (s)) < diff) {
                    sum = s;
                    diff = abs(target - (s));
                }

                if (s < target) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }
        return sum;
    }
};