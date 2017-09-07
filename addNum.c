#include<stdio.h>
/*
  美团电话二面
  问题：输入整数N和M，将M表示成N个数相加，找出有多少种表示方法
  思路：
    1.将M表示成X+(M-X)，M-X由（N-1）个数的和累加得来；
    2.递归N次，每一层递归抽离1个数，抽离的数从1-M循环，知道M为0时检测递归深度是否为N，是的话全局计数器加1.
 */
int count = 0;
void addNum(int n, int m)
{
  if(n==0)
    count++;
  for(int i=1; i<m; i++){
    addNum(n-1,m-i);
  }
}

int main()
{
  int n, m;
  printf("input n & m: ");
  while(scanf("%d %d", &n, &m)!=EOF){
    if(m<n){
      printf("error: m(%d)<n(%d)",m, n);
      continue;
    }
    addNum(n, m);
    printf("res: %d", count);
    count = 0;
    printf("input n & m: ");
  }
  return 1;
}
