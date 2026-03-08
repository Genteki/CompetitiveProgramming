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

bool is_rep(string &s, char *sub, int lsub) {
	int wrong_count = 0;
	// cout << sub << endl;
	if (lsub == 1) {
		char c = s[0]; //cout << sub << endl;
		for (auto &si : s) {
			if (si != c) ++wrong_count;
		}
		
		if (wrong_count >= 2) {
			wrong_count = 0;
			c = s[1];
			// cout << c << endl;
			for (auto &si : s) {
				if (si != c) ++wrong_count;
				if (wrong_count >= 2) return false;
			}
		}
	} else {
		for (int i = 0; i < s.size(); ++i) {
			if (wrong_count > 1) return false;
			if (s[i] != sub[i%lsub]) {wrong_count+=1;
			// cout << "pos " << i << " " << s[i] << endl;
		}
		}
	}
	return wrong_count <= 1;
}

void solve() {
	int ls;
	string s;
	cin >> ls;
	cin >> s;
	bool r1 = is_rep(s, "temp", 1);
	if (r1) {cout << 1 << endl; return;}
	for (int lsub= 2; lsub <= ls / 2; ++lsub) {
		if (ls % lsub == 0) {
			char *sub;
			sub = new char[lsub];
			s.copy(sub, lsub, 0);
			bool rep = is_rep(s, sub, lsub);
			if (rep) {
				cout << lsub << endl;
				delete sub;
				return;
			}
			s.copy(sub, lsub, lsub);
			// cout << sub << "," << s << ": " << endl;
			rep = is_rep(s, sub, lsub);
			if (rep) {
				cout << lsub << endl;
				// cout << sub << endl;
				delete sub;
				return;
			}
			delete sub;
		}

	}
	cout << ls << endl;
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