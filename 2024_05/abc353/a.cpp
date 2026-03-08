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
	vector<int> a(n);
	int j = -1;
	int x;
	cin >> x;
	for (int i = 2; i < n+1; ++i) {
		int y;
		cin >> y;
		if (j == -1 && y > x) {
			j = i;
		}
	}
	cout << j << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}