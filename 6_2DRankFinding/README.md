# Final AC
- Deal with 2^31, use index compression
- BIT對x, y軸做兩次sort即可
- Time 784


# Related Problem
- [杭州電子科技大學 - Stars, 極相似, level算法不同](http://acm.hdu.edu.cn/showproblem.php?pid=1541)
- [HDU 1541 Stars, o4_AC](https://blog.csdn.net/libin56842/article/details/14105099)
- [poj 3264 - Balanced Lineup](https://blog.csdn.net/hurmishine/article/details/54176068)
- [BIT樹狀數組 詳細解說](https://www.mayuan.site/post/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84/)
- [树状数组求逆序对原理, Inversion Pair !!](https://www.jianshu.com/p/8a4081f0ec20)
  - 假如现在有一些数：1234 98756 123456 99999 56782,由于1234是第一小的数，所以num[1]=1;依此，有num[5]=2,num[2]=3,num[4]=4,num[3]=5;这样转化后并不影响原来数据的相对大小关系，何乐而不为呢！！！
  - 树状数组+去重离散化
- [知乎 - BIT樹狀數組](https://zhuanlan.zhihu.com/p/73346123)
- [P2617 Dynamic Rankings](https://www.luogu.org/problem/P2617)
- [dominance graph](https://codeforces.com/blog/entry/65140)
- [codeforecs - Dominant Indices](https://codeforces.com/problemset/problem/1009/F)
- [codeforecs - calculate dominance of points](https://codeforces.com/blog/entry/60745)
- [Weird Points](https://www.spoj.com/problems/DCEPC705/)
- [codeforecs - Tufurama](https://codeforces.com/contest/961/problem/E)
- [codeforecs](http://cfrp.azurewebsites.net/blog/entry/49743)
- [codeforecs - Tufurama: 有vector, segment tree的操作](https://codeforces.com/contest/961/submission/62313819)
- [Tufurama](https://blog.csdn.net/my_sunshine26/article/details/79831362)

# 主席樹
- [主席樹詳解: 解決區間第k大的問題](https://www.itread01.com/content/1549938961.html)
- [ACM数据结构（一）——主席树](https://www.jianshu.com/p/e1d46a714fa8)
- [主席樹](https://blog.sengxian.com/algorithms/president-tree)

# CDQ 分治
- [CDQ 分治, 三维偏序](https://oi-wiki.org/misc/cdq-divide/)
- [CDQ 分治](https://zhuanlan.zhihu.com/p/55322598)

# 二维偏序, 三维偏序
- 给定一个序列，每个点有两个属性(a, b), 试求：这个序列里有多少对点对(i, j)满足 i < j, ai < aj, bi < bj
- [【模板】三维偏序](https://www.luogu.org/problem/P3810)
- 逆序对相当于是一个二维偏序
- [二维偏序, xy座標長方形問題](https://zhuanlan.zhihu.com/p/55322598)

# BITSET + 分塊查詢

# 巨大Array記憶體問題
- [Heap vs Stack](https://stackoverflow.com/questions/216259/is-there-a-max-array-length-limit-in-c)

# Point (127, 0) overflow
- 2^7 = 128
- 使用 `#include <climits>`
```
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
Aborted (core dumped)
```

# ST表
- [ACM gitbook](https://hrbust-acm-team.gitbooks.io/acm-book/content/data_structure/ds_part6.html)
- 可以維護區間最大or最小值


