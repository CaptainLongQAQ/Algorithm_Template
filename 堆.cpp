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

//堆 —— 模板题 AcWing 838. 堆排序, AcWing 839. 模拟堆
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1

//小根堆
const int N = 10010;
int h[N];
int sizes,n;

//让大的点下沉
void down(int u)
{
    int t = u;
    if (u * 2 <= sizes && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= sizes && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}

//让点上升
void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        swap(h[u],h[u/2]);
        u >>= 1;
    }
}



int main(){
    // O(n)建堆
    for (int i = n / 2; i; i -- ) down(i);
    return 0;
}
