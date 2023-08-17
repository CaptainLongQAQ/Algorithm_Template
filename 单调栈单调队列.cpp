
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
int main(){

//单调栈 —— 模板题 AcWing 830. 单调栈
//常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0,n;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[++tt] = i;
}

//单调队列 —— 模板题 AcWing 154. 滑动窗口
//常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;//队头队尾
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ; //判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}



    return 0;
}