#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* llFromVector(const vector<int>& nums) {
    if (nums.empty()) return NULL;

    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;

    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* deleteMiddle(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }       
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return dummy->next;
}


int main() {
    vector<int> vec = {1,2,3,4};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);

    cout << "New List: ";
    head = deleteMiddle(head);
    printList(head);

    return 0;
}
