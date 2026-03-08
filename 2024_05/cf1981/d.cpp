// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

// template <typename T>
// ostream& operator << (ostream &os, vector<T> a) {
//     for (auto & ai : a) os << ai << " ";
// }

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve(const vector<int> &l) {
	int n;
	cin >> n;
	int m = (n + 1) / 2;
	int i = 0;
	while(i < n) {
		cout << l[i]
	}
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> a(600000,0);
    int x = 1, i = 0;
    while(i < a.size()) {
    	x++;
    	if (x == pow((int)sqrt(x), 2)){
    		x++;
    	}
    	a[i] = x;
    }
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(a);
    }
}