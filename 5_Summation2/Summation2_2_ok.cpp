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

// 全部改成long long 就過了最後一個AC
// 可是int不是已經cover過10^5了嗎？

int main(){
    long long n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        priority_queue<long long, vector<long long>, greater<long long> > q;
 
        for (long long i = 0 ; i < n; i++){
            long long num;
            cin >> num;
            q.push(num);
        }

        // 踢掉只有一個input number的可能
        if (n == 1){
            return q.top(); // Cost就是自己
        }

        // print_queue(q);
        // cout << "queue size: " << q.size() << endl;
        long long cost = 0;
        // select two from priority queue, sum up
        while(q.size() > 1){
            long long sum = 0;
            // cout << "1st in queue: " << q.top() << endl;
            sum += q.top();
            q.pop();
            // cout << "2st in queue: " << q.top() << endl;
            sum += q.top();
            q.pop();

            // cout << "each sum: " << sum << endl;
            cost += sum;
            // cout << "Temp Cost: " << cost << endl;
            q.push(sum);
            // pop 兩個後, 在加上一個，最後可能剩下 2 or 1 個
            // (a) 2 個的話會繼續走while loop
            // (b) 1個的話就是代表加到底了
            // cout << "--------" << endl;
        }

        // cout << "queue size: " << q.size() << endl;
        // cout << "Last in queue: " << q.top() << endl;
        // cost += q.top(); 不需要再加了！

        // cout << "Final Cost: " << cost << endl;
        cout  << cost % 524287 << endl;


    }

    return 0;
}
