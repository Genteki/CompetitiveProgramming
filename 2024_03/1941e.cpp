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


int cal_min_row_cost(vector<int> &depth, int m, int k) {
	vector<vector<int>> cost(m, vector<int>(m, inf));
	for (int i = 0; i < m - 1; ++i) {
		for (int j = i + 1; j < min(m, j + k + 1); ++j) {
			cost[i][j] = depth[j] + 1;
		} 
	}
	for (int l = k + 1; l < m; ++l) {
		for (int i = 0; i < m - k; ++i) {
			for (int j = i + l + 1; j < m; ++j) {
				for (int p = i + 1; p < j; ++p) {
					if (cost[i][p] + cost[p][j] < cost[i][j]) {
						cost[i][j] = cost[i][p] + cost[p][j];
					}
				}
			}
		}
	}
	return cost[0][m-1] + depth[0] + 1;
}


void solve() {
	int n,m,k,d;
	cin >> n >> m >> k >> d;
	vector<vector<int>> depth(n, vector<int>(m, 0));
	for (auto & depthi : depth) {
		for (auto & depthij : depthi) {
			cin >> depthij;
		}
	}
	vector<int> min_row_cost(n);
	for (int i = 0; i < n; ++i) {
		min_row_cost[i] = cal_min_row_cost(depth[i], m, d);
		cout << min_row_cost[i] << " ";
	} cout << endl;

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