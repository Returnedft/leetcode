#include <iostream>
#include <math.h>

// Binary Tilt # EASY

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
    int findTilt(TreeNode* root) {
        if (root == nullptr) return 0;
        return abs(getSumTreeNode(root->left) - getSumTreeNode(root->right)) + findTilt(root->left) + findTilt(root->right);
    }

    int getSumTreeNode(TreeNode* root){
        if (root == nullptr) return 0;
        return root->val + getSumTreeNode(root->left) + getSumTreeNode(root->right);
    }
};


int main(){
    Solution sol;
    TreeNode* root = new TreeNode(21);
    root->left = new TreeNode(7);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(3);
    std::cout << sol.findTilt(root) << std::endl;
    return 0;
}