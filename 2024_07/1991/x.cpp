#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<bool> generatePrimes(int limit) {
    vector<bool> prime(limit + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= limit; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

bool isBipartite(int n, const vector<bool>& primes, vector<int>& colors) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= n; ++v) {
                    if (u != v && primes[u ^ v]) {
                        if (colors[v] == -1) {
                            colors[v] = 1 - colors[u];
                            q.push(v);
                        } else if (colors[v] == colors[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> testCases(t);
    int maxN = 0;
    for (int i = 0; i < t; ++i) {
        cin >> testCases[i];
        maxN = max(maxN, testCases[i]);
    }

    // Generate all primes up to 2 * maxN
    int limit = 2 * maxN;
    vector<bool> primes = generatePrimes(limit);

    for (int n : testCases) {
        vector<int> colors(n + 1, -1);
        if (isBipartite(n, primes, colors)) {
            cout << 2 << endl;
            for (int i = 1; i <= n; ++i) {
                cout << colors[i] + 1 << " ";
            }
            cout << endl;
        } else {
            cout << 3 << endl;
            for (int i = 1; i <= n; ++i) {
                cout << (i % 3) + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}