#include<bits/stdc++.h>
long long work(long long p,long long q)//求出值为p/q的点的编号
{
	long long a,k,ans;
	if(p==1&&q==1)
	return 1;
	if(p==0||q==0)
	return 1;
	if(p>q)//右儿子
	{
		k=p/q;
		if(p%q==0)//到达根节点时，特判，下同
		k--;
		a=work(p%q,q);
		ans=pow(2,k)*a+pow(2,k)-1;//找规律
		return ans;
	}
	else if(p<q)//左儿子
	{
		k=q/p;
		if(q%p==0)
		k--;
		a=work(p,q%p);
		ans=pow(2,k)*a;//找规律
		return ans;
	}

    return 0;
}


int main()
{
	long long t,p,q,a;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld/%lld",&a,&p,&q);
		printf("%lld %lld\n",a,work(p,q));
	}
	return 0;
}