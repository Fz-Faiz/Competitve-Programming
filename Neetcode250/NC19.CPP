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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right  = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }

        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightchild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightchild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }

};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i){
                TreeNode* node = q.front(); q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> ans;
    void recursion(TreeNode* root, int level){
        if(root == NULL) return;

        if(ans.size() == level) ans.push_back(root->val);
        recursion(root->right,level+1);
        recursion(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        recursion(root, 0);
        return ans;
    }
};


class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];
        
        for(int i = x; i < x + n; i++) {
            for(int j = y; j< y + n; j++) {
                if(grid[i][j] != val)
                    return false;
            }
        }
        
        return true;
    }
    
    Node* solve(vector<vector<int>> &grid, int x, int y, int n) {
        if(isAllSame(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        } else {
            Node* root = new Node(1, false);
            
            root->topLeft = solve(grid, x, y, n/2);
            root->topRight = solve(grid, x, y+n/2, n/2);
            root->bottomLeft = solve(grid, x+n/2, y, n/2);
            root->bottomRight = solve(grid, x+n/2, y+n/2, n/2);
            
            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};