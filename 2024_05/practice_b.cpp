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

void sort(string &s, int low, int high) {
	// int i_pivot;
	if (low < high) {
		char pivot = s[high-1];
		int i = low;
		for (int j = low; j < high-1; ++j) {
			cout << "? " << pivot << " " << s[j] << endl;
			char r; cin >> r;
			fflush(stdout);
			if (r == '>') {
				swap(s[i], s[j]);
				i++;
			}
		}
		swap(s[i], s[high-1]);
		sort(s, low, i);
		sort(s, i+1, high);
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s(n, 'A');
	for (int i = 0; i < n; ++i) {
		s[i] += i;
	}
	sort(s, 0, n);
	cout << "! ";
	for (char &si : s) {
		cout << si;
	}
	cout << "\n";
	fflush(stdout);
    return;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}