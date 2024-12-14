#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        while (left < right && !isalnum(s[right])) {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}