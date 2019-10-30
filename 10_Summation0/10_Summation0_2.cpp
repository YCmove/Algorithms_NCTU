#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

  
int main(){
    int n;
    int total_sum = 0;

    while (cin >> n){
        int arr[n];
        // vector<int> arr;

        for (int i = 0 ; i < n; i++){
            int a;
            cin >> a;
            // arr.push_back(a);
            arr[i] = a;
            
            // 計算 total_sum
            total_sum += a;
        }

        // sort(arr, arr + n);

        // 建立dp table, 紀錄每一個subproblem array個合
        // total_sum夠小才能這樣開table array
        bool dp[n + 1][total_sum + 1];

        // init dp table
        for (int j = 0; j <= total_sum + 1;++j){
            dp[0][j] = false;
        }
        for (int i = 0; i <= n + 1;++i){
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= total_sum; j++) { 
                // i 不包含在內
                dp[i][j] = dp[i - 1][j]; 
    
                // i 包含在內 
                if (arr[i - 1] <= j) 
                    dp[i][j] |= dp[i - 1][j - arr[i - 1]]; 
            } 
        } 

        int distance = INT_MAX; 
      
        
        for (int j = total_sum / 2; j >= 0; j--){ 
            if (dp[n][j] == true){ 
                distance = total_sum - 2 * j; 
                break; 
            } 
        } 
        cout << distance << endl; 

    }

}