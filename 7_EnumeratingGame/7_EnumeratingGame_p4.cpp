// PS: THERE IS A MISSING PART INDICATED WITH "LAST PART"
// SUBMITTING THIS FILE VERBATIM TO KATTIS SHOULD BE WA

// Rational Sequence 2
// the pattern (after you see it) is like a Binary Heap indexing

// this is the public discussion of solving
// https://open.kattis.com/problems/rationalsequence2
// (Sat 24 March 2018, 11.00 - approx 11.42)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // standard

  int P; // 1 <= P <= 1000, number of test cases
  cin >> P; // just read

  while (P--) { // process per test case... O(P*log n) as n will be at most 2^31-1, so the height is not going to be more than ~30
    // Each data set consists of a single line of input
    // It contains the data set number, K, a single space, the numerator, p, a forward slash (/, graaahhh) and the denominator, q
    int K, p, q;
    char dummy; // ANOTHER I/O tip for CS2040C class, use this to skip the '/' symbol, to be ignored
    cin >> K >> p >> dummy >> q; // yeah, done, I/O problem gone :)

    // PART 1: Find the pattern based on the given information:
    // root is 1/1, left child is p/(p+q), right child is (p+q)/q... Isn't that trivial?? (or not :O:O)
    // so from a given p/q, we can find a path back to root :)
    stack<char> path; // we will reverse the path later, so we will use stack to help
    while (p > 1 || q > 1) { // the pattern is trivial (for me :O, not sure for most of you), basically, ie NOT ROOT
      if (p > q) { // when we are at the right subtree
        path.push('R'); // move upwards and declare that we came from right subtree
        p -= q; // q remains and p is subtracted by q, this is the p/q value of the parent vertex
      }
      else { // when we are at the left subtree
        path.push('L'); // move upwards and declare that we came from left subtree
        q -= p; // p remains and q is subtracted by p, this is the p/q value of the parent vertex
      }
    }

    // PART 2: Now from root, simulate the path as per binary heap indexing strategy and get the required answer n :)
    // Review the pictures shown here https://visualgo.net/en/heap :D
    // and also review previously discussed problem: https://open.kattis.com/problems/numbertree
    int n = 1; // see, I start from 1 now
    while (!path.empty()) { // binary heap like indexing, now we start from the root
      // LAST PART START
//      cout << path.top() << endl; // of course don't print, do something else here
      if(path.top() == 'R') n = 1 + (n*2);
      else n *= 2;


      // LAST PART END
      path.pop();
    }

    // For each data set there is a single line of output
    // It contains the data set number, K, followed by a single space which is then followed by the value of n for which F(n) is p/q
    // Inputs will be chosen so n will fit in a 32-bit integer.
    cout << K << " " << n << "\n";
  }

  return 0;
}