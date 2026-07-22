#include <stdio.h>

int merge(int a[], int aux[], int L, int mid, int R) {
  int count = 0;

  int j = mid + 1;

  for (int i = L; i <= mid; i++) {
    while (j <= R && (long long)a[i] > 2LL * a[j])
      j++;

    count += j - (mid + 1);
  }

  int i = L;
  j = mid + 1;
  int k = L;

  while (i <= mid && j <= R) {
    if (a[i] <= a[j])
      aux[k++] = a[i++];
    else
      aux[k++] = a[j++];
  }

  while (i <= mid)
    aux[k++] = a[i++];

  while (j <= R)
    aux[k++] = a[j++];

  for (i = L; i <= R; i++)
    a[i] = aux[i];

  return count;
}

int mergeSort(int a[], int aux[], int L, int R) {
  if (L >= R)
    return 0;

  int mid = L + (R - L) / 2;

  int count = 0;

  count += mergeSort(a, aux, L, mid);
  count += mergeSort(a, aux, mid + 1, R);
  count += merge(a, aux, L, mid, R);

  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  int a[n];
  int aux[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("%d\n", mergeSort(a, aux, 0, n - 1));

  return 0;
}
