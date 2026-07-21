#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = nullptr;
    }

    ListNode(int x) {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *next) {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2 && carry==0){
            return nullptr;
        }

        int sum = carry;

        if(l1){
            sum += l1->val;
        }
        if(l2){
            sum += l2->val;
        }

        ListNode* node  = new ListNode(sum%10);

        node->next = solve(
            l1 ? l1->next : nullptr,
            l2 ? l2->next : nullptr,
            sum/10
        );

        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1, l2, 0);
    }
};

// Function to create a linked list
ListNode* createList() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n == 0) return nullptr;

    ListNode *head = nullptr, *tail = nullptr;

    cout << "Enter node values: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* newNode = new ListNode(x);

        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val;
        if(head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution obj;

    cout << "First Linked List\n";
    ListNode* l1 = createList();

    cout << "\nSecond Linked List\n";
    ListNode* l2 = createList();

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "\nSum List: ";
    printList(result);

    return 0;
}