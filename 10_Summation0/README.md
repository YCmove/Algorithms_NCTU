# Related Problem
- [Flip minimum signs of array elements to get minimum sum of positive elements possible](https://www.geeksforgeeks.org/flip-minimum-signs-of-array-elements-to-get-minimum-sum-of-positive-elements-possible/)
- [Make Them Equal](https://codeforces.com/problemset/problem/1154/B)
- [Change the signs](https://www.freecodecamp.org/news/just-change-the-signs-how-to-solve-a-competitive-programming-question-f9730e8f04a9/)
  - Note, the dynamic programming is not directly used to obtain the final set, just the sum of the final set of numbers.
  - We use the concept of a parent pointer and backtracking to find out the actual set of numbers.

# Discuess
- think about it as two stacks and you try to minimize the diffrence of their height. This is the offline scheduling problem.
- Greedy can't solve this {4 5 6 7 8} and {5 5 3 3 3}
- 不要只從n, n+1, n+2 來思考subproblem
- 助教提示：**如何判斷sum == 0**
- [Number of subsets with zero sum](https://www.geeksforgeeks.org/number-of-subsets-with-zero-sum/)
- [non-empty subset whose sum is zero?](http://www.zrzahid.com/subset-sum-problem-dynamic-programming/)
- [Partition a set into two subsets such that the difference of subset sums is minimum](https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/)
  - The problem can be solved using dynamic programming when the sum of the elements is **not too big.**