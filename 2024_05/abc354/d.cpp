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
int s0[] = {2, 1, 0, 1};
int s1[] = {1, 2, 1, 0};
void solve() {
	i64 a,b,c,d;
	cin >> a >> b >> c >> d;
	i64 h = (d - b) / 2 * 2;
	i64 w = (c - a) / 4 * 4;
	i64 da = c - w -a ;
	i64 db = d- b-h;
	i64 a2 = a%4+4;
	i64 b2 = b%2+2;
	i64 s = 0;
	for (i64 i = 0; i < da; ++i) {
		s = s + (s0[(a2+i)%4]+s1[(a2+i)%4])* h/2;
		if (db == 2) {
			s = s + s0[(a2+i)%4] + s1[(a2+i)%4];
		} else if (db == 1) {
			if (b2 %2 == 0) {
				s = s + s0[(a2+i)%4];
			} else {
				s = s  + s1[(a2+i)%4];
			}
		}
	}
	s += (w * db);
	s += w * h;
	cout << s << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
}