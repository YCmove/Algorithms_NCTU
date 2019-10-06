// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space

#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}



// 用 BST 做 Sorting, 長出一個歪斜數（左傾）
// 然後把所有node(除了leaf) 的 sum 加起來

int mctFromLeafValues(vector<int>& A) {
    int res = 0;
    // int n = A.size();
    vector<int> stack = {INT8_MAX};
    for (int a : A) {
        while (stack.back() <= a) {
            int mid = stack.back();
            stack.pop_back();
            // res += mid + min(stack.back(), a);
            res += mid * min(stack.back(), a);
        }
        stack.push_back(a);
    }
    for (unsigned int i = 2; i < stack.size(); ++i) {
        // res += stack[i] + stack[i - 1];
        res += stack[i] * stack[i - 1];
    }
    return res;
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
        cout << mctFromLeafValues(all) << endl;
    }

    return 0;
}
