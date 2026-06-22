#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            ListNode* del = temp->next;

            if (del->val == temp->val) {
                temp->next = del->next;
                del->next = NULL;
                delete del;
            }
            else
                temp = temp->next;
        }
        return head;
    }
};

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
    // Example: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    // Free memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}