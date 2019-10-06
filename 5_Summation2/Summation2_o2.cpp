// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space

#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}



// 用 BST 做 Sorting, 長出一個歪斜數（左傾）
// 然後把所有node(除了leaf) 的 sum 加起來

int mctFromLeafValues(vector<int>& arr) {
    vector<int>adj[16];
    int n= arr.size();
    
    for(int i=0;i<n;i++)
        adj[arr[i]].push_back(i);
    
    int left[n];
    for(int i=0;i<n;i++)left[i]=i-1;
    int right[n];
    for(int i=0;i<n;i++)right[i]=i+1;
    
    int ans=0;
    
    for(unsigned int i=1;i<=15;i++){
        for(unsigned int j=0;j<adj[i].size();j++){
            int id= adj[i][j]; // index id in our array arr, global minimum
            int next_greater=0; // minimum element between their neighbor (first check if they are valid)
            if(left[id]==-1 && right[id]!=n){
                next_greater=arr[right[id]];
            }else if(left[id]!=-1 && right[id]==n){
                next_greater=arr[left[id]];
            }else if(left[id]!=-1 && right[id]!=n){
                next_greater=min(arr[left[id]],arr[right[id]]);
            }
            
            //delete index id in our Linked list
            if(right[id]!=n)
                left[right[id]]= left[id];
            if(left[id]!=-1)
                right[left[id]]= right[id];
                
            // ans+=next_greater + i;
            ans+=next_greater*i;
        }
    }
    
    return ans;
}

int main(){
    int n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        vector<int> all;

        for (int i = 0 ; i < n; i++){
            int num;
            cin >> num;
            all.push_back(num);
        }

        print_vec(all);
        cout << mctFromLeafValues(all) << endl;
    }

    return 0;
}
