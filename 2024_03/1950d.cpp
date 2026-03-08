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


bool isbin(int n) {
	for (int i = 0; i < 4; ++i) {
		int m = pow(10, 4-i);
		if (n/m != 0 && n/m != 1) {
			return false;
		}
		n = n % (int)pow(10, 4-i);
	}
	if (n != 1 && n != 0) return false;
	return true;
}
void solve(vector<int>& intlist) {
	int n;
	cin >> n;
	for (auto i : intlist) {
		while (n >= i && n % i == 0) {
			if (isbin(n)) {
				cout << "YES" << endl;
				return;
			}
			n = n / i;

		}
	}
	// cout << n << endl;
	if (isbin(n)) cout << "YES" << endl;
	else cout << "NO" << endl;	
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> intlist;
	for (int i1 = 0; i1 < 2; ++i1) {
		for (int i2= 0; i2 < 2 ; ++i2) {
			for (int i3 = 0; i3 < 2; ++i3) {
				for (int i4 = 0; i4 < 2; ++i4) {
					int x = i1 + i2 * 10 + i3 * 100 + i4 *1000;
					if (x !=1 && x != 0) {
						intlist.push_back(x);
					}
				}
			}
		}
	}

    int test_cases;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(intlist);
    }
}