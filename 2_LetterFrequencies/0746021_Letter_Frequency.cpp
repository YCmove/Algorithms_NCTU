#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

// use 2-D vector

int main(){
    string line;
    getline(cin, line);

    // cout << "total character: " << line.size() << endl;

    unordered_map<char, int> unorder_map;

    // 計算每個char的出現次數
    for (char c:line){
        unorder_map[(int)c]++;
    }

    // 不需要 dynamic allocate, input string 的 size 早就知道了
    vector<vector<int>> show_freq(line.size(), vector<int>(0, line.size()));
    // vector<vector<int>> show_freq(line.size());

    for (auto & pair: unorder_map){
        // cout << pair.first << endl;
        // cout << (int)pair.first << endl;
        // cout << pair.second << endl;
        show_freq[pair.second].push_back((int)pair.first);
        // cout << "----------------" << endl;

    }

    // ASCII 從小到大開始for loop
    for (int i = show_freq.size() - 1; i >= 0; i--){
        int row_size = show_freq[i].size();
        if (row_size == 1)
        {
            // 只出現一次
            cout << show_freq[i][0] << " " << i << endl;
        } 
        else if (row_size > 1) {
            for (int j = 0; j <= row_size - 1; j++)
            {
                vector<int>::iterator min_elem = min_element(show_freq[i].begin(), show_freq[i].end());
                int min_elem_idx = min_element(show_freq[i].begin(), show_freq[i].end()) - show_freq[i].begin();
                // cout << "*min_elem: " << *min_elem << endl;
                // cout << "min_elem_idx: " << min_elem_idx << endl;
                cout << *min_elem << " " << i << endl;
                show_freq[i].erase(min_elem);
            }
        }
    }

        return 0;
}
