// c.cpp

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
	int n, t;
	cin >> n >> t;
	vector<int> a(t);

	for(auto & ai : a) cin >> ai;

	vector<int> row(n, 0 );
	vector<int> col(n,0);
	vector<int> diag(2,0);

	for (int i  =0; i < t; ++i) {
		int r = (a[i]-1) / n;
		int c = (a[i]-1) % n;
		row[r]++;
		col[c]++;
		// cout << r << " " << c << endl;
		if (r == c) diag[0]++;
		if (r+c==n-1) diag[1]++;

		if(row[r] == n || col[c] == n || diag[0] == n || diag[1] == n) {
			// if (diag[0].size()==n) cout << " yes";
			cout << i + 1 << endl;
			return;
		}
	}
	cout << "-1" << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}