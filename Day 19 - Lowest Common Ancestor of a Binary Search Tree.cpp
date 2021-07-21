/*
Solution 1 : Recursive approach
Time Complexity - O(n)
Space Complexity - O(n) //recursion call stack
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root -> val;
        int pVal = p -> val;
        int qVal = q -> val;

        if (pVal < rootVal and qVal < rootVal)
            return lowestCommonAncestor(root->left, p, q);

        else if (pVal > rootVal and qVal > rootVal)
            return lowestCommonAncestor(root->right, p, q);

        else
            return root;
    }
};

/*
Solution 2 : Iterative Approach
Time Complexity - O(n)
Space Complexity - O(1)
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p -> val;
        int qVal = q -> val;

        while (root != NULL) {
            int rootVal = root -> val;
            if (pVal < rootVal and qVal < rootVal)
                root = root ->left;

            else if (pVal > rootVal and qVal > rootVal)
                root = root -> right;

            else
                return root;
        }
        return NULL;
    }
};