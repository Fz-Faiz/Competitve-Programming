
//463. Island Perimeter

class Solution {
public:
    int m, n;
    int peri;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0){
            peri++;
            return;
        }
        if(grid[i][j] == -1) return;

        grid[i][j] = -1;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

    }
    vector<vector<int>> directions{{1,0},{-1, 0}, {0, 1}, {0, -1}};
    int bfs(vector<vector<int>>& grid, int i, int j){
        int peri = 0;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = -1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto& dir: directions){
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if( i_ < 0 || j_ < 0 || i_ >=m || j_ >= n || grid[i_][j_] == 0){
                    peri++;
                }else if(grid[i_][j_] == -1){
                    continue;
                }else{
                    q.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
            
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    return bfs(grid, i, j);
                }
            }
        }
        return -1;
    }
};

// bfs

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int> ans;
        queue<int> q;
        q.push(0);
        int  n = adj.size();
        
        vector<int> visited(n, 0);
        visited[0] = 1;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            for(auto& it: adj[ele]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return ans;
    }
};

// DFS

class Solution {
  public:
    int n;
    
    vector<int> result;
    void dfs(vector<vector<int>>& adj, int node,vector<int>& vis){
        vis[node] = 1;
        result.push_back(node);
        
        for(auto& it: adj[node]){
            if(!vis[it]) dfs(adj, it, vis);
        }
        
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        n = adj.size();
        vector<int> vis(n, 0);
        dfs(adj, 0, vis);
        return result;
    }
};