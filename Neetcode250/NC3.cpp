#include<bits/stdc++.h>
using namespace std;

// Learn Heap, Merge, Quick sort implementaion

// Counting sort

// class Solution {
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         unordered_map<int,int> mp;

//         for(auto &num: nums){
//             mp[num]++;
//         }

//         int minE = *min_element(nums.begin(), nums.end());
//         int maxE = *max_element(nums.begin(), nums.end());

//         int i= 0;
//         for(int num = minE; num <= maxE; num++){

//             while(mp[num] > 0){
//                 nums[i] = num;
//                 i++;
//                 mp[num]--;
//             }
//         }
//         return nums;
//     }
// };

// Dutch National Flag Algorithm(Sorting)
// [0 ... low-1] -> 0
// [low ... mid-1] -> 1
// [mid ... high] -> 0/1/2
// [high+1 ... n-1] -> 2

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0, mid = 0, high = n-1;

//         while(mid <= high){
//             if(nums[mid] == 0){
//                 swap(nums[low], nums[mid]);
//                 low++, mid++;
//             }else if(nums[mid] == 1){
//                 mid++;
//             }else{
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }
//     }
// };


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();

//         unordered_map<int , int> mp;

//         for(auto &num: nums) mp[num]++;

//         vector<vector<int>> bucket(n+1);

//         for(auto &it: mp){
//             int element = it.first;
//             int freq = it.second;

//             bucket[freq].push_back(element);
//         }

//         vector<int> result;

//         for(int i = n ; i >=0 ; i--){
//             if(bucket[i].size() == 0) continue;

//             while(bucket[i].size() > 0 && k > 0){
//                 result.push_back(bucket[i].back());
//                 bucket[i].pop_back();
//                 k--;
//             }
//         }
//         return result;

//     }
// };



// class Solution {
// public:

//     string encode(vector<string>& strs) {
//         string result = "";
//         int n = strs.size();
//         for(int i = 0 ; i < n ; i++){
//             result += to_string(strs[i].size()) + "#" + strs[i];
//         }
//         return result;
//     }

//     vector<string> decode(string s) {
//         vector<string> result;
//         int i = 0;
//         while(i < s.size()){
//             int len = 0;
//             while(s[i] != '#'){
//                 len = len *10 + (s[i]-'0');
//                 i++;
//             }
//             i++;

//             result.push_back(s.substr(i,len));
//             i += len;
//         }
//         return result;
//     }
// };


// class NumMatrix {
// public:
//     vector<vector<int>> prefix;
//     NumMatrix(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         prefix.assign(n+1, vector<int>(m+1, 0));

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
//             }
//         }

//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1];
//     }
// };

// /**
//  * Your NumMatrix object will be instantiated and called as such:
//  * NumMatrix* obj = new NumMatrix(matrix);
//  * int param_1 = obj->sumRegion(row1,col1,row2,col2);
//  */