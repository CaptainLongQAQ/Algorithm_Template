#include <bits/stdc++.h>


using namespace std;
using ll = long long;


const int N = 2e5 + 10;

const ll mod = 1e9 + 7;

//ll k, n, x, m;

using pll = pair<int,int>;

class BitTree{
public:
    vector<ll> tree;
    // 传参 n : 为数组长度+1, 树状数组默认从下标1开始
    BitTree(int n): tree(n, 0){

    }
    ll low_bit (ll x) {return x & -x;}
    // 求前缀和 [1, x]
    ll query (int x) {
        ll res = 0;
        while (x) {
            res += tree[x];
            x -= low_bit(x);
        }
        return res;
    }

    void add (ll x, ll k) {
        while (x < tree.size()) {
            tree[x] += k;
            x += low_bit(x);
        }
    }
};

int a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    BitTree bt1(n + 1), bt2(n + 1);
    // d1   d2 - d1 + d3 - d2 + d2 - d1 +
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        bt1.add(i, a[i]);
        bt1.add(i + 1, -a[i]);
        bt2.add(i, a[i] * (i - 1));
        bt2.add(i + 1, -a[i] * i);
    }
    for (int i = 0; i < m; ++i) {
        ll x, y, k;
        int op;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            bt1.add(x, k);
            bt1.add(y + 1, -k);
            bt2.add(x, k * (x - 1));
            bt2.add(y + 1, -k * y);
        } else {
            cin >> x >> y;
            ll res = (bt1.query(y) * y - bt2.query(y)) - (bt1.query(x - 1) * (x - 1) - bt2.query(x - 1));
            cout << res << endl;
        }
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