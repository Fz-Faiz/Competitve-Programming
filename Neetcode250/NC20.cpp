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


class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar){
        if(root == NULL) return 0;
        int count = 0;
        if(root->val >= maxSoFar){
            count = 1;
            maxSoFar = root->val;
        }

        int lh  = dfs(root->left, maxSoFar);
        int rh  = dfs(root->right, maxSoFar);

        return count + lh + rh;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return dfs(root, root->val);
    }
};


class Solution {
public:
    bool isValid(TreeNode* root, long long minVal, long long maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false; 
        return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};


class Solution {
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = build(preorder, 0, preorder.size() - 1, 
                                inorder, 0, inorder.size() - 1,
                                inMap);
        return root;
    }

    TreeNode* build(vector<int>&preorder, int preStart, int preEnd,
                    vector<int> &inorder, int inStart, int inEnd,
                    map<int,int> &inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder , inStart, inRoot- 1, inMap);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1,inEnd, inMap); 

        return root;

    }
}; 



class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob = root->val + left.second + right.second;

        int notrob = max(left.first , left.second) + max(right.second, right.first);

        return {rob, notrob};
    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};


class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if(root->val == target && root->left == NULL && root->right == NULL){
            return NULL;
        }
        return root;
    }
};