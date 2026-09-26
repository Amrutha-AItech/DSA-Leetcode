class Solution {
public:
    unordered_map<int, int> inIndex;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {
        if (left > right)
            return nullptr;

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int mid = inIndex[rootValue];

        // Build right first because we're moving backwards
        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inIndex[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};