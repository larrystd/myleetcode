#include <list>
#include <iostream>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        list<TreeNode* > treestack;

        treestack.push_back(root);
        TreeNode* node = root;

        while(!treestack.empty()) {
            while(node) {
                treestack.push_back(node);
                node = node->left;
                
            }
            TreeNode* cur = treestack.back();
            treestack.pop_back();

            if (cur->right) {
                node = cur->right;
            }

            if (cur == p) {
                treestack.pop_back();
                return treestack.size() == 0 ? nullptr : treestack.back();
            }
        }

        return nullptr;
    }
};