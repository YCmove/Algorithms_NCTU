#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;
int n;
const int N=32000;
struct node{
	int l,r;
	int cnt;
}tree[4*N+1];
int ans[N]={0};
int read() 			
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9')	{if(ch=='-')	f=-1;	ch=getchar();}
	while(ch>='0' && ch<='9')	{x=x*10+ch-'0';	ch=getchar();}
	return x*f;
}
int cnt=0;
void sum(int k,int x,int y)//求区间和模板
{
	if(tree[k].l>=x && tree[k].r<=y)
	{
		cnt+=tree[k].cnt;
		return ;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid)	sum(2*k,x,y);
	if(y>mid)		sum(2*k+1,x,y);
}
void updata(int k,int x)
{
	if(tree[k].l==tree[k].r)
	{
		tree[k].cnt++;
		return ;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(x<=mid)	updata(2*k,x);
	else				updata(2*k+1,x);
	tree[k].cnt=tree[2*k+1].cnt+tree[2*k].cnt;//一定要更新回去啊！！！
}
void build(int k,int l,int r)
{
	tree[k].l=l,tree[k].r=r;
	if(l==r)	return;
	int mid=(l+r)>>1;
	build(2*k,l,mid);
	build(2*k+1,mid+1,r);
}
int main()
{
	/*
	freopen("stars.in","r",stdin);
	freopen("stars.out","w",stdout);
	*/
	n=read();
	int maxx=INT_MIN;
	vector<int> x;
	for(int i=1;i<=n;i++)
	{
		int tmp=read();
		x.push_back(tmp);
		maxx=max(maxx,tmp);
		tmp=read();//读掉纵坐标
	}
	build(1,0,maxx);
	for(int i=0;i<n;i++)
	{
		cnt=0;//有多少个覆盖点，每次都要重置一次，好像可以放进递归的函数参数里面
		sum(1,0,x[i]);//求0~x的区间和（找有多少个覆盖点）
		ans[cnt]++;//累入答案
        // cout << "(" << x << ", " << y << ") - " << "p:" << p << endl;

		updata(1,x[i]);//更新叶节点
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	//cout<<endl<<(double)clock()/CLOCKS_PER_SEC<<"s";
	return 0;
}