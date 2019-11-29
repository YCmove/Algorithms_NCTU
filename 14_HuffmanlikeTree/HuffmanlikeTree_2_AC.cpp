#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
 
    int n;
    long long x ;
    cin >> n;
   
    vector<int> nums;
    for(int i = 0 ;i <n;i++){
        cin >> x;
        nums.push_back(x);
    }
    priority_queue<long long , vector<long long>, greater<long long> > huff(nums.begin() , nums.end());
   
    while(huff.size( ) > 1){
        long long num1 = huff.top() ;
        huff.pop();
        long long num2 = huff.top() ;
        huff.pop();
        // In the problem with increase in distance of 1 unit,
        // the overall weighted length will become twice, that's why multiplied by 2 here
        huff.push(2*(num1+num2));
    }
    cout << huff.top();
}