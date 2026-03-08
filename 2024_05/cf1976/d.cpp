// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;
template<typename T>
ostream& operator << (ostream& os, const vector<T> & a) {
	for (auto & ai : a) os << ai << " ";
	return os;
}

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int n;
	string s;
	cin >> s;
	n = s.size();

	stack<int> st;
	vector<int> left(n, 0), right(n, 0);
	// vector<vector<pair<int,int>>> m(n, vector<pair<int,int>>(n, {0,0}));
	for (int i = 0; i < n; ++i) {
		// cout << i << ' ';x
		if (st.empty()) {
			st.push(s[i]);
		} else {
			if (st.top() != s[i]) {
				st.pop();
			} else {
				st.push(s[i]);
			}
		}
		left[i] = st.size();
		// cout << s.size() << endl;
	}
	st = stack<int>();
	for (int i = n-1; i >= 0; --i) {
		if (st.empty()) {
			st.push(s[i]);
		} else {
			if (st.top() != s[i]) {
				st.pop();
			} else {
				st.push(s[i]);
			}
		}
		right[i] = st.size();
	}
	// cout << left << endl << right << endl;
	i64 ans = 0;
	for (int i = 1; i < n-1; ++i) {
		stack<char> sti;
		int q = 0;
		for (int j = i; j < n-1; j++) {
			if (sti.empty()) {
				sti.push(s[j]);
				if (s[j] == '(') q=1;
			} else {
				if (sti.top()==')' && s[j] == '(') {
					sti.pop();
				} else {
					sti.push(s[j]);
					if (s[j] == '(') q++;
				}
			}
			// cout << " " << q << " " << (sti.size()-q) << " " << left[i-1] << " " << right[j+1] << endl;
			if(q <= left[i-1] && (sti.size()-q)<=right[j+1] && left[i-1]==right[j+1]) {
				ans++;
			}						
		}
	}
	cout << ans << endl;

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