#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    map<string,bool>in;

    int bfs(queue<string>& q,  map<string,int>& m1, map<string,int>& m2) {
        int cnt = q.size();
        while (cnt--) {
            string s = q.front();
            q.pop();

            int cn = m1[s];
            for (int i = 0; i < s.size(); ++i) {
                char t = s[i];
                for (int j = 0; j < 26; ++j) {
                    s[i] = 'a' + j;
                    cout << s << endl;
                    if (m2.find(s) != m2.end()) return cn + m2[s];//另一个已经搜索到
                    //第一个没有搜素过
                    if (m1.find(s) == m1.end() && in[s]) {
                        cout << s << endl;
                        m1[s] = cn + 1; 
                        q.emplace(s);
                    }
                }
                s[i] = t;
            }
        }
        return -1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<string>qs,qa;
        map<string,int>ms,ma;

        for (int i = 0; i < wordList.size(); ++i) {
            in[wordList[i]] = 1;
        }

        if (!in[endWord]) return 0;

        ms[beginWord] = 0;
        qs.emplace(beginWord);

        ma[endWord] = 0;
        qa.emplace(endWord);

        while (!qs.empty() && !qa.empty()) {
            int t;
            if (qs.size() < qa.size()) {
                t = bfs(qs, ms, ma);
            }else {
                t = bfs(qa, ma, ms);
            }
            if(t != -1) return t;
        }

        return 0;

    }
    
};
int main(){
    string st = "hit",end = "cog";
    vector<string>wordList{"hot","dot","dog","lot","log","cog"};
    Solution a;
    a.ladderLength(st,end,wordList);
    return 0;
}

