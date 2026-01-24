#include<bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> result(n);

//         result[0] = 1;
//         for(int i = 1; i < n;i++){
//             result[i] = result[i-1] * nums[i-1];
//         }
//         int right_product = 1;
//         for(int i = n-1; i >= 0 ;i--){
        
//             result[i] = right_product *  result[i];
//             right_product *= nums[i];
//         }
//         return result;
//     }
// };

// smart

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_set<string> st;

//         for(int i = 0; i < 9; i++){
//             for(int j = 0; j < 9; j++){
//                 if(board[i][j] == '.') continue;

//                 string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
//                 string col = string(1, board[i][j]) + "_COL_" + to_string(j);
//                 string box = string(1, board[i][j]) + "_BOX_" 
//                              + to_string(i/3) + "_" + to_string(j/3);

//                 if(st.count(row) || st.count(col) || st.count(box))
//                     return false;

//                 st.insert(row);
//                 st.insert(col);
//                 st.insert(box);
//             }
//         }
//         return true;   // ✅ correct place
//     }
// };


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int profit = 0;

//         for(int i = 0 ; i < n-1; ++i){
//             if(prices[i] < prices[i+1]){
//                 profit += prices[i+1]-prices[i];
//             }
//         }
//         return profit;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         int cnt = 0;
//         unordered_map<int,int> mp;
//         mp[0] = 1;
//         int sum = 0;
//         for(int i = 0; i < n; ++i){
//             sum += nums[i];
//             int rem = sum - k;
//             cnt += mp[rem];
//             mp[sum] += 1;
//         }
//         return cnt;
        
//     }
// };

// Hard Question


// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         bool contains1 = false;
//         for(int i = 0; i < n; ++i){
//             if(nums[i] == 1) contains1 = true;
//             if(nums[i] <= 0 || nums[i]  > n) nums[i] = 1;
//         }
//         if(contains1 == false) return 1;
//         for(int i = 0 ; i< n ; ++i){
//             int num = abs(nums[i]);
//             int idx = num -1;
//             if(nums[idx] < 0) continue;
//             nums[idx] *= -1;
//         }
//         for(int i = 0 ;i<n;++i){
//             if(nums[i] > 0) return i+1;
//         }
//         return n+1;
//     }
// };