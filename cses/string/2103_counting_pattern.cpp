#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

const int K = 26;
struct TrieNode {
    int next[K];
    int output = 0;
    vector<int> dict;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    TrieNode(int p = -1, char pch = '$') : p(p), pch(pch) {
        std::fill(begin(next), end(next), -1);
        std::fill(begin(go), end(go), -1);
    }
};

struct AhoCorasick {
    vector<TrieNode> nodes;
    AhoCorasick() {
        nodes = vector<TrieNode>(1);
    }
    void add_string(const string& s, const int & idx = 0) {
        int v = 0;
        for (auto & si : s) {
            int k = si - 'a';
            if (nodes[v].next[k] == -1) {
                nodes[v].next[k] = nodes.size();
                nodes.emplace_back(v, si);
            }
            v = nodes[v].next[k];
        }
        nodes[v].output = 1;
        nodes[v].dict.push_back(idx);
    }

    int go(int v, char ch) {
        int k = ch - 'a';
        auto & node = nodes[v];
        if (node.go[k] == -1) {
            if (node.next[k] != -1) {
                node.go[k] = node.next[k];
            } else {
                node.go[k] = v == 0 ? 0 : go(get_link(v), ch);
            }
        }
        
        return node.go[k];
    }

    int get_link(int v) {
        auto & node = nodes[v];
        if (node.link == -1) {
            if (v == 0 || node.p == 0) {
                node.link = 0;
            } else {
                node.link = go(get_link(node.p), node.pch);
            }
        }
        return node.link;
    }
};

void solve() {
    string t;
    cin >> t;
    int m;
    cin >> m;
    AhoCorasick trie;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        trie.add_string(s, i);
    }
    int v = 0;
    vector<int> cnt(trie.nodes.size(), 0);
    for (auto ti : t) {
        v = trie.go(v, ti);
        cnt[v]++;
    }
    vector<int> ans(m, 0);
    
    queue<int> q;
    q.push(0);
    vector<int> order;
    while(!q.empty()) {
        int qi = q.front();
        if (cnt[v]) order.push_back(q.front());
        q.pop();
        for (auto v : trie.nodes[qi].next) {
            if (v != -1) {
                q.push(v);
            }
        }
    }

    reverse(all(order));
    for (auto i : order) {
        int li = trie.get_link(i);
        cnt[li] += cnt[i];
    }

    for (int v = 0; v < trie.nodes.size(); ++v) {
        if (cnt[v]) {
            auto output = trie.nodes[v].dict;
            for (auto oi : output) {
                ans[oi] = cnt[v];
            }
        }
        
    }
    for (auto ai : ans) {
        cout << ai << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}