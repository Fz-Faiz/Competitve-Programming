/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> mp;

        while(temp != NULL){
            Node* newnode = new Node(temp->val);
            mp[temp] = newnode;
            temp = temp -> next;
        }

        temp = head;

        while(temp != NULL){
            Node* copynode = mp[temp];
            copynode->next = mp[temp->next];
            copynode->random = mp[temp->random];
            temp = temp -> next;
        }

        return mp[head];
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummynode =  new ListNode(-1);
        dummynode->next = head;
        ListNode* prev = dummynode;
        for(int i = 1 ; i < left; ++i){
            prev = prev->next;
        }
        ListNode* curr = prev->next;

        for(int i = 1; i <= right-left; i++){
            ListNode* temp = prev->next;
            prev->next=curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }

        return dummynode->next;

    }
};

