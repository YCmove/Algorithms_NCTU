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



// 用 BST 做 Sorting, 長出一個歪斜數（左傾）
// 然後把所有node(除了leaf) 的 sum 加起來



int main(){
    int n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        priority_queue<int, std::vector<int>, std::greater<int> > q;
 
        for (int i = 0 ; i < n; i++){
            int num;
            cin >> num;
            q.push(num);
        }

        print_queue(q);

    }

    return 0;
}
