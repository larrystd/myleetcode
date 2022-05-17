#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return vector<int>{};
        stack<TreeNode*> treestack;
        TreeNode* p = root;
        treestack.push(p);
        vector<int> result;
        result.push_back(p->val);

        while (!treestack.empty()) {
            while (p->left) {
                p = p->left;
                treestack.push(p);

            }
            TreeNode *q = treestack.top();
            result.push_back(p->val);
            treestack.pop();
            if (q->right) {
                p = q->right;
                treestack.push(p);
            }
        }

        return result;
    }
};