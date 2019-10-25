int isSubsetSum(int arr[], int n, int sum)
{
  /* The value of subset[i][j] will be true if there is a
  subset of set[0..j-1] */
  int subset[sum+1][n+1];
  int i,j;
 
  /* If sum ==0, there will be empty set satisfying that condition
  hence row with sum = 0 will have all true values. */
  for (i = 0; i <= n; i++)
    subset[0][i] = true;
 
  /* If sum is not 0 and set is empty, no subset is there */
  for (i = 1; i <= sum; i++)
    subset[i][0] = false;
 
  for (i = 1; i <= sum; i++)
  {
    for ( j = 1; j <= n; j++)
    {
        /* If there is subset with j-1 elements, copy value */
        subset[i][j] = subset[i][j-1];
 
        /* Now if the latest element can be added */
        if (i <= arr[j-1])
            subset[i][j] = subset[i][j]
                           ||subset[i-arr[j-1]][j-1];
    }
  }
  return subset[sum][n];
}
 
/* Driver program */
int main(){
 
  int set[] = {1,3,5,4,6};
  int n  =  sizeof(set)/sizeof(set[0]);
  int K = 10;
  printf("Is there subset with Sum = %d : %s",
          K, isSubsetSum(set, n, K) ? "Yes" : "No");
  return 0;
}