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
	/* 
	r_dk: rect of k^th reservation on day 'd'
	a_dk: area of desired rect on day 'd' k^th reservation
	b_dk: area of r_dk
	l_d:  length of removal on day d

	area cost: 100 * (a_dk - b_dk) * bool(a_dk > b_dk)
	removal cost: 
	*/
	int w, D, N;
	cin >> w >> D >> N;
	vector<vector<int>> a(D, vector<int>(N));
	for (auto& a_d : a) {
		for (auto& a_dk : a_d) {
			cin >> a_dk;
		}
	}
    return;
}

void dummy_output() {
	int w, D, N;
	cin >> w >> D >> N;
	vector<vector<int>> a(D, vector<int>(N));
	for (auto& a_d : a) {
		for (auto& a_dk : a_d) {
			cin >> a_dk;
		}
	}
	int x = sqrt(N-1) + 1;
	int lx = w / x;
	int y = N / x + 1;
	int ly = w / y;
	i64 score = 0;
	i64 area = lx * ly;
	for (int d = 0; d < D; ++d) {
		for (int ix = 0; ix < x; ++ix) {
			for (int iy = 0; iy < y; ++iy) {
				if (ix * y + iy < N) {
					cout << ix * (w / x) << " " 
					<< iy * (w/y) <<  " "
					<< (ix+1) * (w/x) << " "
					<< (iy + 1) * (w / y) << endl;
					score += ((a[d][ix * y + iy] - area) * 100 * int(a[d][ix * y + iy] > area)); 
				}
			}
		}
	}
	score = score + w * (x) + w * (y) - (w - x * (y-1)) * (x*y-N) - (w - x * (N - (x-1) * y));
	cout << "score: " << score << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    dummy_output();
}