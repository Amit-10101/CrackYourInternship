class Solution {
public:
    int check(int n, int arr[], int pages) {
        int students = 1;
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            if (total + arr[i] <= pages) {
                total += arr[i];
            } else {
                students++;
                total = arr[i];
            }
        }
        
        return students;
    }
		
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) return -1;
        
        long long left = *max_element(arr, arr+n);
        long long right = accumulate(arr, arr+n, 0);
        
        while (left < right) {
            long long mid = left + ((right - left) / 2);
            
            int students = check(n, arr, mid);
            if (students == m) {
                right = mid;
            } else if (students < m) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};