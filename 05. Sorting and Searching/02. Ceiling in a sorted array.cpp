#include <bits/stdc++.h>
using namespace std;

pair<bool, int> findCeil(vector<int>& arr, int target) {
    int n = arr.size();
    int left = 0;
    int right = n-1;
    
    if (target > arr[right]) return {false, -1};
    
    while (left < right) {
        int mid = left + ((right - left) / 2);
        
        if (arr[mid] >= target) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

	return {true, left};
}
 
int main() {
    vector<int> arr = { 1, 2, 8, 10, 10, 12, 19 };
    int n = arr.size();
    int target = 5;

	auto ans = findCeil(arr, target);

    if (ans.first) {
        cout << "Ceil element of " << target << " is " << arr[ans.second] << endl;
    } else {
        cout << "Ceil element does not exist " << endl;
    }
    return 0;
}
