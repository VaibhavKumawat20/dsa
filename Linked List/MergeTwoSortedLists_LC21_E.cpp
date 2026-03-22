#include <iostream>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};

// Function to insert at end
ListNode* insertNode(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    if (head == NULL) return newNode;

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    // First sorted list: 1 -> 3 -> 5
    head1 = insertNode(head1, 1);
    head1 = insertNode(head1, 3);
    head1 = insertNode(head1, 5);

    // Second sorted list: 2 -> 4 -> 6
    head2 = insertNode(head2, 2);
    head2 = insertNode(head2, 4);
    head2 = insertNode(head2, 6);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Solution obj;
    ListNode* mergedHead = obj.mergeTwoLists(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}