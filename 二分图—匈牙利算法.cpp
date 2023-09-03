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