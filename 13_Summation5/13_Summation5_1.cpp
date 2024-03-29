#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i < n; ++i)
#define REP(i, n) for(int i=0; i <= n; ++i)

int n;


void Maximum_Sum_Subarray(int arr[],int n)		//Overall Time Complexity O(n^3)
{
	int ans = INT_MIN;		
    int start_index;
    int i;					// #include<climits>
	for(int sub_array_size = 1;sub_array_size <= n; ++sub_array_size)		//O(n)
	{
		for(start_index = 0;start_index < n; ++start_index)				//O(n)
		{
			if(start_index+sub_array_size > n)	//Subarray exceeds array bounds
				break;
			int sum = 0;
			for(i = start_index; i < (start_index+sub_array_size); i++)	//O(n)
				sum+= arr[i];
			ans = max(ans,sum);
		}
	}
	// return ans;
    cout << start_index-1 << " " << i-1 << endl;
}

int main(){
    cin >> n;
    int a;
    int arr[n];

    rep(i, n){
        cin >> a;
        arr[i] = a;
    }

    // int b = 0, sum=-1e10;
    // int x = 0, y = 0;

    Maximum_Sum_Subarray(arr, n);













    // int sum = 0;
    // int best = 0;
    // int x = 0;
    // int y = 0;
    // rep(i, n){
    //     cout << "i=" << i << " / arr[i]=" << arr[i] << " / sum+arr[i]=" << sum+arr[i]<< " / best=" << best << endl;
    //     sum = max(arr[i], sum+arr[i]);
    //     if (sum == arr[i]){
    //         x = i;
    //     }
    //     cout << "x=" << x << " / ";
    //     best = max(best, sum);
    //     if (best == sum){
    //         y = i;
    //     }
    //     cout << "y=" << y << endl;
    // }
    // cout << x << " " << y+1 << endl;
    // cout << best << endl;


    return 0;
}