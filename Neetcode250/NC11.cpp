// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
        
//         stack<pair<int, int>> st;
//         int n = temperatures.size();
//         vector<int> ans(n, 0);

//         for(int i = 0; i < n; ++i){
//             while(!st.empty() && st.top().first < temperatures[i]){
//                 ans[st.top().second] = i-st.top().second;
//                 st.pop();
//             }
//             st.push({temperatures[i], i});
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     string decodeString(string s) {
//         vector<string> st;

//         for(auto &ch : s){
//             if(ch != ']'){
//                 st.push_back(string(1, ch));
//             }
//             else{
//                 string substr = "";
//                 while(st.back() != "["){
//                     substr = st.back() + substr;
//                     st.pop_back();
//                 }
//                 st.pop_back();

//                 string k = "";
//                 while(!st.empty() && isdigit(st.back()[0])){
//                     k = st.back() + k;
//                     st.pop_back();
//                 }

//                 int repeatedCount = stoi(k);
//                 string repeated = "";
//                 for(int i = 0 ; i < repeatedCount; ++i){
//                     repeated += substr;
//                 }
//                 st.push_back(repeated);
//             }

            
//         }
//         string result = "";
//             for(auto &str: st){
//                 result += str;
//             }
//         return result;
//     }
// };

// class Solution {
// public:
//     string simplifyPath(string path) {
//         string token = "";

//         stringstream ss(path);
//         stack<string> st;

//         while(getline(ss, token, '/')){

//             if(token == "" || token == ".") continue;

//             if(token != ".."){
//                 st.push(token);
//             }
//             else if(!st.empty()){
//                 st.pop();
//             }
//         }

//         if(st.empty())
//             return "/";
        
//         string result = "";

//         while(!st.empty()){
            
//             result = "/" + st.top() + result;
//             st.pop();

//         }
//         return result;


//     }
// };