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


//bellman_ford处理负权边单源路最短路问题
//n表示有n个顶点
//k表示源点到终点最多有k条边
//m表示有m条边
int k,n,m;

const int N = 1000;
const int M = 10000;
struct Edge{
    int a,b,v;
}edge[M];

int dij[N],backup[N];
bool st[N];


int bell_ford(int start, int end){
    memset(dij,0x3f,sizeof dij);
    dij[start] = 0;
    for(int i = 0; i < k; ++i){
        memcpy(backup,dij,sizeof dij);//防止串联的情况,不拷贝就不能保证是第i次条边
        for(int j = 0; j < m; ++j){
            int a = edge[j].a,b = edge[j].b,v = edge[j].v;
            dij[b] = min(dij[b],backup[a] + v);
        }
    }
    if(dij[n] > 0x3f3f3f3f / 2)return -1;//不存在
    return dij[n];
}
int main(){
    cin >> n >> k >> m;
    for(int i = 0; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].v;
    }
    cout << bell_ford(1,n);
    return 0;
}

//SPFA是bellman的优化
//处理负权边单源路最短路问题没有负环的图

vector<vector<pair<int,int>>>gra;

bool have[N];

int spfa(){
    memset(dij,0x3f,sizeof dij);
    queue<int>q;
    dij[1] = 0;
    have[1] = true;
    q.push(1);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        have[t] = false;
        for(int j = 0; j < gra[t].size(); ++j){
            if(dij[t] + gra[t][j].second < dij[gra[t][j].first]){
                dij[gra[t][j].first] = dij[t] + gra[t][j].second;
                if(!have[gra[t][j].first]){
                    q.push(gra[t][j].first);
                    have[gra[t][j].first] = true;
                }
            }
        }
    }
    if(dij[n] == 0x3f3f3f3f)return -1;
    return dij[n];
    
}

int SPFAS(){

    //zhiyaonaxiegengixnge
    memset(dij,0x3f,sizeof dij);
    dij[1] = 0;
    queue<int>q;
    q.push(1);
    have[1] = true;
    while(q.size()){
        int t = q.front();
        q.pop();
        have[t] = false;
        for(int i = 0; i < gra[t].size(); ++i){
            if(dij[gra[t][i].first] > dij[t] + gra[t][i].second){
                dij[gra[t][i].first] = dij[t] + gra[t][i].second;
                if(!have[gra[t][i].first]){
                    q.push(gra[t][i].first);
                    have[gra[t][i].first] = true;
                }
            }
        }
    }
    if(dij[n] == 0x3f3f3f3f)return -1;
    return dij[n];
}
