// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
vector<int> tolist(int x) {
	vector<int> ans(31, 0);
	for (int i = 0; i < 31; ++i) {
		ans[i] = (int)(!(((1 << i) & x) == 0));
	}
	// for (auto ai : ans) cout << ai << " "; cout << endl;
	return ans;
}
template <typename T>
ostream& operator << (ostream &os, vector<T> a) {
	for (auto & ai : a) os << ai << " ";
}


void solve() {
	int n ;
	// cout << "go\n";
	cin >> n;
	vector<int> a(n);
	input(a);
	// for (auto &ai : a ) cout << ai << " "; cout << endl;

	vector<pair<int,int>> b;
	for (int i = 0; i < n; ++i) {
		if (a[i]!=-1) {
			b.push_back({i, a[i]});
		}
	}
	if (b.empty()) {
		for (int i = 0; i < n; ++i) {
			cout << (1 + (i % 2)) << " ";
		} cout << endl;
		return;
	}
	for (int i = 0; i < b.size()-1; ++i) {
		int pi = b[i].first; int pv = b[i].second;
		int qi = b[i+1].first; int qv = b[i+1].second;
		auto p_bin = tolist(pv);
		auto q_bin = tolist(qv);
		int qj=0, pj=0;
		for (int j = 30; i >= 0; --j) {
			if (p_bin[j]==1) {
				pj = j; break;
			}
		}
		for (int j = 30; i >= 0; --j) {
			if (q_bin[j]==1) {
				qj = j; break;
			}
		}
		int l = 0;
		while(l <= min(pj, qj) && p_bin[pj-l]==q_bin[qj-l]) {
			l++;
		} --l;
		// cout << pi << " " << pj << " " << l << endl;
		int d = pj + qj - l * 2;
		if (qi - pi < d || (qi -pi -d) % 2 == 1) {
			cout << (-1) << endl;
			// cout << l << " " << pj << endl;
			return;
		}

		for (int j = 1; j <= pj-l; ++j) {
			a[pi + j] = (pv >> j);
		}
		for (int j = 1; j <= qj - l; ++j) {
			a[qi - j] = (qv >> j);
		}
		for (int j = 1 + pi + pj - l; j < qi - (qj-l); j += 2) {
			// cout << j;
			if (a[j-1]==1) {
				a[j] = 2;
				if(a[j+1]==-1) a[j+1] = 1;
			} else { 
				a[j] = (a[j-1] >> 1);
				if (a[j+1]==-1) a[j+1] =(a[j] << 1);
			}
		}
	}
	int ib = b.front().first;
	for(;ib>=1;--ib) {
		if (a[ib]==1) {
			a[ib-1]=2;
		} else {
			a[ib-1]=a[ib]/2;
		}
	}
	ib=b.back().first;
	for (;ib<=n-2;++ib) {
		if (a[ib]==1) {
			a[ib+1] = 2;
		} else {
			a[ib+1] = a[ib] /2;
		}
	}
	for (auto &ai : a ) cout << ai << " "; cout << endl;
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