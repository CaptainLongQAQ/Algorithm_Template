class LCA{
private:
    const static int N = 500010;
    vector<int> g[N];
    int dep[N];
    int fa[N][20];
    int n;
    void dfs(int u, int f) {
        dep[u] = dep[f] + 1;
        fa[u][0] = f;
        for (int i = 1; i <= 19; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = 0; i < g[u].size(); ++i) if (g[u][i] != f) dfs(g[u][i], u);
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        // 把 u 调到 v 同层
        for (int i = 19; i >= 0; --i) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        if (u == v) return u;
        // 调到公共祖先节点的下一层
        for (int i = 19; i >= 0; --i) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
        return fa[u][0];
    }
public:
    LCA(int n, vector<vector<int>> grid) {
        for (int i = 0; i < grid.size(); ++i) {
            g[grid[i][0]].push_back(grid[i][1]);
            g[grid[i][1]].push_back(grid[i][0]);
        }
        this->n = n;
        dep[0] = 0;
        dfs(1, 0);
    }
};
