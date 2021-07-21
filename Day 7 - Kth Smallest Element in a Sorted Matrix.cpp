class Solution {

    //func to find number of elements less than or equal to mid
    int count(vector<vector<int>>& matrix , int mid , int n) {
        int i = n - 1;  //starting from bottom left corner
        int j = 0;
        int ans = 0;

        while (i >= 0 and j < n) {
            if (matrix[i][j] > mid)
                i--;
            else {
                ans += (i + 1);
                j++;
            }

        }
        return ans;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int num = count(matrix, mid, n);

            if (num < k)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};


/*
Video : https://www.youtube.com/watch?v=G5wLN4UweAM&ab_channel=alGOds
*/