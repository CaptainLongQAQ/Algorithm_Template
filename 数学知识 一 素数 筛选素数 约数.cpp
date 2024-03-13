#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <unordered_set>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <climits>
using namespace std;
//素数
bool is_prime(int n){
    for(int i = 2; i <= n / i; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
//素数筛选
//1 -- n
const int N = 1000000;
int primes(int n){
    int have[N];
    int cnt = 0;
    memset(have,0,N);
    for(int i = 2;i <= n; ++i){
        if(!have[i]){
            ++cnt;
            for(int j = i + i; j <= n; j += i){
                have[i] = true;
            }
        }
    }
    return cnt;
}
//线性筛法
int primess(int n){
    bool vis[N];
    int cnt = 0;
    int num[N];
    memset(vis, 0, N);
    for(int i = 2;i <= n; ++i){
        if(!vis[i]) num[++cnt] = i;
        for(int j = 1; 1LL * i * num[j] <= n; ++j){
            have[num[j] * i] = true;
            if(i % num[j] == 0) break;
        }
    }
    return cnt;
}
//质因数分解
void divide(int n){
    int primes[N];
    int cnt[N];
    memset(cnt,0,sizeof cnt);
    int m = 0;
    for(int i = 2; i <= n / i; ++i){
        if(n % i == 0){
            primes[++m] = i;
            cnt[m] = 0;
            while(n % i == 0){
                ++cnt[m];
                n /= i;
            }
        }
    }
    if(n > 1){
        primes[++m] = n;
        cnt[m] = 1;
    }
}





//求约数
vector<int> yues(int n){
    vector<int>ans;
    for(int i = 1; i <= n /2 ; ++i){
        if(n % i == 0){
            ans.push_back(i);
            if(i != n / i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

//求约数的个数
const int MOD = 1e9+7;
int yueh(int n){
    //求n个数的乘积的个数
    unordered_map<int,int>p;
    while(n--){
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; ++i){
            while(x % i == 0){
                x /= i;
                ++p[i];
            }
        }
        if(x > 1) p[x]++;
    }
    long long ans = 1;
    for(auto pp : p){
        ans = ans * (pp.second + 1) % MOD;
    }
    cout << ans;
}
//求约数的和
int yuesum(int n){
    unordered_map<int,int>p;
    while(n--){
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; ++i){
            while(x % i == 0){
                x /= i;
                ++p[i];
            }
        }
        if(x > 1) p[x]++;
    }
    long long ans = 1;
    for(auto pp : p){
        int ps = pp.first,a = pp.second;
        int t = 1;
        for(int i = 0; i < a; ++i){
            t = (ps * t + 1) % MOD;
        }
    }
    cout << ans;
}
