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
#include <queue>

using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))


vector<int> bfs(vector<vector<int>> &g, int a) {
	queue<pair<int,int>> q;
	q.push({a, 0});
	vector<int> distance(g.size(), -1);
	distance[a] = 0;
	while(!q.empty()) {
		auto qi = q.front();
		q.pop();
		int v = qi.first;
		for (int vi : g[v]) {
			if (distance[vi] == -1) {
				distance[vi] = qi.second + 1;
				q.push({vi, qi.second + 1});
			}
		}
	}
	return distance;
}

void solve() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	a--; b--;
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
	auto da = bfs(g, a);
	auto db = bfs(g, b);
	vector<int> dab(n, 0);
	int mp, md = inf;
	for (int i = 0; i < n; ++i) {
		int temp = max(da[i], db[i]);
		if (temp < md) {
			mp = i; md = temp;
		} else if (md == temp) {
			if (da[i] < db[i]) {
				mp = i;
			}
		}
	}
	auto dp = bfs(g, mp);
	int la = *max_element(da.begin(), da.end());
	int lp = *max_element(dp.begin(), dp.end());
	int ansa = da[b] + 2 *(n-1) - la;
	int ansp = md + 2 *(n-1) - lp;

	// for (auto dai : da) cout << dai << " "; cout << endl;
	// cout << ansa << ansp << endl;
	// cout << " " << md << " " << lp << endl;
 	cout << min(ansa, ansp) << endl;
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