// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         int n = nums.size();

//         unordered_map<int,int> mp;

//         for(int i = 0; i < n; ++i){
//             if(mp.find(nums[i]) != mp.end()){
//                 int idx = abs(i-mp[nums[i]]);
//                 if(idx<=k) return true;
//             }
//             mp[nums[i]] = i;
//         }
//         return false;

//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int maxProfit = 0;
//         int mini = prices[0];
//         for(int i = 1; i < n; ++i){
//             if(mini < prices[i]){
//                 int profit = prices[i] - mini;
//                 maxProfit = max(maxProfit, profit);
//             }
//             mini = min(mini, prices[i]);
//         }
//         return maxProfit;
//     }
// };

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int hsh[256];
//         fill(hsh, hsh+256, -1);
//         if(n == 0) return 0;

//         int l = 0, r = 0;
//         int maxLen = 1;
//         while( r < n ){
//             if(hsh[s[r]] != -1 && hsh[s[r]] >= l){
//                 l = hsh[s[r]] + 1;
//             }
//             int len = r-l+1;
//             maxLen = max(maxLen ,len);
//             hsh[s[r]] = r;
//             r++;
//         }
//         return maxLen;
//     }
// };

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();

//         int l = 0, r = 0;

//         int maxlen = 0, maxfreq = 0;

//         int hsh[26];

//         while(r < n){
//             hsh[s[r] - 'A']++;
//             maxfreq = max(maxfreq, hsh[s[r] - 'A']);

//             while((r-l+1) - maxfreq > k){
//                 hsh[s[l]-'A']--;
//                 l++;
//             } 

//             if((r-l+1) - maxfreq <= k){
//                 maxlen = max(maxlen, r-l+1);
//             }
//             r++;
//         }
//         return maxlen;
//     }
// };