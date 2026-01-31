// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         int l = 0, r = 0, cnt = 0;
//         int minLen = INT_MAX;
//         int sIdx = -1;

      
//         int hsh[256] = {0};
//         for(int i = 0; i < m; ++i) hsh[t[i]]++;

//         while(r < n){

//             if(hsh[s[r]] > 0){
//                 cnt++;
//             }
//             hsh[s[r]]--;

//             while(cnt == m){
//                 if(r-l+1 < minLen){
//                     minLen = r-l+1;
//                     sIdx = l;
//                 }
//                 hsh[s[l]]++;
//                 if(hsh[s[l]] > 0){
//                     cnt--;
//                 }
//                 l++;
//             }

//             r++;
//         }

//         return sIdx == -1 ? "" : s.substr(sIdx, minLen);
//     }
// };

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();

//         deque<int> dq;

//         vector<int> result;
        
//         for(int i =0 ; i< n;i++){
//             // Step -1  make space for nums[i]

//             while(!dq.empty() && dq.front() <= i-k){
//                 dq.pop_front();
//             }

//             // Step -2
//             while(!dq.empty() && nums[i] > nums[dq.back()]){
//                 dq.pop_back();
//             }

//             // Step - 3
//             dq.push_back(i);

//             if(i >= k-1) result.push_back(nums[dq.front()]);


//         }

//         return result;
//     }
// };