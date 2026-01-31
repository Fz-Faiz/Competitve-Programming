// class Solution {
// public:
//     int calPoints(vector<string>& operations) {
//         stack<int> st;

//         for(string &op: operations){
//             if(op == "D"){
//                 st.push(2*st.top());
//             }else if(op == "C"){
//                 st.pop();
//             }
//             else if(op == "+"){
//                 int val = st.top(); st.pop();
//                 int val2 = st.top();
//                 st.push(val);
//                 st.push(val+val2);
//             }else{
//                 st.push(stoi(op));
//             }
//         }
//         int sum = 0;
//         while(!st.empty()){
//             sum+=st.top();
//             st.pop();
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     bool isValid(string s) {

//         stack<char> st;
//         unordered_map<char, char> mp;
//         mp['('] = ')';
//         mp['{'] = '}';
//         mp['['] = ']'; 
        
//         for(char &ch: s){
//             if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
//             else{
//                 if(st.empty()) return false;
//                 if(mp[st.top()] != ch) return false;
//                 st.pop();
//             }
//         }

//         return st.empty() == true;


//     }
// };

// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
//     MyStack() {
//     }
    
//     void push(int x) {
//         q2.push(x);

//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1, q2);
//     }
    
//     int pop() {
//         int result = q1.front();
//         q1.pop();
//         return result;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */

//  class MyQueue {
// public:
//     stack<int> input;
//     stack<int> output;
//     int peekEle = -1;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         if(input.empty()){
//             peekEle = x;
//         }

//         input.push(x);
//     }
//     // amortized o(1)
//     int pop() {
//         if(output.empty()){
//             // input -> ouput
//             while(!input.empty()){
//                 output.push(input.top());
//                 input.pop();
//             }
//         }

//         int val = output.top();
//         output.pop();
//         return val;
//     }
    
//     int peek() {
//         if(output.empty()) return peekEle;
//         return output.top();
//     }
    
//     bool empty() {
//         if(input.empty() && output.empty()) return true;

//         return false;
//     }
// };

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */

//  class MinStack {
// public:
//     using P = pair<int,int>;
//     stack<P> st;
    
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()) st.push({val, val});
//         else st.push({val, min(val, st.top().second)});


//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */