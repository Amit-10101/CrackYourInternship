#include <bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int>& arr) {
	int n = arr.size();
	int start = -1;
	int end = -1;

	for (int i = 1; i < n; i++) {
		if (arr[i-1] > arr[i]) {
			if (start == -1) start = i-1;
			end = i;
		}
	}

	if (start == -1) return true;

	reverse(arr.begin()+start, arr.begin()+end+1);

	for (int i = 1; i < n; i++) {
		if (arr[i-1] > arr[i]) {
			return false;
		}
	}

	return true;
}

int main() { 
    vector<int> arr = { 1, 2, 5, 4, 3, 6, 7, 8 }; 

	if (checkSorted(arr)) {
		cout << "Can be sorted" << endl;
	} else {
		cout << "Can't be sorted" << endl;
	}
  
    return 0; 
} 