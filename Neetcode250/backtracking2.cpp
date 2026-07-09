// 51. N-Queens
class Solution {
public:
    int N;
    vector<vector<string>> result;

    bool isValid(vector<string>& board, int row, int col){
        //Look upward
        for(int i = row-1; i >= 0; --i){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //Left diagonal
        for(int i = row-1, j = col-1; i >= 0 && j>=0; --i, --j){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //Right Diagonal
        for(int i = row-1, j = col+1; i>=0 && j>=0 ; --i, ++j){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;

    }
    void solve(vector<string>& board, int row){
        if(row >= N){
            result.push_back(board);
            return ;
        }

        for(int col = 0; col < N; ++col){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));

        solve(board, 0);

        return result;
    }
};

// 698. Partition to K Equal Sum Subsets

class Solution {
public:
    bool solve(vector<int>& nums, int k, vector<bool>& visited, int idx, int target, int curr_sum){
        if(k == 1) return true;

        if(curr_sum == target) return solve(nums, k-1, visited, 0, target, 0);

        for(int i = idx; i < nums.size(); ++i){
            if(visited[i] || curr_sum + nums[i] > target) continue;

            visited[i] = true;
            if(solve(nums, k, visited, i+1, target, curr_sum+nums[i])) return true;
            visited[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums), end(nums), 0);
        vector<bool> visited(nums.size(), false);

        if(sum % k != 0) return false;

        int target = sum / k;

        sort(begin(nums), end(nums), greater<int>());

        return solve(nums, k, visited, 0, target, 0);
    }
};

// 140. Word Break II
class Solution {
public:
    vector<string> result;
    unordered_set<string> st;
    void solve(int i, string &currSentense, string& s){
        if(i >= s.length()){
            result.push_back(currSentense);
            return;
        }
        for(int j = i; j < s.length(); ++j){
            string tempword = s.substr(i, j-i+1);
            if(st.count(tempword)){ // valid word
                string tempSentense = currSentense;
                if(!currSentense.empty()){
                    currSentense += " ";
                }
                currSentense += tempword; // take tempword
                solve(j+1, currSentense, s);  // Explore 
                currSentense = tempSentense;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &word: wordDict){
            st.insert(word);
        }
        string currSentense = "";
        solve(0, currSentense, s);
        return result;
    }
};

// 52. N-Queens II
class Solution {
public:
int N;
    vector<vector<string>> result;

    bool isValid(vector<string>& board, int row, int col){
        //Look upward
        for(int i = row-1; i >= 0; --i){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //Left diagonal
        for(int i = row-1, j = col-1; i >= 0 && j>=0; --i, --j){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        //Right Diagonal
        for(int i = row-1, j = col+1; i>=0 && j>=0 ; --i, ++j){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;

    }
    void solve(vector<string>& board, int row){
        if(row >= N){
            result.push_back(board);
            return;
        }
        for(int col = 0; col < N; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                 solve(board, row+1);
                 board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        solve(board, 0);
        return result.size();
    }
};