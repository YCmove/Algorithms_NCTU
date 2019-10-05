#include <iostream>
#include <vector>

using namespace std;


void print_vec(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void print_nest_vec(vector<vector<int> > vec){
    int size = vec.size();
    // cout << "size: " << size << endl;
    for (int i = 0; i < size; i++){
        cout << "[ ";
        for (auto it = vec[i].begin(); it != vec[i].end(); it++){
            cout << *it << " ";
        }
        cout << "]";
    }
}

void recur(int total, int i, int six, vector<int> & selected, vector<int> & all){
    if (selected.size() == 6){
        // cout << "滿了 印出結果" << endl;
        print_vec(selected);
        // selected.clear();
        return;
    }

    for (i; total - i + 1 > six; i++){
        // cout << "i: " << i << endl;
        // cout << "all[i]: " << all[i] << endl;
        selected.push_back(all[i]);
        recur(total, i + 1, six - 1, selected, all);
        selected.pop_back();
    }
}


int main(){
    int n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        vector<int> all;
        vector<int> selected;

        for (int i = 0 ; i < n; i++){
            int num;
            cin >> num;
            all.push_back(num);
        }

        // cout << "========" << endl;
        // print_vec(all);
        // cout << "start permutation" << endl;

        int start = 0;
        int six = 6;
        // int total = all.size();
        recur(n, start, six, selected, all);


        cout << endl;
    }

    return 0;
}