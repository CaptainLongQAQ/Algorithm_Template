class BitTree{
public:
    vector<int> tree;
    // 传参 n : 为数组长度+1, 树状数组默认从下标1开始
    BitTree(int n): tree(n, 0){

    }
    int low_bit (int x) {return x & -x;}
    // 求前缀和 [1, x]
    int add (int x) {
        int res = 0;
        while (x) {
            res += tree[x];
            x -= low_bit(x);
        }
        return res;
    }

    void insert (int x, int k) {
        while (x < tree.size()) {
            tree[x] += k;
            x += low_bit(x);
        }
    }
};
