#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* middleOfLL(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while((fast != NULL) && (fast->next != NULL)){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);

    Solution obj;
    ListNode* middleOfLL = obj.middleOfLL(head);

    cout << middleOfLL->val << endl;

    return 0;
}