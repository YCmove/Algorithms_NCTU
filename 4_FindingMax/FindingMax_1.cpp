#include <iostream>
#include <vector>

using namespace std;

// STNode: Segment Tree Node
struct STNode{
    int start;
    int end;
    long long max;
    STNode * left;
    STNode * right;
    STNode(int s, int e):start(s),end(e),max(0),left(nullptr),right(nullptr){};
};


class STree{
public:
    STree(vector<long long> & arr);
    void createSTree(vector<long long> & arr);
    long long modify(int i, long long val);
    long long find_max(int i, int j);

private:
    STNode * root;
};

STree::STree(vector<long long> & arr){
    createSTree(0, arr.size()-1, arr);
}

// long long STree::

// long long


void print_vec(vector<long long> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int main(){
    int n_num, m_queries;

    while (cin >> n_num >> m_queries){

        if (n_num == 0){
            return 0;
        }

        vector<long long> all;

        for (int i = 0 ; i < n_num; i++){
            long long num;
            cin >> num;
            all.push_back(num);
        }

        for (int p = 0 ; p < m_queries; p++){
            int i, j, k;
            cin >> i >> j >> k;
            if (i == 1){
                // modify num[j] to k.
                // all[j] = k;
                cout << endl;

            } else {
                // i == 2
                // output the maximum element between indices j and k.
                cout << endl;
            }
        }

        print_vec(all);

    }

    return 0;
}
