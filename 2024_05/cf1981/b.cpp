// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

vector<int> tolist(i64 x) {
	vector<int> ans(64, 0);
	for (int i = 0; i < 64; ++i) {
		ans[i] = (int)(!((((i64)1 << i) & x) == 0));
	}
	// for (auto ai : ans) cout << ai << " "; cout << endl;
	return ans;
}

void solve() {
	i64 n, m;
	cin >> m >> n;

	if (n == 0) {
		cout << m << endl;
	} else {
		i64 p = m + n;
		i64 q = max((i64)0, m - n);
		vector<int> am = tolist(m);
		vector<int> ap = tolist(p);
		vector<int> aq = tolist(q);

		int x = 0; int y = 0;
		for (int i = 63; i >= 0; --i) {
			if (ap[i] == 1 && am[i] == 0) {
				x = i;
				break;
			}
		}
		for (int i = 63; i >= 0; --i) {
			if (aq[i] == 0 && am[i] == 1) {
				y = i;
				break;
			}
		}
		for (int i = x; i >= 0; --i) {
			am[i] = 1;
		}
		for (int i = y-1; i >=0; --i) {
			am[i] =1;
		}

		i64 ans = 0;
		// cout << x << " " << y << endl;
	// for (auto ai : am) cout << ai << " "; cout << endl;

		for (int i = 0; i < 63; ++i) {
			if (am[i]) {
				ans |= ((i64)1 << i);
			}
		}
		cout << ans << endl;
	}
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}