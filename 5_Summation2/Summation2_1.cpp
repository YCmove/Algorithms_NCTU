#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
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

    }

    return 0;
}
