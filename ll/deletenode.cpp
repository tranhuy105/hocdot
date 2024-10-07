#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// since it is guaranteed that the given node node is not the last node in the linked list.
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next; 
    node->next = node->next->next;  
    delete temp; 
}

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

int main() {
    vector<int> vec = {4, 5, 1, 9};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);

    ListNode* nodeToDelete = head->next->next; 
    deleteNode(nodeToDelete);


    cout << "After Deleting Node: ";
    printList(head); 

    return 0;
}
