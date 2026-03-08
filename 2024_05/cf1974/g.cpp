// g.cpp
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
#include <queue>


using namespace std;

typedef long long i64;

const int inf = 0x3f3f3f3f;
// memset(a, 0x3f, sizeof(a))

void solve() {
	int m, x;
	cin >> m >> x;
	priority_queue<int> q;
	i64 balance = 0;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int c;
		cin >> c;
		q.push(c);
		balance-=c;

		if (balance < 0) {
			balance += 	q.top();
			q.pop();
			++ans;
		}
		balance += x;

	}
	cout << q.size() << endl;

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