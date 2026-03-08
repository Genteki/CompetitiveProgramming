#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

struct Info{
    i64 val, a, b, c;
    Info(i64 a, i64 b, i64 c, auto&& f) : a(a), b(b), c(c) {
        val = f(a,b,c);
    }
    friend bool operator <(const Info& a, const Info& b) {return a.val < b.val; }
    friend bool operator >(const Info& a, const Info& b) {return a.val > b.val; }
    
};

void solve() {
    i64 n;
    i64 k;
    cin >> n >> k;

    vector<i64> A(n), B(n), C(n);
    for (i64 i = 0; i < n; i++) cin >> A[i];
    for (i64 i = 0; i < n; i++) cin >> B[i];
    for (i64 i = 0; i < n; i++) cin >> C[i];

    sort(A.begin(), A.end(), greater<i64>());
    sort(B.begin(), B.end(), greater<i64>());
    sort(C.begin(), C.end(), greater<i64>());

    auto f = [&](i64 i, i64 j, i64 k) -> i64 {
        return A[i] * B[j] + B[j] * C[k] + C[k] * A[i];
    };
    priority_queue<Info> pq;
    --k;
    set<i64> st;
    auto g = [&](i64 a, i64 b, i64 c) {
        i64 idx = a * n * n + b * n  + c;
        if (a < n and b < n and c < n and st.find(idx) == st.end()) {
            pq.emplace(a,b,c,f);
            st.emplace(idx);
        }
    };
    g(0,0,0);
    while(k) {
        auto x = pq.top();
        pq.pop();
        g(x.a+1,x.b,x.c);
        g(x.a, x.b+1, x.c);
        g(x.a, x.b, x.c+1);
        --k;
    }
    cout << pq.top().val << endl;
}
    

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases = 1;
    while (test_cases--) {
        solve();
    }
    return 0;
}