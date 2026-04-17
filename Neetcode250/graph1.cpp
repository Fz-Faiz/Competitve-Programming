
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

// 200. Number of Islands
 
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<int>>& visited){

        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(grid[i][j] == '0' || visited[i][j]) return;
   
        visited[i][j] = 1;
       

        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);

        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// 695. Max Area of Island

class Solution {
public:
    int m, n;
    
    int  dfs(vector<vector<int>>& grid, int i, int j, int &area){
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(grid[i][j] == 0) return 0;

        area++;
        grid[i][j] = 0;

        dfs(grid, i+1, j, area);
        dfs(grid, i-1, j, area);
        dfs(grid, i, j+1, area);
        dfs(grid, i, j-1, area);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

// 133. Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: 
    unordered_map<Node*, Node*> mp;
    void dfs(Node* node, Node* clone_node){
        
        for(auto& n: node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone);
            }else{
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* clone_node = new Node(node->val);

        mp[node] = clone_node;

        dfs(node, clone_node);

        return clone_node;



    }
};

// 994. Rotting Oranges
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;
        int freshCount = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto& dir: directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && grid[i_][j_] == 1){
                        grid[i_][j_] = 2;
                        q.push({i_, j_});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }

        return freshCount == 0 ? (minutes-1) : -1;


    }
};