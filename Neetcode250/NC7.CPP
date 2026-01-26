// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();

//         for(int i=  0 ;i < n; ++i){
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             int j=i+1;
//             int k=n-1;
//             while(j<k){
//                 int sum = nums[i] + nums[j] +nums[k];
//                 if(sum < 0) j++;
//                 else if(sum > 0) k--;
//                 else {
//                     vector<int> temp = {nums[i], nums[j], nums[k]};
//                     ans.push_back(temp);
//                     j++;
//                     k--;
//                     while(j<k && nums[j] == nums[j-1]) j++;
//                     while(j<k && nums[k] == nums[k+1]) k--;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());

//         for(int i = 0 ; i < n ; ++i){
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             for(int j= i+1;j <n;j++){
//                 if(j > i+1 && nums[j] == nums[j-1]) continue;
//                 int k = j+1;
//                 int l = n-1;
//                 while(k<l){
//                     long long sum = nums[i];
//                     sum+=nums[j];
//                     sum+=nums[k];
//                     sum += nums[l];
//                     if(sum == target){
//                         vector<int> temp = {nums[i], nums[j], nums[k] ,nums[l]};
//                         ans.push_back(temp);
//                         k++,l--;
//                         while(k<l && nums[k] == nums[k-1]) k++;
//                         while(k<l && nums[l] == nums[l+1]) l--;

//                     }else if(sum < target ) k++;
//                     else l--;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;
//         reverse(nums.begin(), nums.end()-k);
//         reverse(nums.end()-k, nums.end());
//         reverse(nums.begin(), nums.end());
//     }
// };

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int i = 0, j = n-1;
//         int maxArea = 0;
//         while(i<j){
//             int area = (j-i) * min(height[i], height[j]);
//             maxArea = max(maxArea, area);
//             if(height[i] < height[j]) i++;
//             else j--;
//         }

//         return maxArea;
//     }
// };

// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int n  = people.size();
//         int boat = 0;
//         sort(people.begin(), people.end());
//         int i = 0, j = n -1;
//         while(i <= j){
//             if(people[i] + people[j] <= limit){
//                 j--, i++;
//             }
//             else{
//                 j--;
//             }
//             boat++;
//         }
//         return boat;
//     }
// };


// class Solution {
// public:
//     vector<int> getLeftMax(vector<int> &height, int n){
//         vector<int> leftMax(n);
//         leftMax[0] = height[0];
//         for(int i = 1; i < n; ++i){
//             leftMax[i] = max(leftMax[i-1], height[i]);
//         }
//         return leftMax;
//     }
//     vector<int> getRightMax(vector<int> &height, int n){
//         vector<int> rightMax(n);
//         rightMax[n-1] = height[n-1];
//         for(int i = n-2; i >= 0; --i){
//             rightMax[i] = max(rightMax[i+1], height[i]);
//         }
//         return rightMax;
//     }
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> leftMax = getLeftMax(height, n);
//         vector<int> rightMax = getRightMax(height, n);
//         int sum = 0;
//         for(int i = 0 ; i < n ; ++i){
//             int h = min(leftMax[i], rightMax[i]) - height[i];
//             sum+=h;
//         }
//         return sum;
//     }
// };