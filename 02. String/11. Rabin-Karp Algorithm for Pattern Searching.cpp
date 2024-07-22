#include <bits/stdc++.h>
using namespace std;

#define d 256
#define mod INT_MAX

void search(string& s, string& pattern) {
    int m = s.size();
    int n = pattern.size();

    int pHash = 0;
    int sHash = 0;

    int h = 1;
    for (int i = 0; i < n - 1; i++) {
        h = (h * d) % mod;
	}

    for (int i = 0; i < n; i++) {
        pHash = (d * pHash + pattern[i]) % mod;
        sHash = (d * sHash + s[i]) % mod;
    }

    for (int i = 0; i <= m - n; i++) {
        if (sHash == pHash) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (s[i + j] != pattern[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

        if (i < m - n) {
            sHash = (d * (sHash - s[i] * h) + s[i + n]) % mod;
            if (sHash < 0) {
                sHash = (sHash + mod);
			}
        }
    }
}

int main() {
    string s = "AABAACAADAABAABA";
    string pattern = "AABA";

    search(s, pattern);

    return 0;
}