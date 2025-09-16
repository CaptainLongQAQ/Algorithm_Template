#include <bits/stdc++.h>


using namespace std;
using ll = long long;


const int N = 500010;

const ll mod = 1e9 + 7;

int k, n, m;

using pll = pair<int,int>;

vector<int> g[N];
int dep[N];
int fa[N][20];

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    for (int i = 1; i <= 19; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = 0; i < g[u].size(); ++i) if (g[u][i] != f) dfs(g[u][i], u);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    // 把 u 调到 v 同层
    for (int i = 19; i >= 0; --i) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    // 调到公共祖先节点的下一层
    for (int i = 19; i >= 0; --i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}


void solve() {
    int s;
    cin >> n >> m >> s;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(s, 0);

    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
//    int t;
//    cin >> t;
//    while (t--) solve();
    return 0;
}
