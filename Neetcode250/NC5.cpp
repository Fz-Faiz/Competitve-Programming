#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int n = s.size();

//         for(int i = 0; i < n /2; ++i){
//             swap(s[i], s[n-i-1]);
//         }
//     }
// };

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int n = s.size();
//         string temp = "";
//         for(int i = 0; i < n; ++i){
//             if(isupper(s[i])) temp += tolower(s[i]);
//             else if(isalnum(s[i])) temp += s[i];
//             else if(s[i] == ' ') continue;
//         }
//         string temp2 = temp;
//         reverse(temp2.begin(), temp2.end());

//         return temp == temp2;
//     }
// };

// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int n = s.size();
//         int left = 0, right = n-1;

//         while(left < right){
//             if(s[left] == s[right]){
//                 left++;
//                 right--;
//             }else{
//                 return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
//             }
//         }
//         return true;
//     }
//     bool isPalindrome(string &s, int left ,int right){
//         while(left<right){
//             if(s[left] == s[right]){
//                 left++;
//                 right--;
//             }else return false;
//         }
//         return true;
//     }
// };