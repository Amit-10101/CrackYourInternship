#include <bits/stdc++.h>
using namespace std;

void printDuplicateChars(string& s) {
	unordered_map<char, int> um;

	for (char c : s) {
		um[c]++;
	}

	for (auto& pair : um) {
		if (pair.second > 1) {
			cout << pair.first << ": " << pair.second << endl;
		}
	}
}

int main() {
	string s;
	cout << "Input string: ";
	cin >> s;

	printDuplicateChars(s);

	return 0;
}