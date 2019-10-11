#include <functional>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}


int main(){
    long long n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }


 
        for (long long i = 0 ; i < n; i++){
            long long a, b, c, d;
            // Root Node: (a,b)
            cin >> a >> b >> c >> d;
        }


        // cout << "Final Cost: " << cost << endl;
        // cout  << cost % 524287 << endl;


    }

    return 0;
}
