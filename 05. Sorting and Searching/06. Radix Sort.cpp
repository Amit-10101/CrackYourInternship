#include <bits/stdc++.h>
using namespace std;

void print(vector<auto>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void countSort(vector<int>& arr, int place) {
    int n = arr.size();
    vector<int> count(10, 0);
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / place) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    
    vector<int> temp(n, 0);
    for (int i = n-1; i >= 0; i--) {
        int rem = (arr[i] / place) % 10;
        int ind = --count[rem];
        temp[ind] = arr[i];
    }

    arr = temp;
}

void radixSort(vector<int>& arr) {
    int maxEle = *max_element(arr.begin(), arr.end());
    
    for (int i = 1; maxEle / i > 0; i *= 10) {
        countSort(arr, i);
    }
}

int main() {
	vector<int> arr = {334, 53, 548, 12, 90, 4, 73, 33};
	
	cout << "Original Array: ";
	print(arr);

	radixSort(arr);
	
	cout << "Updated Array:  ";
	print(arr);
	
	return 0;
}