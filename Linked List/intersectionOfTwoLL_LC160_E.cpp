#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA != pB){
            if(pA == nullptr){
                pA = headB;
            }
            else{
                pA = pA->next;
            }

            if(pB == nullptr){
                pB = headA;
            }
            else{
                pB = pB->next;
            }
        }

        return pA; // intersection node or nullptr
    }
};

int main() {
    /*
        Create:

        A: 4 -> 1 \
                    8 -> 4 -> 5
        B: 5 -> 6 -> 1 /
    */

    // Common part
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    // List A
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    // List B
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: "
             << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}