#include<bits/stdc++.h>

using namespace std;
const int K = 26;
struct TrieNode {
    int next[K];
    vector<int> output;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    TrieNode(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), - 1);
    }
};

struct AhoCorasick {
    vector<TrieNode> t;
    vector<bool> lazy;
    AhoCorasick() { t = vector<TrieNode>(1, TrieNode(-1)); }

    void add_string(const string& s, int idx) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch);
            }
            v = t[v].next[c];
        }
        t[v].output.push_back(idx);
    }

    void reset_lazy() {
        lazy.assign(t.size(), true);
    }

    int go(int v, char ch) {
        int c = ch - 'a';
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1) {
                t[v].go[c] = t[v].next[c];
            } else {
                t[v].go[c] = (v == 0 ? 0 : go(get_link(v), ch));
            }
        }
        return t[v].go[c];
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0) 
                t[v].link = 0;
            else 
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }
};

int main() {
    string t;
    cin >> t;
    int n = t.size();
    int m;
    cin >> m;
    AhoCorasick trie;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        trie.add_string(s, i);
    } 
    trie.reset_lazy();
    vector<int> appeared(m, 0);
    int v = 0;

    for (int i = 0; i < n; ++i) {
        v = trie.go(v, t[i]);
        int u = v;
        while(trie.lazy[u] == true) {
            if (!trie.t[u].output.empty()) {
                for (auto oi : trie.t[u].output) {
                    appeared[oi] = true;
                }
            }
            trie.lazy[u] = 0;

            u = trie.get_link(u);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (appeared[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}