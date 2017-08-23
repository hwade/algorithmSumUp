 #include <stdio.h>
/* 
  题目：求1/1!-1/3!+1/5!-1/7!+.....+(-1)^(n+1)/(2n-1)!
  思路：
<<<<<<< HEAD
    1.累乘，每次结果累加
*/

float add(int n){
    float denominator, sum=0.0;
    for(int i=1; i<=n; i++){
		if(i==1)
	        denominator = 1.0;
		else
			denominator *= (2*i-1)*(2*i-2);
		printf("%.6f ", denominator);
        sum += ((i%2 == 0)?-1.0:1.0)/denominator;
    }
    return sum;
=======
    1.求阶乘
    2.当前一次循环已经求出7!时,再去求9!不需要从1累成，从上一次7!的结果继续乘
    3.时间复杂度从O(n2)变为O(n)
*/
float fact(float n, int tag){
    if(tag==0 || n==0 || n==1){
        return(1);
    }
    else{
        return(n*fact(n-1, tag-1));
    }
}
float add(int n){
    int flag;
    float numerator ,denominator =1.0,sum=0.0;
    for(int i=1; i<=n; i++){
        flag = (i%2 == 0)?-1:1;
        numerator = flag;
        denominator *= fact(2*i-1,2);
        sum += numerator/denominator;
        printf("sum:%.4f, numerator:%.4f, denominator:%.4f, res%.4f:\n", sum, numerator, denominator, numerator/denominator);
    }
    return(sum);
>>>>>>> 1788b35824a9807bd83c82600b6a65c9de802dce
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<=0){
            printf("Input Error");
            continue;
        }
<<<<<<< HEAD
        printf("result: %.6f\n",add(n));
    }
    return 0;
}
=======
        printf("%.4f\n",add(n));
    }
    return 0;
}

>>>>>>> 1788b35824a9807bd83c82600b6a65c9de802dce
