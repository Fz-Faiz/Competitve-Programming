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
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfs(root->left);
        if(lh == -1) return -1;
        int rh = dfs(root->right);
        if(rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1+max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p == NULL || q == NULL) return (p == q);

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


class Solution {
public:
    string preorder(TreeNode* root){
        if(root == NULL) return "#";

        return "," + to_string(root->val) + preorder(root->left) + preorder(root->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string fullTree = preorder(root);
        string subTree = preorder(subRoot);

        
        if(fullTree.find(subTree) != string::npos){
            return true;
        }else return false;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(true){
            if(curr->val <= val){
                if(curr->right != NULL) curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left != NULL) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};