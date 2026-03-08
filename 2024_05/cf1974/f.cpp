// f.cpp
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
int binary_search(map<i64, unordered_set<int>> &by, int p) {
	int n = by.size();
	auto it = by.begin();
	int low = 0; int high = n;
	while(high > low) {
		int mid = (high + low) / 2;
		if ((advance(it, mid)) -> first == p) {
			return mid;
		} else {
			if ((advance(it, mid)) -> first < p) {
				low = mid;
			} else {
				high = mid;
			}
		}
	}
	return -1;
}

void solve() {
	i64 a,b,n,m;
	cin >> a >> b >> n >> m;
	i64 row_st = 0, row_ed = a, col_st = 0, col_ed = b;
	map<i64, unordered_set<int>> by_r, by_c;
	for (int i = 0; i < n; ++i) {
		i64 x, y;
		cin >> x >> y;
		by_r[x].insert(y);
		by_c[y].insert(x);
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