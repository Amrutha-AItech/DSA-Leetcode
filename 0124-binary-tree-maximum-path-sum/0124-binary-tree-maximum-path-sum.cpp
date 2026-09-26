class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Path passing through current node
        ans = max(ans, root->val + left + right);

        // Return the best one-sided path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};