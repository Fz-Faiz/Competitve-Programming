// class FreqStack {
// public:
// priority_queue<pair<int, pair<int, int>>> pq;
//         unordered_map<int, int> freq;
//         int pos = 0;
//     FreqStack() {
        
//     }
    
//     void push(int val) {
//         pq.push(make_pair(++freq[val], make_pair(++pos, val)));
//     }
    
//     int pop() {
//         auto val = pq.top();
//         pq.pop();
//         int x = val.second.second;
//         freq[x]--;
//         return x;
//     }
// };

// /**
//  * Your FreqStack object will be instantiated and called as such:
//  * FreqStack* obj = new FreqStack();
//  * obj->push(val);
//  * int param_2 = obj->pop();
//  */

//  class Solution {
// public:
//     vector<int> nse(vector<int> &heights){
//         int n = heights.size();
//         stack<pair<int, int>> st;
//         vector<int> result(n, n);
//         for(int i = 0; i < n; ++i){
//             while(!st.empty() && st.top().first > heights[i]){
//                 result[st.top().second]  = i;
//                 st.pop();
//             }
//             st.push({heights[i], i});
//         }
//         return result;
//     }
//     vector<int> pse(vector<int> &heights){
//         int n = heights.size();
//         stack<pair<int,int>> st;
//         vector<int> result(n , -1);
//         for(int i = 0; i < n; ++i){
//             while(!st.empty() && st.top().first >= heights[i]){
//                 st.pop();
//             }
//             if(!st.empty()){
//                 result[i] = st.top().second;
//             }
//             st.push({heights[i], i});
//         }
//         return result;
//     }
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> next = nse(heights);
//         vector<int> prev = pse(heights);

//         int ans = 0;
//         for(int i = 0; i < n; ++i){
//             int width = next[i] - prev[i] - 1;
//             ans = max(ans, heights[i] * width);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();

//         int lo = 0, hi = n-1;

//         while(hi - lo > 1){
//             int mid = lo + (hi-lo)/2;
//             if(nums[mid] < target) lo = mid + 1;
//             else hi = mid;
//         }

//         if(nums[lo] == target) return lo;
//         else if(nums[hi] == target) return hi;
//         else return -1;
//     }
// };

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();

//         int low = 0, high = n-1;

//         while(high - low > 1){
//             int mid = low + (high - low) / 2;

//             if(nums[mid] < target) low = mid + 1;
//             else high = mid;
//         }

//         if(target <= nums[low]) return low;
//         else if(target <= nums[high]) return high;
//         else return n;
//     }
// };