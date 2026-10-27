#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for(int i = 1; i <= right-left; i++){
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }

        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Input: head = [1,2,3,4,5], left = 2, right = 4
    // Output: [1,4,3,2,5]

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2;
    int right = 4;

    Solution obj;
    head = obj.reverseBetween(head, left, right);

    cout << "Output: ";
    printList(head);

    return 0;
}
