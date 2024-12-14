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

ListNode* reverse(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp != NULL) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

void deleteNode(ListNode* nodeToDelete) {
    if (nodeToDelete == NULL) return;
    nodeToDelete->val = nodeToDelete->next->val;
    ListNode* temp = nodeToDelete->next;
    nodeToDelete->next = temp->next;
    delete temp;    
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    head = reverse(head);
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        head = reverse(head);
        return head->next;
    }

    deleteNode(temp);
    head = reverse(head);
    return head;
}

ListNode* removeNthFromEndPremium(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // We need the slow to right before the deleted node for easy delete (just skip)
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
}

int main() {
    vector<int> vec = {1,2,3,4,5};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);

    cout << "New List: ";
    head = removeNthFromEndPremium(head, 1);
    printList(head);

    return 0;
}
