class Solution {
public:
    int dfs(TreeNode* root, int maxValue) {
        if (!root)
            return 0;

        int good = 0;

        if (root->val >= maxValue) {
            good = 1;
            maxValue = root->val;
        }

        good += dfs(root->left, maxValue);
        good += dfs(root->right, maxValue);

        return good;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};