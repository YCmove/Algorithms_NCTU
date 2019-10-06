// https://blog.csdn.net/ShellDawn/article/details/89029536


#include <bits/stdc++.h>
using namespace std;


const int maxn = 1000000;
int segtree[maxn];

void segadd(int now,int l,int r,int loc,int key){
    if(l>=r-1){
        segtree[now] = max(segtree[now],key);
        return ;
    }
    segtree[now] = max(segtree[now],key);
    int mid = (l+r+1)/2;
    if(loc < mid) segadd(now*2+1,l,mid,loc,key);
    else segadd(now*2+2,mid,r,loc,key);
}

int segfind(int now,int l,int r,int L,int R){
    if(l == L && r == R){
        return segtree[now];
    }
    int MID = (L+R+1)/2;
    if(l < MID && r > MID)
    {
        return max(segfind(now*2+1,l,MID,L,MID),segfind(now*2+2,MID,r,MID,R));
    }   
    if(r <= MID){
        return segfind(now*2+1,l,r,L,MID);
    }else{
        return segfind(now*2+2,l,r,MID,R);
    }
}

vector<int> maxInWindows(const vector<int>& num, unsigned int size){
    int l = num.size();
    if(size <= 0 ) return *(new vector<int>);
    memset(segtree,0x80,sizeof(segtree));
    for(int i=0;i<l;i++) segadd(0,0,l,i,num[i]);
    vector<int> ans;
    for(int i=0;i+size<=l;i++) ans.push_back(segfind(0,i,i+size,0,l));
    return ans;
}

int main(){
    vector<int> input;
    int inputa[] = {2,3,4,2,6,2,5,1};
    for(int i=0;i<8;i++) input.push_back(inputa[i]);
    vector<int> output = maxInWindows(input,3);
    for(int i=0;i<output.size();i++) printf("<<%d>> ",output[i]);
    printf("\n");
    return 0;
}