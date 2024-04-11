
 // 结构体版
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
#define lc p << 1
#define rc p << 1 | 1

ll w[N];

struct node {
    ll l, r, sum, add;
}tr[4 * N];

void pushup(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {
    if (tr[p].add) {
        // 左边
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
        tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}


void update(int p, int l, int r, int k) {
    if (l <= tr[p].l && r >= tr[p].r) {
        // 打烂标记
        tr[p].add += k;
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    pushdown(p);
    if (l <= mid) update(lc, l, r, k);
    if (r > mid) update(rc, l, r, k);
    pushup(p);
}

ll query(int p, int l, int r) {
    if (l > tr[p].r || r < tr[p].l) return 0;
    if (l <= tr[p].l && r >= tr[p].r) {
        return tr[p].sum;
    }
    ll res = 0;
    int mid = tr[p].l + tr[p].r >> 1;
    pushdown(p);
    if (l <= mid) res += query(lc, l ,r);
    if (r > mid) res += query(rc, l, r);
    return res;
}



int main(){
  int n,m,op,x,y,k;  
  cin>>n>>m;
  for(int i=1; i<=n; i ++) cin>>w[i];
  
  build(1,1,n);
  while(m--){
    cin>>op>>x>>y;
    if(op==2)cout<<query(1,x,y)<<endl;
    else cin>>k,change(1,x,y,k);
  }
  return 0;
}
