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

const int N = 10000;
bool have[N];
int dij[N];//最短距离
int gr[N][N];//图
int nn;//图的点数
//点i到n的最小距离
//朴素迪杰斯特拉算法求稠密图单源点到指定点的最小距离
//i表示起点, n表示目的点
int dijistra(int i, int n){
    memset(dij,0x3f,sizeof dij);
    dij[i] = 0;
    for(int i = 0; i < nn; ++i){
        int t = -1;
        //每次选择最短的且未确定的最短路
        for(int j = 1; j <= nn; ++j){
            if(!have[j] && (t == -1 || dij[t] > dij[j]))
                t = j;
        }
        if(t == n) break;
        have[t] = true;
        //由当前点更新到每个点的距离
        for(int j = 1; j <= nn; ++j){
            dij[j] = min(dij[j],dij[t] + gr[t][j]);
        }
    }
    if(dij[n] == 0x3f3f3f3f) return -1;

    return dij[n];
}

//堆优化版缔结斯塔拉算法求稀疏图单源点到指定点的最小距离
//存储图---邻接表
//vector<vector<pair<int,int>>>gra;//存储图
//i --> n的最小距离
vector<vector<pair<int,int>>>gra;
int dijiestra(int i,int n,vector<vector<pair<int,int>>>&gra){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    memset(dij,0x3f,sizeof dij);
    dij[i] = 0;
    pq.push({0,i});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();

        int pos = t.second,dis = t.first;

        if(have[pos]) continue;
        have[pos] = true;
        
        for(int i = 0; i < gra[pos].size(); ++i){
            if(dij[gra[pos][i].first] > dis + gra[pos][i].second){
                dij[ gra[pos][i].first ] = dis + gra[pos][i].second;
                pq.push({dij[ gra[pos][i].first ], gra[pos][i].first});
            }
        }
    }
    if(dij[n] == 0x3f3f3f3f) return -1;
    return dij[n];
}


int main(){
    int i ;
    cin >> nn >> i;
    vector<vector<pair<int,int>>>gra(nn + 1);
    memset(gr,0x3f,sizeof gr);
    while(i--){
        int a,b,v;
        cin >>  a >> b >> v;
        gr[a][b] = min(gr[a][b],v);
        gra[a].push_back({b,v});
    }
    cout << dijistra(1,2) << endl; 
    cout << dijiestra(1,nn,gra);
    return 0;
}


