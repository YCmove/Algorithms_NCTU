#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff first
#define ss second

struct Job {
    int deadline, duration, idx;

    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

vector<int> compute_schedule(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end());

    set<pair<int,int>> s;
    vector<int> schedule;
    for (int i = jobs.size()-1; i >= 0; i--) {
        int t = jobs[i].deadline - (i ? jobs[i-1].deadline : 0);
        s.insert(make_pair(jobs[i].duration, jobs[i].idx));
        while (t && !s.empty()) {
            auto it = s.begin();
            if (it->first <= t) {
                t -= it->first;
                schedule.push_back(it->second);
            } else {
                s.insert(make_pair(it->first - t, it->second));
                t = 0;
            }
            s.erase(it);
        }
    }
    return schedule;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    ll due, t;
    vector<pair<ll, ll> > v;



    for (int i = 0; i < n;++i) {
        cin >> due >> t;
        v.push_back(make_pair(due, t));
    }
}