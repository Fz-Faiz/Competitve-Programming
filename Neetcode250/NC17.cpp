#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        val = val;
        left = right = NULL;
    }
};


// There are three traveral techniques in DFS
// 1. In-order Traversal(L Root R)
// 2. Pre-order Traversal
// 3. Post-order Traversal



class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};


class Solution {
public:
    void traversal(TreeNode* root){
        if(root == NULL) return;
        traversal(root->left);
        traversal(root->right);
        swap(root->left, root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1+max(lh, rh);

    }
};


class Solution {
public: 
    int maxi = 0;
    int helper(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int lh = helper(root->left, maxi);
        int rh = helper(root->right, maxi);
        maxi = max(maxi, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root, maxi);
        return maxi;
    }
};