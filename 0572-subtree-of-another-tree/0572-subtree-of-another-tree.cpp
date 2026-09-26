class Solution {
public:
    bool sameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;

        if (!a || !b || a->val != b->val)
            return false;

        return sameTree(a->left, b->left) &&
               sameTree(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;

        if (!root)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};