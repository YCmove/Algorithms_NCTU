#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
#define ll long long
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        ll Array[N];
        for(int i=0;i<N;i++){ cin>>Array[i];}
        ll Biggest=Array[0];
        int coin=1;
        for(int i=1;i<N-1;i++){
            if (Biggest+Array[i]<Array[i+1]){
                Biggest+=Array[i];
                coin++;
            }
        }
        coin++;
        cout<<coin<<endl;
    }
    return 0;
}