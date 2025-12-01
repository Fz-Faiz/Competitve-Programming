#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<int> getConcatenation(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(2*n);

//         for(int i = 0; i < n; ++i){
//             ans[i] = nums[i];
//             ans[i+n] = nums[i];
//         }
        
//         return ans;
//     }
// };

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         unordered_set<int> st;

//         for(int x : nums){
//             if(st.count(x)) return true;
//             st.insert(x);
//         }

//         return false;

        
        
//     }
// };

// class Solution {
// public:
//     bool isAnagram(string s, string t) {

//         int hsh[26] = {0};
//         if(s.size() != t.size()) return false;

        
//         for(char c : s) hsh[c-'a']++;
//         for(char c : t) hsh[c-'a']--;
        

//         for(int i = 0; i < 26; i++){
//             if(hsh[i] != 0) return false;
//         }
//         return true;

        
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;

//         for(int i = 0 ; i < nums.size(); ++i){
//             int rem = target - nums[i];

//             if(mp.count(rem)){
//                 return {mp[rem], i};
//             }

//             mp[nums[i]] = i;
//         }
//         return {};
//     }
// };
