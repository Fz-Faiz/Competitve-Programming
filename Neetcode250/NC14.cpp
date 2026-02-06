// class Solution {
// public:
//     int find_pivot(vector<int> &nums, int n){
//         int lo = 0, hi = n-1;
//         while(hi - lo > 1){
//             int mid = lo + (hi - lo) / 2;

//             if(nums[mid] > nums[hi]){
//                 lo = mid + 1;
//             }
//             else{
//                 hi = mid;
//             }
//         }
//         if(nums[lo] <= nums[hi]) return lo;
//         return hi;
//     }
//     int bs(int lo, int hi, vector<int> &nums, int target){
//         if(lo > hi) return -1;
//         while(hi - lo > 1){
//             int mid = lo + (hi - lo) / 2;

//             if(nums[mid] < target) lo = mid + 1;
//             else hi = mid;
//         }
//         if(nums[lo] == target ) return lo;
//         else if(nums[hi] == target) return hi;
//         else return -1;
//     }
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();

//         int pivot_index = find_pivot(nums, n);


//         if(target >= nums[pivot_index] && target <= nums[n-1])
//             return bs(pivot_index, n-1, nums, target);
//         else
//             return bs(0, pivot_index-1, nums, target);
//     }
// };

// class Solution {
// public:
// int find_pivot(vector<int> &nums, int n){

        
//         int lo = 0, hi = n-1;

        
//         while(hi - lo > 1){

//             while(lo < hi && nums[lo] == nums[lo+1]) lo++;
//             while(lo < hi && nums[hi] == nums[hi-1]) hi--;
//             int mid = lo + (hi - lo) / 2;

//             if(nums[mid] > nums[hi]){
//                 lo = mid + 1;
//             }
//             else{
//                 hi = mid;
//             }
//         }
//         if(nums[lo] <= nums[hi]) return lo;
//         return hi;
//     }
//     bool bs(int lo, int hi, vector<int> &nums, int target){
//         if(lo > hi) return false;
//         while(hi - lo > 1){
//             int mid = lo + (hi - lo) / 2;

//             if(nums[mid] < target) lo = mid + 1;
//             else hi = mid;
//         }
//         if(nums[lo] == target ) return true;
//         else if(nums[hi] == target) return true;
//         else return false;
//     }
//     bool search(vector<int>& nums, int target) {
//         int n = nums.size();
      

//         int pivot = find_pivot(nums, n);

//         if(target >= nums[pivot] && target <= nums[n-1]){
//             return bs(pivot,n-1, nums, target);
//         }else return bs(0, pivot-1, nums, target);
//     }
// };

// class TimeMap {
// public:
//     unordered_map<string, vector<pair<string, int>>> mp;
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         mp[key].push_back({value, timestamp});
//     }
    
//     string get(string key, int timestamp) {
//         if(mp.find(key) == mp.end()) return "";

//         auto &v = mp[key];
//         int lo = 0,hi = v.size() - 1;

//         if(v[0].second > timestamp) return "";

//         while(hi - lo > 1){
//             int mid = lo + (hi - lo) / 2;
//             if(v[mid].second <= timestamp){
//                 lo = mid ;
//             }
//             else hi = mid-1;
//         }

//         if(v[hi].second <= timestamp) return v[hi].first;
//         else return v[lo].first;
//     }
// };

// /**
//  * Your TimeMap object will be instantiated and called as such:
//  * TimeMap* obj = new TimeMap();
//  * obj->set(key,value,timestamp);
//  * string param_2 = obj->get(key,timestamp);
//  */

//  class Solution {
// public:
//     int cntSum(vector<int> &nums, int mid){
//         int sum = 0;
//         int maxcnt = 1;
//         for(int i = 0; i < nums.size(); ++i){
//             sum += nums[i];
//             if(sum > mid){
//                 maxcnt++;
//                 sum = nums[i];
//             }
//         }
//         return maxcnt;
//     }
//     int splitArray(vector<int>& nums, int k) {
//         int n = nums.size();

//         int lo = *max_element(begin(nums), end(nums));
//         int hi = accumulate(begin(nums) ,end(nums), 0);

//         while(hi - lo > 1){
//             int mid = lo + (hi - lo) / 2;

//             int cnt = cntSum(nums, mid);

//             if(cnt > k){
//                 lo = mid ;
//             }else hi = mid;
//         }

//         if(cntSum(nums, lo) <= k) return lo;
//         else return hi;
//     }
// };