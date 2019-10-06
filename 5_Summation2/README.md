# Use Priority Queue
- https://en.cppreference.com/w/cpp/container/priority_queue

# Huffman(Hoffman) Tree Problem

# Test Data
- [Inverting Huffman](https://udebug.com/UVa/12676)

# Related LeetCode
- [1000. Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)
- [Stone Game](https://aaronice.gitbooks.io/lintcode/dynamic_programming/stone_game.html)
- [1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)
- [Burst Balloons](https://leetcode.com/problems/burst-balloons/)
- [Remove Boxes](https://leetcode.com/problems/remove-boxes/)
- [Cherry Pickup]()
- [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

# 石頭合併
- 这是一道经典的 DP 题。可以参考这个文章： 
石子合并问题3种题型 https://blog.csdn.net/briup_acmer/article/details/42706769 
石子合并问题是最经典的DP问题。首先它有如下3种题型： 
- (1)有N堆石子，现要将石子有序的合并成一堆，规定如下：每次只能移动任意的2堆石子合并，合并花费为新合成的一堆石子的数量。求将这N堆石子合并成一堆的总花费最小（或最大）。 
- 分析：当然这种情况是最简单的情况，合并的是任意两堆，直接贪心即可，每次选择最小的两堆合并。本问题实际上就是哈夫曼的变形。 

