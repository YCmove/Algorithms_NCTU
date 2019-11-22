#include<iostream>
using namespace std;

int main()
{
    int amount,time_lim;
    cin>>amount>>time_lim;
    int value[amount];
    int weight[amount];
    int cost[time_lim + 1] = {0};
    // find all kinds of optimal case at every state (time limit)

    for(int i = 0 ; i < amount ; i++)  // enter each assignment's score & required time
    {
        cin>>value[i]>>weight[i];
    }

    for(int i = 0 ; i < amount ; i++)  // test each of the assignment in order
    {
        int value_cur = value[i];
        int weight_cur = weight[i];
        for(int j = time_lim ; j - weight_cur >= 0 ; j--)
        {  // test from the largest backpack , before reach the max weight it can put
            cost[j] = max(cost[j],cost[j-weight_cur]+value_cur);
           // not put or put
        }
    }

    cout<<cost[time_lim]<<endl;

    return 0;
}
