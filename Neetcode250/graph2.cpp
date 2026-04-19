// 130. Surrounded Regions

class Solution {
public:
    int m, n;
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return;
        }
        if(vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = 1;
        dfs(i+1, j, vis, board);
        dfs(i-1, j, vis, board);
        dfs(i, j-1, vis, board);
        dfs(i, j+1, vis, board);

    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // first row and last row
        for(int j = 0; j < n; ++j){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j, vis, board);
            }
        }
        // first column and last column
        for(int i = 0; i < m; ++i){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, vis, board);
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};

// 752. Open the Lock
class Solution {
public:
    void fillNeighbours(queue<string>& q, string curr, unordered_set<string>& st){
        for(int i = 0 ; i < 4; ++i){
            int ch = curr[i];

            int inc = ch == '9'? '0' : ch+1;
            int dec = ch == '0'? '9' : ch-1;

            curr[i] = inc;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            } 
            curr[i] = dec;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            }
            curr[i] = ch;

        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(begin(deadends), end(deadends));
        string start = "0000";

        if(st.find(start) != st.end()){
            return -1;
        }

        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == target){
                    return level;
                }
                fillNeighbours(q, curr, st);
            }
            level++;
        }
        return -1;

    }
};

// Topo sort(kahn's algo)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; ++i){
            for(auto& it: edges[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto& it: edges[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};

// 207. Course Schedule
class Solution {
public:
    bool checktoposort(int n, unordered_map<int, vector<int>>& adj, vector<int>& indegree){
        queue<int> q;
        int count  = 0;
        for(int i = 0; i < n; ++i){

            if(indegree[i] == 0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& v: adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        
        for(auto& it: prerequisites){
            int a = it[0];
            int b = it[1];

            // b ---> a
            adj[b].push_back(a);

            indegree[a]++;

        }

        return checktoposort(numCourses, adj, indegree);
    }
};