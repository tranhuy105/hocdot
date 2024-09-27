#include <iostream>

using namespace std;

// log 10 cung duoc
int count(int n) {
  int cnt = 0;
  while (n > 0) {
    int lastD = n % 10;
    cnt++;
    n = n /10;
  }

  return cnt;
}

int reverseNum(int n) {
  int reverse = 0;
  while (n > 0)
  {
    int last = n % 10;
    reverse = reverse * 10 + last;
    n = n /10;
  }

  return reverse;
}

int palindrome(int num) {
  if (num == reverseNum(num)) {
    return 1;
  }

  return 0;
}

int amstrong(int num) {
  int dup = num;
  int sum = 0;
  while (num > 0) {
    int last = num % 10;
    sum += last * last * last;
    num = num / 10;
  }

  return sum == dup;
}

int gcd(int num1, int num2) {
  for (int i = min(num1, num2); i >= 1; --i) {
    if (num1 % i == 0 && num2 % i == 0) {
      return i;
    }
  }

  return -1;
}

int gcd2(int a, int b) {
  if (b == 0) return a;
  return gcd2(b, a % b);
}

int main() {
  cout << gcd2(9, 12) << endl;

  return 0;
}

