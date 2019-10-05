#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void print_vec(vector<long long> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// void print_nest_vec(vector<vector<long long> > vec){
//     long long size = vec.size();
//     // cout << "size: " << size << endl;
//     for (long long i = 0; i < size; i++){
//         cout << "[ ";
//         for (auto it = vec[i].begin(); it != vec[i].end(); it++){
//             cout << *it << " ";
//         }
//         cout << "]";
//     }
// }

long long merge(vector<long long> & vec, long long begin, long long mid, long long end){

    // create 2 array
    long long n1 = mid - begin + 1;
    long long n2 = end - mid;
    vector<long long> arr1;
    vector<long long> arr2;
    for (long long i = 0; i < n1; i++){
        arr1.push_back(vec[begin + i - 1]);
    }
    for (long long j = 0; j < n2; j++){
        arr2.push_back(vec[mid + j]);
    }
    arr1[n1 + 1] = INT8_MAX;
    arr2[n2 + 1] = INT8_MAX;

    long long i = 1;
    long long j = 1;
    long long inversions = 0;

    for (long long k = begin; k <= end; k++){
        if (arr1[i] > arr2[j]){
            inversions = inversions + n1 - i + 1;
            vec[k] = arr2[j];
            j = j + 1;
        } else if (vec[k]==arr2[j]){
            i = i + 1;
        }
    }
    return inversions;
}

long long merge_sort(vector<long long> & v, long long begin, long long end){
    if (begin < end) {
        long long mid = floor((begin + end) / 2);
        // cout << "begin: " << begin << endl;
        // cout << "end: " << end << endl;
        // cout << "--------" << endl;
        long long left = merge_sort(v, begin, mid);
        long long right = merge_sort(v, mid + 1, end);
        long long inversions = merge(v, begin, mid, end) + left + right;
        // cout << "left: " << left << " / right: " << right << " / inversions:" << inversions << endl;
        return inversions;
    } else {
        return 0;
    }
}






int main(){
    long long n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        vector<long long> all;
        vector<long long> selected;

        for (long long i = 0 ; i < n; i++){
            long long num;
            cin >> num;
            all.push_back(num);
        }

        // print_vec(all);
        long long inversions = merge_sort(all, 0, all.size());
        // cout << "inversions: " << inversions << endl;
        // cout << "========" << endl;

        cout << inversions << endl;
        // cout << inversions % 524287 << endl;


        // cout << endl;
    }

    return 0;
}

