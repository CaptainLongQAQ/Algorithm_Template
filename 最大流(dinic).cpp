#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 210;
const int mod = 1e9 + 7;

using i_128 = __int128;

int m, n, k, t, s;

using pll = pair<ll,int>;

int idx = 1;

struct {
    ll v, c, ne;
}e[20100];

int h[N]; // 出边编号
int d[N]; // u 点的图层
int pre[N]; // u 点的当前出边编号
int cur[N];

void add(int u, int v, int w) {
    e[++idx] = {v, w, h[u]};
    h[u] = idx;
}

bool bfs() {
    memset(d, 0, sizeof d);
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            int v = e[i].v;
            if (!d[v] && e[i].c) {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}

ll dfs(int u, ll mf) {
    if (u == t) return mf;
    ll sum = 0;// 累加u 流出流量的总和
    for (int i = cur[u]; i; i = e[i].ne) {
        cur[u] = i;
        int v = e[i].v;
        if (d[v] == d[u] + 1 && e[i].c) {
            ll f = dfs(v, min(e[i].c, mf));
            e[i].c -= f;
            e[i ^ 1].c += f;
            sum += f;
            mf -= f;
            if (mf == 0) break;
        }
    }
    if (sum == 0) d[u] = 0;
    return sum;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        memcpy(cur, h, sizeof h);
        flow += dfs(s, 1e9);
    }
    return flow;
}


void solve() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    cout << dinic() << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
//    cin >> t;
//    while (t--) solve();
    return 0;
}