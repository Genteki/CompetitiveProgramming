#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // kmp
    vector<int> pi(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int k = pi[i];
        while (k > 0 && s[k] != s[i + 1]) {
            k = pi[k - 1];
        } 
        if (s[k] == s[i + 1]) {
            pi[i + 1] = k + 1;
        } else {
            pi[i + 1] = k;
        }
    }
    vector<int> ans;
    int k = n;
    while (pi[k - 1] > 0) {
        ans.push_back(pi[k - 1]);
        k = pi[k - 1];
    }
    std::reverse(ans.begin(), ans.end());
    for (auto ai : ans) cout << ai << " ";
}