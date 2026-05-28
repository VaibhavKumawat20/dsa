#include <iostream>
using namespace std;

// Definition for singly-linked list
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
    void reorderList(ListNode* head) {

        // Edge case
        if (head == NULL || head->next == NULL)
            return;

        // =========================
        // STEP 1: FIND MIDDLE
        // =========================

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL &&
               fast->next->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now at middle

        // =========================
        // STEP 2: REVERSE 2ND HALF
        // =========================

        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        // Break first half
        slow->next = NULL;

        while (curr != NULL) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nextNode;
        }

        // prev is head of reversed list

        // =========================
        // STEP 3: MERGE BOTH HALVES
        // =========================

        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

// Function to print linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:" << endl;
    printList(head);

    Solution obj;
    obj.reorderList(head);

    cout << "Reordered List:" << endl;
    printList(head);

    return 0;
}