#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve(vector<int> &prime) {
    int n;
    cin >> n;
    int low = 0; int high = 2e3;
    int m = -1;
    while(high-low > 1) {
        int mid = (high + low + 1) / 2;
        int cap = (mid % 2 == 0) ? (mid * (mid + 1) / 2 - (mid-2) / 2) : (mid * (mid + 1) / 2);
        if (cap >= (n-1)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    m = high;
    // cout << m << endl;
    vector<unordered_set<int>> g(m);
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            g[i].insert(j);
            g[j].insert(i);
        }
    }

    if (m % 2 == 0) {
        for (int i = 2; i < m; i+=2) {
            g[i].erase(i+1);
            g[i+1].erase(i);
        }
    }

    vector<int> ans;
    stack<int> st;
    st.push(0);
    // dfs
    while(!st.empty()) {
        int v = st.top();
        if (g[v].empty()) {
            ans.push_back(v);
            st.pop();
        } else {
            int u = *g[v].begin();
            st.push(u);
            g[v].erase(u);
            g[u].erase(v);
        }
    }
    reverse(all(ans));
    int c = 0, d = 0;
    vector<bool> viewed(m, false);
    while( c < n ) {
        cout <<   prime[ans[d]] << " ";
        ++c;
        if (!viewed[ans[d]] && c < n) {
            cout << prime[ans[d]] << " ";
            viewed[ans[d]] = true;
            ++c;
        }
        ++d;
    }
    cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = 3e5;
    int x = 2;
    vector<int> prime({1});
    while(x < N) {
        bool flag = true;
        for (int j = 2; j <= sqrt(x); ++j) {
            if (x % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            prime.push_back(x);
        }
        ++x;
    }

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(prime);
    }
}