//70. Climbing Stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3){
            return n;
        }
        vector<int> stairs(n+1);

        stairs[0] = 0;
        stairs[1] = 1;
        stairs[2] = 2;

        for(int i = 3; i <= n; ++i){
            stairs[i] = stairs[i-1]+stairs[i-2];
        }
        return stairs[n];
    }
};

// 198. House Robber

class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n, int idx){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int steal = nums[idx]+solve(nums,n ,idx+2);
        int skip = solve(nums, n , idx+1);

        return dp[idx] =  max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        if(n == 1) return nums[0];
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i <= n; ++i){
            int steal = nums[i-1] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(steal, skip);
        }
        return dp[n];
    }
};