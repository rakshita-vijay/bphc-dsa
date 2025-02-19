arraymax (int a[], int b[]) {
  max = A[0];  // basic operations: accessing, assigning
  for (int i = 1; i < n; i++) {
    if A[i] > max // basic operations: accessing, comparing
      max = A[i];
  }
  return max;
}
// 2 in line 2
// 1 + n-1 + 2(n-1) in line 3
// 2(n-1) in line 4
// 2(n-1) in line 5
// 1 in line 7
// 2 + 1 + n-1 + 2n-2 + 2(2n-2) + 1 = 3 + n-1 + 2n-2 + 4n-4 + 1
                                =  7n-7 + 4
                                = 7n - 3
