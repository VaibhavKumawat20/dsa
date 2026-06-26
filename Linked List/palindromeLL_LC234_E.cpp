#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;

        ListNode* slow = head;
        ListNode* fast = head;

        // Push the first half of the list onto the stack
        while (fast != nullptr && fast->next != nullptr) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle node if the length is odd
        if (fast != nullptr) {
            slow = slow->next;
        }

        // Compare the second half with the stack
        while (slow != nullptr) {
            if (s.empty() || s.top() != slow->val) {
                return false;
            }
            s.pop();
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;

    if (obj.isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}