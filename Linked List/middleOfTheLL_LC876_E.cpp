#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 1;

        while(temp!=nullptr && temp->next!=nullptr){
            count++;
            temp = temp->next;
        }
        count /= 2;

        while(count){
            head = head->next;
            count--;
        }

        return head;
    }
};

int main() {
    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "Middle node: " << middle->val << endl;

    return 0;
}