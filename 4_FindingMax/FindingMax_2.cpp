#include <iostream>
#include <vector>

using namespace std;

// STNode: Segment Tree Node
struct STNode{
    long long start;
    long long end;
    long long max_idx;
    long long max;
    STNode * left;
    STNode * right;
    STNode(long long s, long long e):start(s),end(e),max_idx(0),max(0),left(nullptr),right(nullptr){};
};


class STree{
public:
    STree(vector<long long> & arr);
    STNode* createSTree(long long start, long long end, vector<long long> & arr);
    void modify_node(long long j, long long val);
    long long modify(long long j, long long val, STNode* root);
    long long find_max_val(long long j, long long k);
    long long find_max(long long j, long long k, STNode* root);
    void print_root();

private:
    STNode * root;
};

STree::STree(vector<long long> & arr){
    root = createSTree(0, arr.size()-1, arr);
}

void STree::print_root(){
        cout << "max: " << root->max << " / start: " << root->start << " / end: " << root->end << endl;
}

STNode* STree::createSTree(long long start, long long end, vector<long long> & arr){
    STNode* root = new STNode(start, end);

    // 1) only one number in input array
    // or 
    // 2) it recursive to the leaf
    if (start == end) {
        root->max = arr[start];
        root->max_idx = start;
        return root;
    }

    // split to left and right sub-tree
    long long mid = start + (end-start)/2;
    root->left = createSTree(start, mid, arr);
    root->right = createSTree(mid+1, end, arr);
    if (root->left->max > root->right->max){
        root->max = root->left->max;
        root->max_idx = root->left->max_idx;
    } else {
        root->max = root->right->max;
        root->max_idx = root->right->max_idx;
    }
    
    return root;
}

void STree::modify_node(long long j, long long val){
    modify(j, val, root);
}

long long STree::modify(long long j, long long val, STNode* root){
    // cout << "Start modify()" << endl;
    // cout << "root->start:" << root->start << " / root->end: " << root->end << endl;

    // 過濾違反規則的, i超過index範圍
    if (j < root->start || j > root->end){
        return 0;
    }

    // reach the end
    if (j == root->start && j == root->end){
        root->max = val; // 到達葉子，一定要修改max值
        // root->max_idx 到達葉子，max_idx 不變（一樣是自己）
        return root->max;
    }

    // search left or right tree
    long long mid = root->start + (root->end - root->start)/2;
    if (j <= mid){
        long long m = modify(j, val, root->left);
        root->max = (root->right->max > m) ? root->right->max : m;
        if (root->right->max > m){
            root->max_idx = root->right->max_idx;
        }
    } else {
        // root->max = max(root->left->max, modify(j, val, root->right));
        long long m = modify(j, val, root->right);
        root->max = (root->left->max > m) ? root->left->max : m;
        if (root->left->max > m){
            root->max_idx = root->left->max_idx;
        }
    }
    return root->max;
}


long long STree::find_max_val(long long j, long long k){
    return find_max(j, k, root);
    // print_root();
}

long long STree::find_max(long long j, long long k, STNode* root){
    // 排除違反規則的
    // cout << "Start find_max()" << endl;
    // cout << "root->start:" << root->start << " / root->end: " << root->end << endl;
    // print_root();
    if (j < root->start || k > root->end || j > k){
        // cout << "violate rule 1" << endl;
        // cout << "violate rule 1, j:" << j << endl;
        // cout << "violate rule 1, root->start:" << root->start << endl;
        // cout << "violate rule 1, k:" << k << endl;
        // cout << "violate rule 1, root->end:" << root->end << endl;
        // print_root();
        return 0;
    }

    // reach the leaf
    // if (j == root->start && k == root->end && j == k){
    if (j <= root->max_idx && k >= root->max_idx){
        // cout << "reach the leaf max:" << root->max << endl;
        return root->max;
    }

    // check the overlapping range(j, k) of left or right tree
    long long mid = root->start + (root->end - root->start)/2;
    if (k <= mid){
        // 全部在 left tree
        // cout << "go to left" << endl;
        return find_max(j, k, root->left);
    } else if (j > mid) {
        // 全部在 right tree
        // cout << "go to right" << endl;
        return find_max(j, k, root->right);
    }

    // 一部分在左，一部分在右
    // cout << "go to both" << endl;
    return max(find_max(j, mid, root->left), find_max(mid+1, k, root->right));

};

void print_vec(vector<long long> vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
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

        STree tree(all);
        // tree.print_root();

        for (long long p = 0 ; p < m_queries; p++){
            long long i, j, k;
            cin >> i >> j >> k;
            if (i == 1){
                // modify num[j] to k.
                // all[j] = k;
                tree.modify_node(j, k);
                // tree.print_root();
                // cout << endl;

            } else {
                // i == 2
                // output the maximum element between indices j and k.
                // tree.print_root();
                // cout << "Max value between (2, 2)" << endl;
                // cout << tree.find_max_val(2, 2) << endl;
                // cout << tree.find_max_val(3, 3) << endl;
                // cout << "Max value between (" << j << ", " << k << ")" << endl;
                cout << tree.find_max_val(j, k) << endl;
            }
        }


    }

    return 0;
}
