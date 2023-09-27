//数组写法
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

class Trie {
public:
    int index = 0;
    int son[100010][26]={0};
    int cnt[100010]={0};

    void insert(string& forbidden){
        int p = 0;
        for(int j = 0; j < forbidden.size(); ++j){
            int u = forbidden[j] - 'a';
            if(!son[p][u]){
                son[p][u] = ++index;
            }
            p = son[p][u];
        }
        ++cnt[p];
    }
    int check(string& s){
        int p = 0;
        for(int i = 0; i < s.size(); ++i){
            int u = s[i] - 'a';
            if(!son[p][u]){
                return 0;
            }
            p = son[p][u];
        }
        return cnt[p];
    }
};

//指针写法
struct node{
    node* next[26];
    int have;
};
//初始化每个节点
class Trie{
private:
    node* head;
public:
    Trie() {
        head = new node;
        init(head);
    }
    void init(node* h){
        for(int i = 0; i < 26; ++i) h->next[i] = nullptr;
        h->have = 0;
    }
    //插入字符串
    void insert(string& forbidden){
        node* p = head;
        for(int j = 0; j < forbidden.size(); ++j){
            int u = forbidden[j] - 'a';
            if(!p->next[u]){
                p->next[u] = new node; //创建节点
                init(p->next[u]);
            }
            p = p->next[u];
        }
        p->have = 1;
    }
    //求字符串的个数
    int check(string& s){
        node* p = head;
        for(int i = 0; i < s.size(); ++i){
            int u = s[i] - 'a';
            if(!p->next[u]) return 0;
            p = p->next[u];
        }
        return p->have;
    }
};
