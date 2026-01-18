#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     string generate(string &word){
//         int arr[26] = {0};
//         for(char &ch: word) arr[ch-'a']++;
//         string new_word = "";
//         for(int i = 0; i < 26; i++){
//             int freq = arr[i];
//             if(freq>0) new_word += string(freq, i+'a');
//         }
//         return new_word;
//     }
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n = strs.size();
//         vector<vector<string>> result;
//         unordered_map<string, vector<string>> mp;

//         for(int i = 0; i < n; ++i){
//             string temp = strs[i];
            
//             string new_word = generate(temp);

//             mp[new_word].push_back(temp);
//         }
//         for(auto it: mp){
//             result.push_back(it.second);
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int k = 0;

//         for(int i = 0; i < nums.size(); ++i){
//             if(nums[i] != val){
//                 nums[k] = nums[i];
//                 k++;
//             }
//         }
//         return k;
//     }
// };

// Moore's Voting Algorithm is used to find the majority element in n size input
// > n / 2 (By keeping a count of elements assusming first element is majority)



// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // Moore's Voting Algorithm
//         int n = nums.size();
//         int cnt = 0;
//         int ele;
//         for(int i = 0; i < n; ++i){
//             if(cnt == 0){
//                 cnt = 1;
//                 ele = nums[i];
//             }
//             else if(ele == nums[i]){
//                 cnt++;
//             }else{
//                 cnt--;
//             }
//         }
//         return ele;
//     }
// };

// There can be two collison in hashing 1. separate collison 2. open collision
// open collions -> Linear and quadratic
// separate collision -> Load Factor(It must be less than or equal to 0.75)
// Load Factor -> LF = n / m ||| n = number of elements, m = bucket size

// class MyHashSet {
// public:
//     int M; //   Number of buckets
//     vector<list<int>> buckets; 
//     int getIndex(int key){
//         return key%M;
//     }
//     MyHashSet() {
//         M = 15000;
//         buckets.resize(M);
//     }
    
//     void add(int key) {
//         int index = getIndex(key);

//         auto it = find(buckets[index].begin(), buckets[index].end(), key);

//         if(it == buckets[index].end())
//             buckets[index].push_back(key);
//     }
    
//     void remove(int key) {
//         int index = getIndex(key);

//         auto it = find(buckets[index].begin(), buckets[index].end(), key);

//         if(it != buckets[index].end())
//             buckets[index].erase(it);
//     }
    
//     bool contains(int key) {
//         int index = getIndex(key);

//         auto it = find(buckets[index].begin(), buckets[index].end(), key);

//         return it != buckets[index].end();
//     }
// };

// /**
//  * Your MyHashSet object will be instantiated and called as such:
//  * MyHashSet* obj = new MyHashSet();
//  * obj->add(key);
//  * obj->remove(key);
//  * bool param_3 = obj->contains(key);
//  */

// Use range-based for when you do not erase elements.
// Use iterator-based loops when erasing from a container.

// class MyHashMap {
// public:
//     using P = pair<int,int>;
//     int M;
//     vector<list<P>> bucket;

//     int getIndex(int key){
//         return key%M;
//     }
//     MyHashMap() {
//         M = 15000;
//         bucket.resize(M);
//     }
    
//     void put(int key, int value) {
//         int index = getIndex(key);

//         for(auto &it: bucket[index]){
//             if(it.first == key){
//                 it.second = value;
//                 return;
//             }
//         }

//         bucket[index].push_back({key, value});
//     }
    
//     int get(int key) {
//         int index = getIndex(key);

//         for(auto &it: bucket[index]){
//             if(it.first == key){
//                 return it.second;
//             }
//         }
//         return -1;
//     }
    
//     void remove(int key) {
//         int index = getIndex(key);
//         for(auto it = bucket[index].begin(); it != bucket[index].end(); ++it){
//             if(it->first == key){
//                 bucket[index].erase(it);
//                 return;
//             }
//         }
//     }
// };

// /**
//  * Your MyHashMap object will be instantiated and called as such:
//  * MyHashMap* obj = new MyHashMap();
//  * obj->put(key,value);
//  * int param_2 = obj->get(key);
//  * obj->remove(key);
//  */