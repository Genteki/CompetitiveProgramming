// a.cpp
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
	int x,y;
	cin >> x >> y;
	int a2 = (y+1) / 2;
	int b = a2 * 15 - y * 4;
	if (b >= x) {
		cout << a2 << endl;
	}
	else {
		cout << (a2 + (x - b + 14) / 15) << endl;
	}
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