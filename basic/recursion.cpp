#include <iostream>

using namespace std;

void print(int i, int n) {
  if (i > n) return;
  print(i + 1, n);
  cout << i++ << endl;
}

int sum(int i) {
  if (i == 0 || i == 1) {
    return i;
  }

  return i + sum(i-1);
}

int main() {
  int n;
  cin >> n;
  // print(1, n);

  cout << sum(n) << endl;

  return 0;
}