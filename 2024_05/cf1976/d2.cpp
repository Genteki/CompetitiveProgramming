// d2.cpp
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
	vector<int> left(n, 0), right(n, 0), rleft(n, 0), rright(n,0);
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
	cout << left << endl << right << endl;
	i64 ans = 0;
	// st = stack<int>();
	// for (int i = 0; i < n; ++i) {
	// 	int q = 0;
	// 	if (st.empty()) {
	// 		st.push(s[i]);
	// 		q++;
	// 	} else {
	// 		if (st.top()==')' && s[i] =='(') {
	// 			st.pop();
	// 		} else {
	// 			st.push(s[i]);
	// 			if (s[i]=='(') q++;
	// 		}
	// 	}
	// 	rleft[i] = q;
	// }

	// st = stack<int>();
	// for (int i = n-1; i >= 0; --i) {
	// 	int q = 0;
	// 	if (st.empty()) {
	// 		st.push(s[i]); q++;
	// 	} else {
	// 		if (st.top()=='(' && s[i] == ')') {
	// 			st.pop();
	// 		} else {
	// 			st.push(s[i]);
	// 			if (s[i]==')') q++;
	// 		}
	// 	}
	// 	rright[i]=q;
	// }

	// cout << left << endl << right << endl << rleft << endl << rright << endl;
	for (int i = 1; i < n-1; ++i) {
		for (int j = i+1; j <n-1; j+=2) {
			if (left[i-1]==right[j+1] && left[i-1]*2 >= left[j] && right[j+1]*2 >= right[i]) {
				ans++;
				cout << '(' << (i+1) << ',' << (j+1) << ')' << endl;
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