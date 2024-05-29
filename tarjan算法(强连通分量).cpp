#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

using i_128 = __int128;

int m, n, k, s;

using pll = pair<int, int>;


vector<int> g[N];

int dfn[N]; // 访问时间戳
int low[N]; // 追溯值，从x出发 能访问到的最早时间戳
int tot;
int stk[N], instk[N], top;
// 每个点属于哪个强连通分量
int scc[N], siz[N], cnt;

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y : g[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) { // x 是根
        int y;
        ++cnt;
        do {
            y = stk[top];
            --top;
            instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(y != x);
    }
}

void solve() {
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    vector<int> du(n + 2, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++du[v];
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!scc[i]) tarjan(i);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
//    int t;
//    cin >> t;
//    while (t--) solve();
    return 0;
}