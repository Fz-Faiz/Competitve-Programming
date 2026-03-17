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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    int maxPathDown(TreeNode* root, int maxi){
        if(root == NULL) return 0;

        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, root->val+left+right);

        return root->val + max(left, right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";    

        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL) s.append("#,");
            else s.append(to_string(temp->val)+',');

            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* newnode = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(newnode);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(ss, str, ',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                node->left = leftnode;
                q.push(leftnode);
            }

            getline(ss, str, ',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                node->right = rightnode;
                q.push(rightnode);
            }
        }

        return newnode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));