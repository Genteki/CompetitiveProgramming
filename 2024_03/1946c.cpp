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

struct node {
	vector<int> sons;
	int parent;
	int size;
	node() {size = 1; sons = {};}
};

int recur_tree_size(int n, vector<node>& nodes) {
	if ((nodes[n].sons).size() == 0) {
		nodes[n].size = 1;
		return 1;
	}
	for (auto si : nodes[n].sons) {
		nodes[n].size += recur_tree_size(si, nodes);
	}
	// cout << n << ":" << nodes[n].size << endl;
	return nodes[n].size;
}

void remove_node(vector<node>&nodes, int s, int k, int &tot) {
	int n = s;
	while (nodes[n].size() {
		
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<node> nodes(n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		nodes[u-1].sons.push_back(v-1);
		nodes[v-1].parent = u-1;
	}
	recur_tree_size(0, nodes);
	cout << nodes[0].size << endl;
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