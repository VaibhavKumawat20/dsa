#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        int size = 0;

        // Calculate size
        while(ptr1 != NULL){
            ptr1 = ptr1->next;
            size++;
        }

        // If deleting head
        if(size == n){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ptr1 = head;

        // Move to node before target
        for(int i = 1; i < (size - n); i++){
            ptr1 = ptr1->next;
        }

        ListNode* temp = ptr1->next;
        ptr1->next = temp->next;
        delete temp;

        return head;
    }
};

// Helper function to insert node at end
ListNode* insert(ListNode* head, int val) {
    if(head == NULL) return new ListNode(val);

    ListNode* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Helper function to print list
void printList(ListNode* head) {
    while(head != NULL){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = NULL;

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    int n = 2; // remove 2nd node from end

    head = obj.removeNthFromEnd(head, n);

    cout << "After Removal: ";
    printList(head);

    return 0;
}