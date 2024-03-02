
/*
 Z函数 ：意义是每个位置i和 S串的最长公共前缀

*/

vector<int> get_z(string s) {
    int n = s.size();
    vector<int> z(n + 1, 0);
    string w;
    w += 'a';
    w += s;
    z[1] = n;
    for (int i = 2, l, r = 0; i <= n; ++i) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (w[z[i] + 1] == w[i + z[i]]) ++z[i];
        if (z[i] + i >= r) l = i, r = i + z[i] - 1;
    }
    return z;
}