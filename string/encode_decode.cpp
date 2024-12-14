#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(vector<string> &strs) {
    string encodedString;
    for (string s : strs) {
        string e = to_string(s.size()) + '#';
        encodedString.append(e).append(s);
    }

    return encodedString;
}

vector<string> decode(string &str) {
    vector<string> strs;
    int i = 0;
    while (i < str.size()) {
        int j = i;
        while (str[j] != '#') j++;
        
        // Get the length of the next word
        int length = stoi(str.substr(i, j - i));
        
        // Move i to the start of the actual string after '#'
        i = j + 1;
        
        // Extract the string of the given length
        strs.push_back(str.substr(i, length));
        
        // Move i to the next encoded length
        i += length;
    }
    return strs;
}

int main() {
    vector<string> strs = {"my", "name#", "#1s", "##2##"};
    string str = encode(strs);
    cout << str << endl;

    strs = decode(str);

    for (string s : strs) cout << s << " ";
    cout << endl;
    return 0;
}