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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans(-1);
        ListNode* temp = &ans;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != NULL) {
            temp->next = list1;
        }
        else {
            temp->next = list2;
        }

        return ans.next;
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
    // List 1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // List 2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Solution obj;
    ListNode* merged = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    // Free memory
    while (merged != NULL) {
        ListNode* del = merged;
        merged = merged->next;
        delete del;
    }

    return 0;
}