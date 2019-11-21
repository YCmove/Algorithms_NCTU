#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Point{
    int points, t;
    float ratio;
};

bool comp (const Point a, const Point b){
    if (a.ratio == b.ratio){
        return a.points > b.points;
    }
    return a.ratio > b.ratio;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    int points, t;
    Point arr[n];
    // int ratio[n] = {0};
    for (int i = 0; i < n;++i) {
        cin >> points >> t;
        // cout << "points=" << points << ", t=" << t << '\n';
        arr[i].points = points;
        arr[i].t = t;
        arr[i].ratio = (float)points / t;
        // cout << "points=" << points << ", t=" << t << ", ratio=" << arr[i].ratio << '\n';
    }

    sort(arr, arr+n, comp);

    int max_points = 0;
    for (int i = 0; i < n;++i) {
        cout << "points: " << arr[i].points << ", t: " << arr[i].t << ", ratio: " << arr[i].ratio << '\n';
        m -= arr[i].t;
        if (m < 0){
            // cout << max_points << '\n';
            break;
        }
        max_points += arr[i].points;
    }
    cout << max_points << '\n';


    return 0;
}
