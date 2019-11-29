#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define lowbit(x) ((x)&(-x))
int n;

template<class T> void print_arr(T* arr, int n) {
    for (int i = 0; i < n; ++i){
        // cout << arr[i] << " ";
        cout << "arr[" << i << "]:" << arr[i].weight << ",   ";
    }
    cout << '\n';
}

struct Leaf {
    int symbol, weight, width;
    bool operator<(const Leaf &o) const
    {
        return weight < o.weight;
    }
};

// bool comp(const Leaf a, const Leaf b){
//     return a.weight < b.weight;
// }

struct comp
{
    bool operator()(const Leaf & a, const Leaf & b)
    {
        return a.weight > b.weight;;
    }
};

// Smallest power of 2 in binary representation of number x
// void min_width(int num){
//     bitset<10> b(num); //convent number into bit array
//     cout << num << " binary is " <<  b << endl;
//     return;
// }



int main(){
    cin >> n;
    // Leaf tree[n];
    priority_queue<Leaf, vector<Leaf>, comp> pq;

    int w;
    rep(i, n){
        cin >> w;
        Leaf l;
        l.symbol = i;
        l.width = pow(2, i);
        l.weight = w;
        pq.push(l);
        // min_width(w);
        cout << "w = " << w << " / lowbit=" << lowbit(w) << endl;
        // tree[i].symbol = i;
        // tree[i].weight = w;
    }

    // sort(tree, tree+n, comp);
    // print_arr(tree, n);

    int d, r;
    while(!pq.empty()) {
        Leaf node = pq.top();
        cout << node.weight << " ";
        d = lowbit(node.weight);
        r = pow(2, d);

        if ()



        pq.pop();
    }





    return 0;
}