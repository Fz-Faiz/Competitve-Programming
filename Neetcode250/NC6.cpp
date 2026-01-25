#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         string temp  = "";

//         int i = 0, j = 0;
//         while(i<n || j<m){
//             if(i<n)temp += word1[i++];
//             if(j<m)temp += word2[j++];
//         }
//         return temp;
//     }
// };

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        

//         int k = m + n - 1;
//         int i = m-1, j = n-1;
//         while(i >= 0 && j >= 0){
//             if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
//             else nums1[k--] = nums2[j--];
//         }

//         while(j>=0) nums1[k--] = nums2[j--];
//     }
// };

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();

//         int i = 0, j = i+1;
//         int k = 0;

//         while(j < n){
//             if(nums[i] != nums[j]){
//                 nums[++i] = nums[j];
//                 k++;
//             }
//             j++;
//         }
//         return k+1;
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n = numbers.size();
//         int i = 0 , j = n-1;

//         while( i < j ){
//             if(numbers[i] + numbers[j] == target) return {i+1,j+1};
//             else if(numbers[i] + numbers[j] > target) j--;
//             else i++;
//         }

//         return {i+1, j+1};
//     }
// };