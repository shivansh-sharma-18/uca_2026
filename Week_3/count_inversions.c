#include <stdio.h>
#include <stdlib.h>

int merge(int a[], int temp[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;
  int count = 0;

  while (i <= mid && j <= right) {
    if (a[i] <= a[j]) {
      temp[k++] = a[i++];
    } else {
      temp[k++] = a[j++];
      count += (mid - i + 1);
    }
  }

  while (i <= mid)
    temp[k++] = a[i++];

  while (j <= right)
    temp[k++] = a[j++];

  for (i = left; i <= right; i++)
    a[i] = temp[i];

  return count;
}

int mergeSort(int a[], int temp[], int left, int right) {
  int count = 0;

  if (left < right) {
    int mid = (left + right) / 2;

    count += mergeSort(a, temp, left, mid);
    count += mergeSort(a, temp, mid + 1, right);
    count += merge(a, temp, left, mid, right);
  }

  return count;
}

int main() {
  int n;
  scanf("%d", &n);

  int a[n];
  int temp[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("%d\n", mergeSort(a, temp, 0, n - 1));

  return 0;
}
