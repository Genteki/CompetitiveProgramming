// d.cpp

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
	int n ;
	string s;
	cin >> n >> s;
	int south = 0, east = 0, north = 0, west = 0;
	for (auto & si : s) {
		if (si == 'S') {
			south++;
		} else if (si == 'N') north++;
		else if (si == 'W') west++;
		else east++;
	}

	if ((south+north) % 2 || (east+west) % 2) {
		cout << "NO" << endl;
		return;
	}
	if ((south == 1 && north == 1) && (east==0 && west == 0)) {
		cout << "NO" << endl;
		return;
	}
	if ((south == 0 && north == 0) && (east==1 && west == 1)) {
		cout << "NO" << endl;
		return;
	}

	int h_ns = min(south, north);
	int h_ew = min(west, east);

	int nn = north / 2;
	int ns = south / 2;
	int ne = east / 2;
	int nw = west / 2;
	if (north % 2) {
		nn++;
		ns++;
	}
	if (east % 2) {
		ne++;
		nw++;
	}

	string ans = "";
	for (auto si : s) {
		if (si == 'N') {
			if (nn > 0) ans.push_back('R');
			else ans.push_back('H');
			nn--;
		} else if (si == 'W') {
			if (nw > 0) ans.push_back('H');
			else ans.push_back('R');
			nw--;
		} else if (si == 'E') {
			if (ne > 0) ans.push_back('H');
			else ans.push_back('R');
			ne--;
		} else if (si == 'S') {
			if (ns > 0) ans.push_back('R');
			else ans.push_back('H');
			ns--;
		}
	}

	cout << ans << endl;

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