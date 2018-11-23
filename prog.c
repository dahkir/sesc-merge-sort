#include <stdlib.h>
#include <stdio.h>

int min(int a, int b) {
  if(a<b){return a;}else{return b;}
}

void merge(int *newarr, int *arr1, int *arr2, int l1, int l2) {
  int i=0, k=0, j=0;
  while(k < l1 + l2) {
    if (i>=l2 || (j < l1 && arr1[j] >= arr2[i]))
      newarr[k] = arr1[j];
      j++;
      k++;
    if (j>=l1 || (i < l2 && arr2[i] >= arr1[j]))
      newarr[k] = arr2[i];
      i++;
      k++;
  }
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  int *arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int *temp =(int*)malloc(sizeof(int) * n);
  for (int i=1; i<n; i*=2){
    for (int j=0; j<n; j+=i*2){
      int l1 =min(i, n - j), l2 = min(i, n - j - i);
      merge(&temp[j], &arr[j], &arr[j + i], l1, l2);
    }
    int *temp2 =arr;
    arr=temp;
    temp=temp2;
  }
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
