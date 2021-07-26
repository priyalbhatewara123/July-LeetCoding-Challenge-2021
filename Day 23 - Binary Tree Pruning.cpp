class Solution {
    bool hasOne(TreeNode* root) {

        //base case
        if (root == NULL)
            return false;

        bool has1left = hasOne(root->left);
        bool has1right = hasOne(root->right);

        if (!has1left)
            root->left = NULL;

        if (!has1right)
            root->right = NULL;

        return has1left || has1right || root->val == 1;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        return hasOne(root) ? root : NULL;
    }
};