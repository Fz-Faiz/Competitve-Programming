// 77. Combinations
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, int k, int n, vector<int> &ds){
        if(k == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = start ; i <= n; ++i){
            ds.push_back(i);
            solve(i+1, k-1, n, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        solve(1, k, n, ds);
        return ans;
    }
};

//46. Permutations
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& ds,unordered_set<int>& st){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(st.find(nums[i]) == st.end()){
                ds.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, ds, st);
                ds.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> ds;
        unordered_set<int> st;
        solve(nums, ds, st);
        return ans;
    }
};

//90. Subsets II
class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind, vector<int> &nums, vector<int> &ds){
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); ++i){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, nums, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, nums, ds);
        return ans;
    }
};

// 47. Permutations II
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(map<int,int> &mp, vector<int> &ds){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        for(auto& [num, cnt]: mp){
            if(cnt == 0){
                continue;
            }
            ds.push_back(num);
            mp[num]--;
            solve(mp, ds);
            ds.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        map<int,int> mp;
        for(auto &n: nums){
            mp[n]++;
        }
        vector<int> ds;
        solve(mp, ds);
        return ans;
    }
};

// 79. Word Search
class Solution {
public:
    int n, m;
    bool find(vector<vector<char>>& board, int i, int j, int idx, string word){
        if(idx == word.size()) return true;

        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        int result = find(board, i-1, j, idx+1, word) ||
                    find(board, i+1, j, idx+1, word) ||
                    find(board, i, j-1, idx+1, word) ||
                    find(board, i, j+1, idx+1, word);
        board[i][j] = temp;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == word[0] && find(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

// 17. Letter Combinations of a Phone Number

class Solution {
public:
    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    void solve(int idx, string& digits, string& ds){
        if(idx == digits.size()){
            ans.push_back(ds);
            return;
        }

        string letters = mp[digits[idx]];
            for(auto& it: letters){
                ds.push_back(it);
                solve(idx+1, digits, ds);
                ds.pop_back();
            }


    }
    vector<string> letterCombinations(string digits) {
        string ds;
        solve(0, digits, ds);
        return ans;
    }
};