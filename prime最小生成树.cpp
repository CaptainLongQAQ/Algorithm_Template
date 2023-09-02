#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;
//Prime求最小生成树
int n;
const int N = 1010,inf = 0x3f3f3f3f;
int dis[N];
bool st[N];
int grd[N][N];

int prime() {
    memset(dis,0x3f,sizeof dis);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
        }
        if (i && dis[t] == inf) return inf;
        res += dis[t];
        st[t] = true;
        for (int j = 1; j <= n; ++j) {
            dis[j] = min(dis[j],grd[t][j]);
        }
    }
    return res;
}


//Kruskal算法

struct Edge{
    int a,b,w;
    bool operator< (Edge & t) {
        return w < t.w;
    }
}edge[N];
int p[N];
int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int kruscal(int n,int m) {
    sort(edge, edge + m);
    for (int i = 1; i <= n; ++n) {
        p[i] = i;
    }
    int cnt = 0, res = 0;
    for (int i =0; i < m; ++i) {
        int a = edge[i].a,b = edge[i].b;
        a = find(a),b = find(b);
        if (a != b) {
            ++cnt;
            res += edge[i].w;
            p[a] = b;
        }
    }
    if (cnt < n - 1) {
        cout << "imposible" << endl;
    }else{
        cout << res << endl;
    }
}