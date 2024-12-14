#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

int main() {
    vector<int> vec = {};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);

    ListNode* newList = oddEvenList(head);
    cout << "New List: ";
    printList(newList);

    return 0;
}