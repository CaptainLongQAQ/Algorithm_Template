#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod;

ll euler_phi(ll n) {
  ll m = ll(sqrt(n + 0.5));
  ll ans = n;
  for (ll i = 2; i <= m; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
long long fpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b%2==0){
            b/=2;
            a=a*a%mod; 
        }else{
            ans=ans*a%mod; 
            b--;
        }
    } 
    return ans%mod;
}
signed main(){
    ll a, m;
    cin >> a >> m;
    string s;
    cin >> s;
    ll phy = euler_phi(m);
    ll sum = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); ++i) {
        sum = sum * 10 + s[i] - '0';
        if (sum >= phy) flag = true,sum %= phy;
    }
    if (flag) sum += phy;
    mod = m;
    cout << fpow(a, sum) << endl;
    return 0;
}