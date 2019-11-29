/**
 * Reverse Package Merge Algorithm.
 * @param {Array.<number>} P sorted probability.
 * @param {number} n number of symbols.
 * @param {number} L code length limit.
 * @return {Array.<number>} code lengths.
 */

var P = [7,10,13,14]
var n = 4
var L = 4

console.log(reversePackageMerge(P, n, L))

var P = [59, 58, 57, 59, 58, 57, 59, 58]
var n = 8
var L = 7

console.log(reversePackageMerge(P, n, L))

function reversePackageMerge(P, n, L) {
    /** @type {Array.<number>} */
    var l = new Array(L);
    /** @type {Array.<number>} */
    var b = new Array(L);
    /** @type {Array.<number>} */
    var c = new Array(n);
    /** @type {Array.<number>} */
    var value = new Array(L);
    /** @type {Array.<number>} */
    var type  = new Array(L);
    /** @type {Array.<number>} */
    var curpos = new Array(L);
    /** @type {number} */
    var excess = (1 << L) - n;
    /** @type {number} */
    var half = (1 << (L - 1));
    /** @type {number} */
    var i;
    /** @type {number} */
    var j;
    /** @type {number} */
    var t;
    /** @type {number} */
    var weight;
    /** @type {number} */
    var next;
  
    /**
     * @param {number} j
     */
    function takePackage(j) {
      /** @type {number} */
      var x = type[j][curpos[j]];
  
      if (x === n) {
        takePackage(j+1);
        takePackage(j+1);
      } else {
        --c[x];
      }
  
      ++curpos[j];
    }
  
    l[L-1] = n;
  
    for (j = 0; j < L; ++j) {
      if (excess < half) {
        b[j] = 0;
      } else {
        b[j] = 1;
        excess -= half;
      }
      excess <<= 1;
      l[L-2-j] = (l[L-1-j] / 2 | 0) + n;
    }
    l[0] = b[0];
  
    value[0] = new Array(l[0]);
    type[0]  = new Array(l[0]);
    for (j = 1; j < L; ++j) {
      if (l[j] > 2 * l[j-1] + b[j]) {
        l[j] = 2 * l[j-1] + b[j];
      }
      value[j] = new Array(l[j]);
      type[j]  = new Array(l[j]);
    }
  
    for (i = 0; i < n; ++i) {
      c[i] = L;
    }
  
    for (t = 0; t < l[L-1]; ++t) {
      value[L-1][t] = P[t];
      type[L-1][t]  = t;
    }
  
    for (i = 0; i < L; ++i) {
      curpos[i] = 0;
    }
    if (b[L-1] === 1) {
      --c[0];
      ++curpos[L-1];
    }
  
    for (j = L-2; j >= 0; --j) {
      i = 0;
      weight = 0;
      next = curpos[j+1];
  
      for (t = 0; t < l[j]; t++) {
        weight = value[j+1][next] + value[j+1][next+1];
  
        if (weight > P[i]) {
          value[j][t] = weight;
          type[j][t] = n;
          next += 2;
        } else {
          value[j][t] = P[i];
          type[j][t] = i;
          ++i;
        }
      }
  
      curpos[j] = 0;
      if (b[j] === 1) {
        takePackage(j);
      }
    }
  
    return c;
  }