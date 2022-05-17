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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result = dfs(1, n);
        

        return result;
    }

    vector<TreeNode*> dfs(int left, int right) {
        if (left > right) 
            return {nullptr};
        
        vector<TreeNode*> allTrees;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftTrees = dfs(left, i-1);
            vector<TreeNode*> rightTrees = dfs(i+1, right);
            for (auto& left : leftTrees) {
                for (auto& right : rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }

        return allTrees;
    }
};