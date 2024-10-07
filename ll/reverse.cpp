#include <iostream>
#include <vector>
#include <stack>

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

ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    stack<int> st;
    while(temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        temp->val = st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

ListNode* reverseListIterative(ListNode* head) {
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

ListNode* reverseListRecursive(ListNode* head) {
    // Base case: if head is NULL (empty list) or head->next is NULL (single node)
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* newHead = reverseListRecursive(head->next);

    // At this point, newHead is the last node in the original list (which is now the head of the reversed list)
    // Now we reverse the pointers: 
    // Make the node after the current head (head->next) point back to head
    ListNode* front = head->next; 
    front->next = head;

    // Set the current head's next to NULL, because it's now the last node in the reversed list
    head->next = NULL;

    // Return the new head of the reversed list
    return newHead;
}

int main() {
    vector<int> vec = {1,2,3,6,4,5};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);
    head = reverseListRecursive(head);
    cout << endl << "Reversed List: ";
    printList(head);

    return 0;
}
