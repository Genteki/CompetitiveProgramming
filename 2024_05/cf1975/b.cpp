// b.cpp
#include <bits/stdc++.h>
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
#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x))std::cin>>ai
using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int n ;
	cin >> n;
	vector<int> a(n);
	for (auto & ai : a) cin >> ai;
	sort(a.begin(), a.end());
	set<int> st;
	for (int i = 0; i < n; ++i) {
		if (a[i] % a[0] != 0) {
			st.insert(a[i]);
		}
	} 
	int x = *st.begin();
	for(auto sti : st) {
		if (sti % x != 0) {
			cout << 
			"No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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