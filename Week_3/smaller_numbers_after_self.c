#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  int index;
};

void merge(struct Node a[], struct Node temp[], int left, int mid, int right,
           int ans[]) {
  int i = left;
  int j = mid + 1;
  int k = left;
  int rightCount = 0;

  while (i <= mid && j <= right) {
    if (a[j].value < a[i].value) {
      temp[k++] = a[j++];
      rightCount++;
    } else {
      ans[a[i].index] += rightCount;
      temp[k++] = a[i++];
    }
  }

  while (i <= mid) {
    ans[a[i].index] += rightCount;
    temp[k++] = a[i++];
  }

  while (j <= right) {
    temp[k++] = a[j++];
  }

  for (i = left; i <= right; i++) {
    a[i] = temp[i];
  }
}

void mergeSort(struct Node a[], struct Node temp[], int left, int right,
               int ans[]) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(a, temp, left, mid, ans);
    mergeSort(a, temp, mid + 1, right, ans);

    merge(a, temp, left, mid, right, ans);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node a[n], temp[n];
  int ans[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].value);
    a[i].index = i;
    ans[i] = 0;
  }

  mergeSort(a, temp, 0, n - 1, ans);

  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }

  return 0;
}
