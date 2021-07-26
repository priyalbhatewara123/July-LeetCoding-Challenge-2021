/*
Solution 1 : Checking consecutive bits of every number.
This leads to TLE because of high constraints(10^9).

Time Complexity : O(32*n)
Space Complexity : O(1)
*/

class Solution {
	bool consecutiveOnes(int n) {
		int i = 31; //32 bit integer
		while (i > 0) {
			if ((n >> i & 1) & (n >> (i - 1) & 1))
				return true;

			i--;
		}
		return false;
	}

public:
	int findIntegers(int n) {
		int count = 1; //include 0
		for (int i = 1; i <= n; i++) {
			if (!consecutiveOnes(i))
				count++;
		}
		return count;
	}
};

/*
Solution 2:
Time Complexity - O(x) //x are the total numbers <=n that doesnot contains consecutive 1's
Space Complexity - O(32) //max we go upto 32 bits
*/

class Solution {
	int count(int i, int sum , int n , bool prev) {
		if (sum > n)
			return 0;

		if (1 << i > n)
			return 1;

		if (prev)
			return count(i + 1, sum, n, false);

		return count(i + 1, sum, n, false) + count(i + 1, sum + (1 << i) , n, true);
	}

public:
	int findIntegers(int n) {
		return count(0, 0, n, false);
	}
};

/*
Solution 3 :
https://www.youtube.com/watch?v=4OL7WdGKC1Y&ab_channel=CodingDecoded
https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/discuss/103754/C%2B%2B-Non-DP-O(32)-Fibonacci-solution
(Do again)
*/

class Solution {
public:
	int findIntegers(int num) {
		int f[32];
		f[0] = 1;
		f[1] = 2;
		for (int i = 2; i < 32; ++i)
			f[i] = f[i - 1] + f[i - 2];
		int ans = 0, k = 31, pre_bit = 0;
		while (k >= 0) {
			if (num & (1 << k)) {
				ans += f[k];
				if (pre_bit) return ans;
				pre_bit = 1;
			}
			else
				pre_bit = 0;
			--k;
		}
		return ans + 1;
	}
};