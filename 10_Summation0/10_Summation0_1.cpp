#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

// ll min_sum(ll arr[], ll n)
// {
//         ll cout_a, cout_b, min_sum;
//         cout_a = arr[n-1]; // 最後一個 Max
//         cout_b = arr[n-2]; // 倒數第二個

//         int i = n - 3;

//         while(i >= 0){
//             if(cout_a > cout_b){ 
//                 cout_b = cout_b + arr[i];
        //     } else {
        //         cout_a = cout_a + arr[i];
        //     }
        //     i--;
        // }

        // if(cout_a > cout_b){
        //     min_sum = cout_a - cout_b;
        // } else {
        //     min_sum = cout_b - cout_a;
        // }
//         // cout << "min_sum: " << min_sum << endl;

//         return min_sum ;
// }


int canPartition(vector<int>& nums, int total_sum) {
    const int MAX_NUM = 300;
    const int MAX_ARRAY_SIZE = 500;
    bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
    int sum = 0;
    for (auto n : nums) {
        sum += n;
        bits |= bits << n;
    }
    if (!(sum % 2) && bits[sum / 2]){
        cout << "equal partition" << endl;
        return 0;
        // cout << "0" << endl;
    } 
    else {
        int diff = INT_MAX; 
        cout << "total_sum: " << total_sum << endl;
      
        // Find the largest j such that dp[n][j] 
        // is true where j loops from sum/2 t0 0 
        for (int j = total_sum/2; j>=0; j--) 
        { 
            cout << "j: " << j << endl;
            // Find the  
            if (!(total_sum % 2) && bits[total_sum / 2])
            // if (dp[n][j] == true) 
            { 
                cout << "diff: " << diff << endl;
                diff = total_sum-2*j; 
                break; 
            } 
        } 
        return diff; 
    }

    return !(sum % 2) && bits[sum / 2];
}


// Returns the minimum value of the difference of the two sets. 
int findMin(int arr[], int n) 
{ 
    // Calculate sum of all elements 
    int sum = 0;  
    for (int i = 0; i < n; i++) 
        sum += arr[i]; 
  
    // Create an array to store results of subproblems 
    bool dp[n+1][sum+1]; 
  
    // Initialize first column as true. 0 sum is possible  
    // with all elements. 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // Initialize top row, except dp[0][0], as false. With 
    // 0 elements, no other sum except 0 is possible 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    // Fill the partition table in bottom up manner 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            // If i'th element is excluded 
            dp[i][j] = dp[i-1][j]; 
  
            // If i'th element is included 
            if (arr[i-1] <= j) 
                dp[i][j] |= dp[i-1][j-arr[i-1]]; 
        } 
    } 
   
    // Initialize difference of two sums.  
    int diff = INT_MAX; 
      
    // Find the largest j such that dp[n][j] 
    // is true where j loops from sum/2 t0 0 
    for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 
  

int main(){
    int n;
    int total_sum = 0;

    while (cin >> n){
        // int arr[n];
        vector<int> arr;

        for (int i = 0 ; i < n; i++){
            int a;
            cin >> a;
            arr.push_back(a);
            total_sum += a;
            // arr[i] = a;
        }
        
        // if (n == 1){
        //     cout << arr[0] << endl;
        //     return 0;
        // } 

        // sort(arr, arr + n);


        cout << canPartition(arr, total_sum) << endl;
        // cout << findMin(arr, n) << endl;

    }

}