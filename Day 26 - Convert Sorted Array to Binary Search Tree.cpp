class Solution {
    TreeNode* constructBST(vector<int>& nums , int start , int end) {

        //base case
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = constructBST(nums, start, mid - 1);
        root -> right = constructBST(nums, mid + 1, end);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        TreeNode* root = constructBST(nums, start, end);
        return root;
    }
};