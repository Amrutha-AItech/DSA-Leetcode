class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // rob = take current node
        int rob = root->val + left.second + right.second;

        // skip = don't take current node
        int skip = max(left.first, left.second)
                 + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};