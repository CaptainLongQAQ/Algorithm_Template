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

// 染色法判断二分图
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>have(n + 1, 0);
        vector<vector<int>>g(n + 1,vector<int>());
        function<bool(int, int)>dfs = [&](int i, int co)->bool{
            have[i] = co;
            for (int j = 0; j < g[i].size(); ++j) {
                if (!have[g[i][j]]) {
                    if (!dfs(g[i][j], 3 - co)) return false;
                }else if(have[g[i][j]] == co){
                    return false;
                }
            }
            return true;
        };
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() && !have[i]) {
                if (!dfs(i,1)) {
                    return false;
                }
            }
        }
        return true;
    }
};


// 匈牙利算法--最大匹配项
//n1是二分图左边的点, n2是二分图右边的点
int n1, n2, m;
const int N = 510;
int match[N];
bool st[N];
vector<vector<int>>g(N,vector<int>());

bool find(int x) {
    for (int i = 0; i < g[x].size(); ++i) {
        if (!st[g[x][i]]) {
            st[g[x][i]] = true;
            if (match[g[x][i]] == 0 || find(match[g[x][i]])) {
                match[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    for (int i = 0 ; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        //n1 -> n2
        g[a].push_back(b);
    }
    int res;
    for (int i = 1; i <= n1; ++i) {
        memset(st, 0, sizeof st);
        if (find(i)) res++;
    }
    cout << res;
    return 0;
}