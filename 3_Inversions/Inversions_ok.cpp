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

void merge(vector<long long> & vec, long long begin, long long mid, long long end, long long & inv){

    // create 2 array
    long long n1 = mid - begin + 1;
    long long n2 = end - mid;
    vector<long long> arr1;
    vector<long long> arr2;
    for (long long i = 0; i < n1; i++){
        arr1.push_back(vec[begin + i]);
    }
    for (long long j = 0; j < n2; j++){
        arr2.push_back(vec[mid + j + 1]);
    }
    // arr1[n1 + 1] = INT8_MAX;
    // arr2[n2 + 1] = INT8_MAX;
    // cout << "\n--- print_vec ---" << endl;
    // cout << "arr1: ";
    // print_vec(arr1);
    // cout << "arr2: ";
    // print_vec(arr2);

    long long i = 0; // index on arr1(left array)
    long long j = 0; // index on arr2(right array)
    long long k = 0;
    // long long inversions = 0;
    // cout << "[" << arr1[i] << ", " << arr2[j] << "]  ";

    // use k to re-assign origin vector
    for(long long k = begin; k <= end; k++) {
        if (i == n1) {
            // end of arr1
            vec[k] = arr2[j++];

        } else if (j == n2) {
            // end of arr2
            vec[k] = arr1[i++];

        // put smaller one into vec[k]
        } else if (arr1[i] <= arr2[j]) {
            // no inversion happen
            vec[k] = arr1[i++];

        } else {
            vec[k] = arr2[j++];
            inv += n1 - i;

        }
    }
}

void merge_sort(vector<long long> & v, long long begin, long long end, long long & inv){
    if (end == 0){
        return;
    }
    if (begin < end) {
        long long mid = floor((begin + end) / 2);
        // cout << "begin: " << begin << " / mid: " << mid << " / end: " << end << endl;

        // cout << "--- left array ---" << endl;
        merge_sort(v, begin, mid, inv);
        // cout << "--- right array ---" << endl;
        merge_sort(v, mid + 1, end, inv);
        // cout << "--- merge left and right ---" << endl;
        merge(v, begin, mid, end, inv);
        // cout << "left: " << left << " / right: " << right << " / inversions:" << inversions << endl;
    } 
    else {
        return;
    }
}




long long inversions = 0;

int main(){
    long long n;

    while (cin >> n){

        if (n == 0){
            return 0;
        }

        vector<long long> all;

        for (long long i = 0 ; i < n; i++){
            long long num;
            cin >> num;
            all.push_back(num);
        }

        // print_vec(all);
        
        merge_sort(all, 0, all.size()-1, inversions);
        // cout << "inversions: " << inversions << endl;
        // cout << "========" << endl;

        // cout << inversions << endl;
        cout << inversions % 524287 << endl;


        // cout << endl;
    }

    return 0;
}

