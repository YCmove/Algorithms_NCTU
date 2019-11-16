#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
// #define MID ((BEG+END)>>2)
int arr_len, invers = 0;

void merge(int * arr, int BEG, int MID, int END){
    int n1 = MID - BEG + 1;
    int n2 = END - MID;
    int i = BEG;
    int j = n1;
    int k = 0;
    cout << "\n Start Merge: BEG=" << BEG << ", MID=" << MID << ", END=" << END << ", i=" << i << ", j=" << j << ", n1=" << n1 << ", n2=" << n2 << endl;
    // for (; k < END - BEG + 1;++k){
    // cout << "i: " << i << " / j: " << j << " / k: " << k << endl;
    for (k = BEG; k <= END; ++k){
        cout << "i: " << i << " / j: " << j << " / k: " << k << endl;
        cout << "arr[i]: " << arr[i] << " / arr[j]: " << arr[j] << " / arr[k]: " << arr[k] << endl;

        // if (i > n1 || j >n2){
        //     return;
        // }

        if (arr[i] <= arr[j]){
            cout << "3." << '\n';
            arr[k] = arr[i];
            i++;
        } else if (arr[i] > arr[j]){
            cout << "Invers Added! arr[i]=" << arr[i] << " / arr[j]=" << arr[j] << " / invers=" << invers << '\n';
            arr[k] = arr[j];
            j++;
            invers += n1 - i;
        }
        
        if(i == MID){
            cout << "1." << '\n';
            arr[k] = arr[j];
            j++;
        } else if (j == MID + n2){
            cout << "2." << '\n';
            arr[k] = arr[i];
            i++;
        }

    }
    return;
}

void mergesort(int * arr, int BEG, int END){
    if (END == 0) return;
    if (BEG == END) return;
    int MID = (BEG+END)/2;
    if (BEG < END){
        cout << "here 1,  BEG: " << BEG << " / MID: " << MID << " / END: " << END << '\n';
        mergesort(arr, BEG, MID);
        cout << "here 2,  BEG: " << BEG << " / MID: " << MID << " / END: " << END << '\n';
        mergesort(arr, MID+1, END);
        cout << "here 3,  BEG: " << BEG << " / MID: " << MID << " / END: " << END << '\n';
        merge(arr, BEG, MID, END);
    } else {
        return;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    const int arr_len = n;
    int arr[arr_len];
    int i = 0;

    while (n--){
        cin >> arr[i];
        // cout << arr[i] << '\n';
        i++;
    }

    mergesort(arr, 0, arr_len);
    cout << invers % 524287 << endl;

    return 0;
}