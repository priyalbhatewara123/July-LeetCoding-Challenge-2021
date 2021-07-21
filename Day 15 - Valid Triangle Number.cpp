/*
Solution 1 : Using Binary Search
Time Complexity : O(n2logn)
Space complexity : O(logn). Sorting takes O(logn) space.
*/

class Solution {
public:

    int binarySearch(vector<int>& nums , int l , int r, int x) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1 and nums[i] != 0; j++) {
                int x = nums[i] + nums[j];
                k = binarySearch(nums, k, n - 1, x);

                count += (k - 1 - j);
            }
        }
        return count;
    }
};


/*
Solution 2 : Linear Search
Time Complexity : O(n2)
Space Complexity : O(logn)
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int k = i + 2;
            for (int j = i + 1 ; j < n - 1 and nums[i] != 0 ; j++) {
                int x = nums[i] + nums[j];

                //Linear Scan to kind k
                while (k < n and nums[k] < x)
                    k++;

                count += (k - 1 - j);
            }
        }
        return count;
    }
};

//Solution - 3 (much faster)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = n - 1; i >= 2; i--) {
            int lo = 0, hi = i - 1;

            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[i]) {
                    res += hi - lo;
                    hi--;
                }

                else lo++;
            }
        }

        return res;
    }
};