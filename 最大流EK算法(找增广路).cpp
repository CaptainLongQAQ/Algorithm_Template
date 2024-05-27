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
ll mf[N]; // 流量上限
int pre[N]; // v 的前驱边的编号



void add(int u, int v, int w) {
    e[++idx] = {v, w, h[u]};
    h[u] = idx;
}

bool bfs() {
    memset(mf, 0, sizeof mf);
    mf[s] = 1e9;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i; i = e[i].ne) {
            ll v = e[i].v;
            if (!mf[v] && e[i].c) {
                mf[v] = min(e[i].c, mf[u]);
                pre[v] = i;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}

ll EK() {
    ll flow = 0;
    while (bfs()) {
        ll v = t;
        while (v != s) {
            int i = pre[v];
            // 更新残余网
            e[i].c -= mf[t];
            e[i ^ 1].c += mf[t];
            v = e[i ^ 1].v;
        }
        flow += mf[t]; // 累加可行流
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
    cout << EK() << endl;
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