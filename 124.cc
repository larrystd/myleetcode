#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxSum = INT32_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

class Solution {
private:
    const int maxSum = INT32_MIN;

public:  
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftGain = max(maxGain(node->left), 0); // 左子树贡献
        int rightGain = max(maxGain(node->right), 0);   // 右子树贡献

        int priceNewpath = node->val + leftGain + rightGain;  // 以node为根节点路径最大贡献

        maxSum = max(maxSum, priceNewpath);

        return node->val + max(leftGain, rightGain);  // 节点能给父节点的贡献
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};