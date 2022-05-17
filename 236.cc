struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p||root==q) {
            return root;
        }
        if (root!=nullptr){
            TreeNode* lNode=lowestCommonAncestor(root->left,p,q);
            TreeNode* rNode=lowestCommonAncestor(root->right,p,q);
            if (lNode!=nullptr&&rNode!=nullptr) // root即为所求
                return root;
            else if(lNode==nullptr) {//两个都在右子树
                return rNode;
            }
            else { //两个都在左子树里面
                return lNode;
            }
        }
        return nullptr;
    }
};