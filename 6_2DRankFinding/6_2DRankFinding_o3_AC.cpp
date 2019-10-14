// https://blog.csdn.net/libin56842/article/details/14105099
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
 
const int maxn = 32000+10;

// left shift = (32000+10) * 2^k
int tree[maxn<<2], t, x, y, ans[maxn<<2];
 
// insert(0, maxn, 1);
void insert(int l, int r, int i)
{
    if(l == r)
        t+=tree[i];
    else
    {
        // >> 1 等同除以二(*1/2)
        int mid = (l + r) >> 1;
        if(x <= mid)
            // left child
            insert(l, mid, 2 * i);
        else
        {
            // right child
            t += tree[2 * i];//走右子树，则把左子树的所有星星数目加起来
            insert(mid+1, r, 2*i+1);
        }
    }
    tree[i]++;
}
 
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof(tree));
        memset(ans,0,sizeof(ans));
        for(i = 0; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            // t 是 layer index
            t = 0;

            insert(0, maxn, 1);

            // 每insert一個點，就會去他所在的layer更新(+1)
            ans[t]++;//等级个数
            cout << "(" << x << ", " << y << "): " << ans[t] << endl;
        }
        for(i = 0; i<n; i++)
            printf("%d\n",ans[i]);
    }
 
    return 0;
}