
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 999999
//这道题目很巧妙，首先是根据x的增长来的，然后再根据y的增长来排的； 
//所以这样就能理解为什么每次就只要求x之前的就好了 
int c[maxn];
int levels[maxn];
int lowbit(int x){
	return x&(-x);
}
//这里是对前x进行求和； 
int sum(int x){
	int res=0;
	while(x>0){	//注意这里是x>0,不能写成x>=0; 
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
//这里的目的是给下标为pos的加上1,这样的话下次询问前面的就能够累加上去了； 
void update(int pos){
	while(pos<=32001){
		c[pos]++;
		pos+=lowbit(pos);
	}
}
int main(){
	int n,x,y;
	while(~scanf("%d",&n)){
		memset(levels,0,sizeof(levels));
		int tt=n;
		while(tt--){
			scanf("%d%d",&x,&y);
			levels[sum(x+1)]++;
			update(x+1);
		}
		for(int i=0;i<n;i++) printf("%d\n",levels[i]);
	}

    return 0;
}