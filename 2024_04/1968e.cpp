// 1968e.cpp

// #include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <vector>
#include <regex>

using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int n;
	cin >> n;
	cout << n << " " << n << endl;
	if (n % 2 == 0) {
		for (int i = 0; i < n - 1; ++i) {
			if (i % 2 == 0) {
				cout << "1 " << i+1 << endl;
			} else {
				cout << (n - i) << " " << n << endl;
			}
		}
	}
	else {
		for (int i = 0; i < n - 2; ++i) {
			if (i % 2 == 0) {
				cout << "1 " << i+1 << endl;
			} else {
				cout << (n - i) << " " << n << endl;
			}
		}
		cout << "1 " << n << endl;
	}
	cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int test_cases;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}