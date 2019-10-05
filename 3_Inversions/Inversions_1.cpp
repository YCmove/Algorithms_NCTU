#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void print_vec(vector<int> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// void print_nest_vec(vector<vector<int> > vec){
//     int size = vec.size();
//     // cout << "size: " << size << endl;
//     for (int i = 0; i < size; i++){
//         cout << "[ ";
//         for (auto it = vec[i].begin(); it != vec[i].end(); it++){
//             cout << *it << " ";
//         }
//         cout << "]";
//     }
// }

int merge(vector<int> & vec, int begin, int mid, int end){

    // create 2 array
    int n1 = mid - begin + 1;
    int n2 = end - mid;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = 0; i < n1; i++){
        arr1.push_back(vec[begin + i]);
    }
    for (int j = 0; j < n2; j++){
        arr2.push_back(vec[mid + j + 1]);
    }
    // arr1[n1 + 1] = INT8_MAX;
    // arr2[n2 + 1] = INT8_MAX;
    // cout << "\n--- print_vec ---" << endl;
    // cout << "arr1: ";
    // print_vec(arr1);
    // cout << "arr2: ";
    // print_vec(arr2);

    int i = 0; // index on arr1(left array)
    int j = 0; // index on arr2(right array)
    int k = 0;
    int inversions = 0;
    // cout << "[" << arr1[i] << ", " << arr2[j] << "]  ";

    // do {
    //     if (arr1[i] <= arr2[j]){
    //         vec[k] = arr1[i];
    //         i += 1;
    //     } else {
    //         vec[k] = arr2[j];
    //         j += 1;
    //         inversions += 1;
    //         cout << "[" << arr1[i] << ", " << arr2[j] << "]  ";
    //     }
    //     k += 1;

    // } while ((i <= n1) && (j <= n2));

    // do {
    //     vec[k] = arr1[i];
    //     i += 1;
    //     k += 1;
    // } while (i <= n1);

    // do {
    //     vec[k] = arr2[j];
    //     j += 1;
    //     k += 1;
    // } while (j <= n2);

    // 
    for(int k = begin; k <= end; k++) {
        if (i == n1) {
            // end of arr1
            vec[k] = arr2[j++];

        } else if (j == n2) {
            // end of arr2
            vec[k] = arr1[i++];

        } else if (arr1[i] <= arr2[j]) {
            // no inversion happen
            vec[k] = arr1[i++];

        } else {
            vec[k] = arr2[j++];
            inversions += n1 - i;
        }
    }

    // for (int k = begin; k <= end; k++){
    //     if (arr1[i] > arr2[j]){
    //         inversions = inversions + n1 - i + 1;
    //         vec[k] = arr2[j];
    //         j = j + 1;
    //     } else if (vec[k]==arr1[j]){
    //     // } else {
    //     //     vec[k] = arr1[j];
    //         i = i + 1;
    //     }
    // }
    return inversions;
}

int merge_sort(vector<int> & v, int begin, int end){
    if (end == 0){
        return 0;
    }
    if (begin < end) {
        int mid = floor((begin + end) / 2);
        // cout << "begin: " << begin << " / mid: " << mid << " / end: " << end << endl;

        // cout << "--- left array ---" << endl;
        int left = merge_sort(v, begin, mid);
        // cout << "--- right array ---" << endl;
        int right = merge_sort(v, mid + 1, end);
        // cout << "--- merge left and right ---" << endl;
        int inversions = merge(v, begin, mid, end) + left + right;
        // cout << "left: " << left << " / right: " << right << " / inversions:" << inversions << endl;
        return inversions;
    } 
    else {
        return 0;
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

        // print_vec(all);
        int inversions = merge_sort(all, 0, all.size()-1);
        // cout << "inversions: " << inversions << endl;
        // cout << "========" << endl;

        // cout << inversions << endl;
        cout << inversions % 524287 << endl;


        // cout << endl;
    }

    return 0;
}

