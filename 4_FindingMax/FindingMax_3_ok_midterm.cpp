#include <iostream>
#include <vector>

using namespace std;

void print_array(long long * segtree, long long size){
    for (long long i = 0; i < size; i++){
        cout << segtree[i] << " ";
    }
    cout << endl;
}

void print_vec(vector<long long> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


long long query(long long *segtree, long long idx, long long start, long long end, long long j, long long k){
    // 踢掉不合法的query
	if(j > end || start > k) return 0;
    // 完全在range內，直接回傳
	if(start >= j && end <= k){
        return segtree[idx];
    }
	long long mid = (start + end) / 2;
    if (k <= mid){
	    return query(segtree, 2 * idx, start, mid, j, k);
    } else if (j > mid){
	    return query(segtree, 2 * idx + 1, mid + 1, end, j, k);
    }
	long long left_ans = query(segtree, 2 * idx, start, mid, j, k);
	long long right_ans = query(segtree, 2 * idx + 1, mid + 1, end, j, k);
	return max(left_ans, right_ans);
}
void modify(long long *segtree, long long idx, long long start, long long end, long long position, long long value){
	if (position < start || position > end) return; // 踢掉不合法的值
	if (start == end) { // 到達了指定的leaf
		segtree[idx] = value;
		return;
	}
	long long mid = (start + end) / 2;
    if (position <= mid){
        modify(segtree, 2 * idx, start, mid, position, value);
    } else if (position > mid){
	    modify(segtree, 2 * idx + 1, mid + 1, end, position, value);
    }
	segtree[idx] = max(segtree[2 * idx], segtree[2 * idx + 1]);
	return;
}
void create_tree(long long *segtree, vector<long long> &vec, long long idx, long long start, long long end){
	if(start > end) return; // 踢掉特例
	if(start == end){ // 只有一個
		segtree[idx] = vec[start];
		return;
	}
	long long mid = (start + end) / 2;
	create_tree(segtree, vec, 2 * idx, start, mid);
	create_tree(segtree, vec, 2 * idx + 1, mid + 1, end);
	segtree[idx]= max(segtree[2 * idx], segtree[2 * idx + 1]);
	return;
}
int main(){
    long long n_num, m_queries;

    while (cin >> n_num >> m_queries){

        if (n_num == 0){
            return 0;
        }

        vector<long long> all;

        for (long long i = 0 ; i < n_num; i++){
            long long num;
            cin >> num;
            all.push_back(num);
        }

        // cout << "Start Processing: ";
        // print_vec(all);
        long long vec_size = all.size();
        long long * segtree = new long long[4 * vec_size + 1];
        long long idx = 1; //index of 1st node
        create_tree(segtree, all, idx, 0, vec_size - 1);
        // cout << "Printing Array" << endl;
        // print_array(segtree, 4 * vec_size + 1);

        for (long long p = 0 ; p < m_queries; p++){
            long long i, j, k;
            cin >> i >> j >> k;
            if (i == 1){
                // modify num[j] to k.
                // modify_node(j, k);
                // cout << "vec_size: " << vec_size << endl;
                modify(segtree, idx, 0, vec_size-1, j, k);
                // update_range_value(segtree, idx, start, end, 0,5,1);

            } else {
                // i == 2
                // output the maximum element between indices j and k.
                // cout << "Max value between (2, 2)" << endl;
                // cout << segtree.find_max_val(2, 2) << endl;
                // cout << segtree.find_max_val(3, 3) << endl;
                // cout << "Max value between (" << j << ", " << k << ")" << endl;
                // cout << segtree.find_max_val(j, k) << endl;
                // long long ans = query(segtree, idx, 0, vec_size - 1, j, k);
                // cout << "Answer to query: " << ans << endl;
                cout << query(segtree, idx, 0, vec_size - 1, j, k) << endl;

            }
        }

        // print_vec(all);


    }

    return 0;
}
