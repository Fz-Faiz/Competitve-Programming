class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, vector<pair<int,int>>> mp2;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        mp2[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto i: mp2[userId]) pq.push(i);
        for(auto i: mp[userId]){
            for(auto j: mp2[i]){
                pq.push(j);
            }
        }
        vector<int> feed;
        int count = 10;
        while(!pq.empty() && count){
            feed.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


 class Solution {
public
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int,3>> sortedTasks;

        for(int i = 0; i < n; ++i){
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];
            sortedTasks.push_back({start_time, processing_time, i});
        }
        // sort
        sort(sortedTasks.begin(), sortedTasks.end());

        long long curr_time = 0;
        int idx = 0;

        vector<int> result;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        while(idx < n || !pq.empty()){
            if(pq.empty() && curr_time < sortedTasks[idx][0]){
                curr_time = sortedTasks[idx][0];
            }
            while(idx<n && sortedTasks[idx][0] <= curr_time){
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }
            auto curr_task = pq.top();
            pq.pop();

            curr_time+=curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};
class Solution {
public:
    typedef pair<int,int> P;
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> count(26, 0);

        for(auto &ch: s){
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2) return "";
        }

        priority_queue<P, vector<P>> pq;

        for(char ch = 'a'; ch <= 'z'; ch++){
            if(count[ch-'a'] > 0) pq.push({count[ch-'a'],ch});

        }

        string result = "";

        while(pq.size() >= 2){
            auto P1 = pq.top(); pq.pop();
            auto P2 = pq.top(); pq.pop();
            result.push_back(P1.second); P1.first--;
            result.push_back(P2.second); P2.first--;

            if(P1.first>0) pq.push(P1);
            if(P2.first>0)pq.push(P2);

        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;


    }
};