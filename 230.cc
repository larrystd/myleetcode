#include <iostream>
#include <stack>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> treestack;
        treestack.push(root);
        TreeNode* p = root;
        int result;
        while (!treestack.empty()) {
            while (p->left) {
                p = p->left;
                treestack.push(p);
            }
            TreeNode *node = treestack.top();
            k--;
            if (k == 0)
                return node->val;
            treestack.pop();
            if (node->right) {
                treestack.push(node->right);
                p = node->right;
            }
        }

        return 0;
    }
};