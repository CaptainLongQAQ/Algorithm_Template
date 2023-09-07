#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

//SPFA是bellman的优化
//处理负权边单源路最短路问题没有负环的图，但可有负权边


const int N = 1010;
int dij[N];
bool have[N];
using pll = pair<int,int>;
vector<vector<pll>>g;
int SPFA(int start, int end) {
    memset(dij, 0x3f, sizeof dij);
    memset(have, 0, sizeof have);
    dij[start] = 0;
    have[start] = 1;
    queue<int>q;
    q.emplace(start);
    while (!q.empty()) {
        int t = q.front();
        have[t] = false;
        q.pop();
        for (int i = 0; i < g[t].size(); ++i) {
            if (dij[t] + g[t][g[t][i].second] < dij[g[t][i].first]) {
                dij[g[t][i].first] = dij[t] + g[t][g[t][i].second];
                if (!have[g[t][i].first]) {
                    q.emplace(g[t][i].first);
                    have[g[t][i].first] = 1;
                }
            }
        }
    }
    if(dij[end] > 0x3f3f3f3f / 2)return -1;
    return dij[end];
}

int main(){
    
    return 0;
}

