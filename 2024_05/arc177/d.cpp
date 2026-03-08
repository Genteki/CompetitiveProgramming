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

const i64 module = 998244353;
const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int n; i64 h;
	cin >> n >> h;

	vector <i64> prob_list(n+1);
	prob_list[n] = 1;
	for (int i = 0; i < n; ++i) {
		prob_list[n - 1 - i] = (prob_list[n-i] * 2) % module;
	}

	vector<i64> x(n);
	map<i64, int> mpx;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		mpx[x[i]] = i;
	}

	vector<i64> y = x;
	sort(y.begin(), y.end());
	map<i64, int> mpy;
	for (int i = 0; i < n; ++i) {
		mpy[y[i]] = i;
	}
	map<string, i64> prob;
	string status(n, '0');
	string done(n, '1');
	string init_prob(n, '0');
	init_prob[0] = 1;
	prob.insert(pair<string, i64>(status, 1));
	for (int i = 0; i < n; ++i) {
		map<string, i64> new_prob;
		i64 p = 0;
		i64 pos = x[i];
		int x_pos = mpy[pos];
		int left = x_pos, right = x_pos;

		while (right < n-1 && y[right+1] - y[right] <= h) {
			right++;
		}
		while (left > 0 && y[left] - y[left - 1] <= h) {
			left--;
		}
		for (auto & probi : prob) {
			string left_s = probi.first, right_s = probi.first;
			fill(left_s.begin() + left, left_s.begin() + x_pos + 1, '1');
			fill(right_s.begin() + x_pos, right_s.begin() + right + 1, '1');
			// cout << left << " " << i << " ";
			// cout << left_s << " " << right_s << endl;
			if (left_s == done) p = (p + probi.second) % module;
			else new_prob[left_s] = (new_prob[left_s] + probi.second) % module;
			if (right_s == done) p = (p + probi.second) % module;
			else new_prob[right_s] = (new_prob[right_s] + probi.second) % module;
		}

		cout << ((p << (n - 1 - i)) % module) << " ";
		prob = new_prob;
	}
	
    return;
}

void solve2() {
	int n; i64 h;
	cin >> n >> h;
	if (n == 1) cout << "2\n";
	vector <i64> prob_list(n+1);
	prob_list[n] = 1;
	for (int i = 0; i < n; ++i) {
		prob_list[n - 1 - i] = (prob_list[n-i] * 2) % module;
	}

	vector<i64> x(n);
	unordered_map<i64, int> mpx;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		mpx[x[i]] = i;
	}

	vector<i64> y = x;
	sort(y.begin(), y.end());
	unordered_map<i64, int> mpy;
	for (int i = 0; i < n; ++i) {
		mpy[y[i]] = i;
	}


	// split them into subproblems
	vector<vector<int>> sub_problems;
	int q = 0;
	vector<int> new_problem;
	while (q < n) {
		if (new_problem.empty()) {
			new_problem.push_back(mpx[y[q]]);
			++q;
		}
		else if (y[q] - y[q-1] <= h) {
			new_problem.push_back(mpx[y[q]]);
			++q;
		} else {
			sub_problems.push_back(new_problem);
			new_problem = {};
		}
	}
	if (!new_problem.empty()) sub_problems.push_back(new_problem);

	for (auto & problem : sub_problems) {
		for (int i = 0; i < problem.size(); ++i) {
			int p = problem[i];
			int r = 0;
			for (int j = 0; j < p; ++j) {
				if (problem[j] < p) {
					r++;
				}
			}
			for (int j = p+1; j < problem.size(); ++j) {
				if (problem[j] < p) {
					r++;
				}
			}
		}
	}	
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve2();
}