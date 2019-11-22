#include<iostream>
#include<algorithm>
using namespace std;

struct infinite_HW
{
    long long due_t;
    long long work_t;

    bool operator<(const infinite_HW &a)
    {
        if(due_t == a.due_t)
            return work_t < a.work_t;
        return due_t < a.due_t;
    }
};

int main()
{
    long long size_order;
    cin>>size_order;

    infinite_HW A[size_order];
    for(int i = 0 ; i < size_order ; i++)
    {
        cin>>A[i].due_t>>A[i].work_t;
    }

    sort( A , A + size_order);
/*
    for(int i = 0 ; i < size_order ; i++)
    {
            cout<<A[i].due_t<<" "<<A[i].work_t<<endl;
    }
*/
    long long accumu_t = 0;
    long long work_load = 0;

    for(int j = 0 ; j < size_order ; j++)
    {
        if( A[j].due_t - accumu_t >= A[j].work_t)
        {
            accumu_t += A[j].work_t;
            work_load++;
        }
        if(accumu_t > A[size_order - 1].due_t)
            break;
    }
    cout<<work_load<<endl;

    return 0;
}
