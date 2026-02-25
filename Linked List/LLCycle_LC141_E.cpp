#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Connect nodes: 1 -> 2 -> 3 -> 4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Uncomment the next line to create a cycle
    // fourth->next = second;  // Creates cycle

    Solution obj;

    if(obj.hasCycle(head)){
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}