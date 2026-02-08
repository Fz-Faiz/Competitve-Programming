// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;

//         ListNode* newNode = reverseList(head->next);

//         ListNode* front = head -> next;
//         front->next = head;
//         head->next = NULL;

//         return newNode;
//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
// ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) return head;

//         ListNode* newNode = reverseList(head->next);

//         ListNode* front = head -> next;
//         front->next = head;
//         head->next = NULL;

//         return newNode;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL) return true;
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast->next != NULL && fast->next->next != NULL){
//             slow = slow->next;
//             fast = fast-> next->next;
//         }

//         ListNode* newHead = reverseList(slow->next);
//         ListNode* first = head;
//         ListNode* second = newHead;

//         while(second != NULL){
//             if(first->val != second->val){
//                 reverseList(newHead);
//                 return false;
//             }
//             first=first->next;
//             second=second->next;
//         }

//         reverseList(newHead);
//         return true;

//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* t1 = list1;
//         ListNode* t2 = list2;
//         ListNode* dummynode = new ListNode(-1);
//         ListNode* temp = dummynode;
//         while(t1 != NULL && t2 != NULL){
//             if(t1->val < t2->val){
//                 temp->next = t1;
//                 temp = t1;
//                 t1 = t1->next;
//             }
//             else{
//                 temp->next = t2;
//                 temp = t2;
//                 t2 = t2->next;
//             }
//         }

//         if(t1) temp->next =t1;
//         else temp->next = t2;

//         return dummynode->next;
//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == NULL || head->next == NULL) return false;
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast != NULL && fast->next != NULL){
//             slow = slow -> next;
//             fast = fast -> next -> next;
//             if(slow == fast) return true;
//         }

//         return false;
//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head){
//         if(head == NULL || head -> next == NULL) return head;
//         ListNode* temp = head;
//         ListNode* prev = NULL;
//         while(temp != NULL){
//             ListNode* front = temp -> next;
//             temp -> next = prev;
//             prev = temp;
//             temp = front;
//         }
//         return prev;
//     }
//     void reorderList(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast != NULL && fast -> next != NULL){
//             slow = slow -> next;
//             fast = fast -> next -> next;
//         }

//         ListNode* temp = head;
//         ListNode* prev = reverseList(slow);

//         while(prev->next != NULL && prev != NULL){
//             ListNode* front = temp -> next;
//             ListNode* prevfront = prev -> next;

//             temp -> next = prev;
//             prev -> next = front;

//             temp = front;
//             prev = prevfront;
//         } 

      
//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
//         if(head == NULL || head->next == NULL) return NULL;

//         int cnt = 0;
//         ListNode* temp;
//         temp = head;

//         while(temp != NULL){
//             temp = temp -> next;
//             cnt++;
//         }

//         temp = head;
//         int k  = cnt - n -1;
//         if(cnt == n) return head->next;
//         while(k--){
//             temp = temp -> next;
//         }
//         ListNode* front = temp -> next;
//         temp -> next = temp -> next -> next;
//         front -> next = NULL;

//         return head;
//     }
// };