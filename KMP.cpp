#include <bits/stdc++.h>


using namespace std;
using ll = long long;


const int N = 2e5 + 10;

const ll mod = 1e9 + 7;

int k, n;

using pll = pair<int,int>;

const int L = 1e6 + 10;

char s[L], p[L];

void solve() {
    scanf("%s", s + 1);
    scanf("%s", p + 1);
    s[0] = p[0] = '0';
    int m = strlen(p) - 1, n = strlen(s) - 1;
    int ne[m + 1];
    ne[0] = ne[1] = 0;
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++j;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (p[j + 1] == s[i]) ++j;
        if (j == m) cout << i - j + 1 << endl;
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


