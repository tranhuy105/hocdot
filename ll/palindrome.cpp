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

bool isPalindrome(ListNode* head) {
    stack<int> s;

    ListNode* temp = head;
    while (temp != NULL) {
        s.push(temp->val);
        temp=temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (s.top() == temp->val) {
            s.pop();
            temp=temp->next;
        }
        else return false;
    }

    return true;
}

ListNode* reverseList(ListNode* head) {
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

bool isPalindrome2(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = reverseList(slow);

    ListNode* firstHalf = head;
    ListNode* temp = secondHalf;
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false; 
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverseList(temp);

    return true;
}



int main() {
    vector<int> vec = {1,2,1};
    ListNode* head = llFromVector(vec);

    cout << "Original List: ";
    printList(head);

    cout << "Is Palindrome: " << isPalindrome2(head) << endl;
    return 0;
}