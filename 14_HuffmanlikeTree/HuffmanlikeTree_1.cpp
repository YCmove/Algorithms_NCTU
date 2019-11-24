#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int n;

template<class T> void print_arr(T* arr, int n) {
    for (int i = 0; i < n; ++i){
        // cout << arr[i] << " ";
        cout << "arr[" << i << "]:" << arr[i].weight << ",   ";
    }
    cout << '\n';
}

struct Leaf {
    int symbol, weight;
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


int main(){
    cin >> n;
    // Leaf tree[n];
    priority_queue<Leaf, vector<Leaf>, comp> pq;

    int w;
    rep(i, n){
        cin >> w;
        Leaf l;
        l.symbol = i;
        l.weight = w;
        pq.push(l);
        // tree[i].symbol = i;
        // tree[i].weight = w;
    }

    // sort(tree, tree+n, comp);
    // print_arr(tree, n);

    while(!pq.empty()) {
        Leaf value = pq.top();
        pq.pop();
        cout << value.weight << " ";
    }





    return 0;
}