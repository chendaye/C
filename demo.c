#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>

void fun1() 
{ 
        int sign=1;
		double pi=0.0,tmp=1.0;

		while(fabs(tmp)>1.0e+1){ 
			pi+=(1.0/tmp)*sign;

			sign=-sign;
			tmp+=2;
		}

		pi*=4;

		printf("%10.8f",pi);
	
} 


void fun2() 
{ 
       int a1=1,a2=1,a3,i;
		
		
	    for(i=1;i<10;i++){
			printf("%12d %12d",a1);
			a3=a1+a2;
			printf("%d\n",a3);
			a1=a2;
			a2=a3;
	   }
	
} 

// 判断是不是素数
int fun3(){
	int n,i;

	scanf("%d",&n);

	if(n<3){
		printf("不能小于3");
		return 0;
	}else{
		for(i=2;i<n-1;i++){
			if(n%i==0){
				printf("不是素数");
				return 0;
			}
		}
		printf("是素数");
		return 1;
	}
}

void fun4(){
	int n,i;
	int sign;

	for(n=100;n<=200;n++){
		sign=1;
		for(i=2;i<n-1;i++){
			if(n%i==0){
				sign=0;
				break;
			}
		}
		if(sign==1){
			printf("%d\n",n);
		}
		
	}

	
}

// 最大公约数 最小公倍数 最小公倍数=(m*n)/最大公约数
void fun5(){

	int m,n,i=1,j;
	int max,min;

	
	scanf("%d%d",&m,&n);

	max=1;
	min=m*n;
	j=m*n;
	
	while(i<=m&&i<=n){
		if(m%i==0&&n%i==0){
			max=i;
		}
		i++;
	}



	while(j>=m&&j>=n){
		if(j%m==0&&j%n==0){
			min=j;
		}
		j--;
	}
	printf("%d是最小公倍数\n%d是最大公约数\n",min,max);
}


// 输入一行字符 统计字母 空格 数字 和其他的个数
void fun6(){
	char c;
	int word=0,space=0,num=0,other=0;
	c=getchar();

	while(c!='\n'){
		// 字符 '0'~'9' 占一个字节  整数 0-9 占2或4字节
		if(c>='0'&&c<='9'){
			num++;
		}else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			word++;
		}else if(c==' '){
			space++;
		}else{
			other++;
		}

		c=getchar();
	}
	printf("word=%d,space=%d,num=%d,other=%d\n",word,space,num,other);
}


// S=a + aa + aaa  n=3  a2=a1*10 + a
void fun7(int a){
	int n,i=1;
	double sum=0.0;
	int m,x;
	scanf("%d",&n);
	
	while(i<=n){
		m=n-i;
		x=1;
		while(m>0){
			x*=10;
			m--;
		}
		sum=sum + a*x*i;  //  a*x  有 i 个  a00 有1个  a0有2个  a有3个
		i++;
	}

	printf("%f\n",sum);

}


// 算阶乘
void fun8(){
	double s=0.0;
	int n=1;
	int m=1;
	
	for(n=1;n<=20;n++){
		m=m*n;
		s+=m;
	}
	printf("%f\n",s);


}

void fun9(){
	double sum=0.0;
	int i;
	for(i=1;i<=100;i++){
		sum+=i;
	}

	for(i=1;i<=50;i++){
		sum+=i*i;
	}

	for(i=1;i<=10;i++){
		sum+=1/i;
	}

	printf("%15.6f\n",sum);
}

// 水仙花数
void fun10(){
	int i;
	int a,b,c;
	int d;
	for(i=100;i<=999;i++){
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		d=a*a*a+b*b*b+c*c*c;
		if(d==i){
			printf("%d\n",d);
		}
	}
}

// 完数
void fun11(){
	int i,j;
	int m;
	for(i=1;i<=1000;i++){
		m=0;
		for(j=1;j<i;j++){
			if(i%j==0){
				m+=j;
			}
		}
		if(m==i){
			printf("%d\n",i);
		}
	}
}

// 分数求和
void fun12(){
	double sum=0.0;
	int a=1,b=2,c=2,d=3;
	int i=1;
	double m,n;
	double s;

	sum=2.0/1.0+3.0/2.0;
	while(i<=18){
		// 分子
		m=a+b;
		n=c+d;
		sum+=n/m;
		a=b;b=m;
		c=d;d=n;
		i++;
	}

	printf("%16.10f\n",sum);

}

void fun13(){
	double s0=100,h0=100;
	int i=0;
	while(i<=10){
		s0+=h0;
		h0=h0/2;
		i++;
	}
	printf("%d\n",i);
	printf("h=%5.2f\n",h0);
	printf("s=%5.2f\n",s0);

}


// 猴子吃桃
void fun14(){
	int day,d1,d2;
	day = 9;
	d2=1;
	while(day>0){
		d1=(d2+1)*2;
		d2=d1;
		day--;
	}
	printf("%d\n",d1);
}


// 开根号
void fun15(double a){
	double x1,x2;
	double diff=0;

	x1=a/2;
	

	do{
		x2=(x1+a/x1)/2;
		diff=(x2>x1)?(x2-x1):(x1-x2);
		diff=fabs(x1-x2);
		x1=x2;
	}while(diff>=1e-5);

	
	printf("%f\n",x2);
}


// 二分法求根
double fun16(double a,double b){
	
	double x,fa,fb,fx;
	x=(a+b)/2;

	if(fabs(a-b) < 1e-8){
		printf("%6.3f\n",x);
		return x;
	}else{
		fa=2*a*a*a-4*a*a+3*a-6;
		fb=2*b*b*b-4*b*b+3*a-6;
		fx=2*x*x*x-4*x*x+3*a-6;

		if(fa*fx<0){
			fun16(a,x);
		}else{
			fun16(x,b);
		}

	}
}

// 打印图形  找到一行的最大符号个数，按奇偶 周期打印不同的符号
void fun17(){
	int i,j;
	// 上三角
	for(i=1;i<=4;i++){
		for(j=1;j<=14;j++){
			if(j%2!=0 && j>=7-(i-1)*2 && j<=7+(i-1)*2){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}

	// 下三角
	for(i=1;i<=3;i++){
			for(j=1;j<=14;j++){
			if(j%2!=0 && j>=7-(3-i)*2 && j<=7+(3-i)*2){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}


// 选择法对10个整数排序
void fun18(){
	int a[5];
	int i,j;
	int tmp;



	for(i=0;i<5;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	printf("\n");

	// 输出5个数
	for(j=0;j<5;j++){
		printf("%5d",a[j]);
	}
	printf("\n");
	i=0;j=0;

	// 排序
	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
			if(a[j]>a[i]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}

	for(j=0;j<5;j++){
		printf("%5d",a[j]);
	}

	printf("\n");
}


// 3*3矩阵对角线和
void fun19(){
	int a[3][3];
	int i,j;
	int sum=0 ;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}

	printf("\n");

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			//printf("a[%d][%d]=",i,j);
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}

	printf("\n");


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j){
				sum+=a[i][j];
			}
		}
	}

	printf("%d\n",sum);
}


// 按顺序插入
void fun20(){

	int a[8]={1,2,3,5,6,7,8};
	int b,i,j,tmp;
	scanf("%d",&b);

	for(i=0;i<8;i++){
		if(a[i]>b){
			j=i;
			break;
		}
	}

	for(i=6;i>=j;i--){
		a[i+1]=a[i];
	}
	a[j]=b;

	for(i=0;i<8;i++){
		printf("%5d", a[i]);
	}
	printf("\n");
	
}

// 数组逆序
void fun21(){
	char a[]="QDFRG ert #$Tv";

	int i=0;
	int up=0;
	int low=0;
	int space=0;
	int other=0;
	while(a[i]!='\0'){
		if(a[i]>'A'&&a[i]<'Z'){
			up++;
		}else if(a[i]>'a'&&a[i]<'z'){
			low++;
		}else if(a[i]==' '){
			space++;
		}else{
			other++;
		}

		i++;
	}
	printf("大写字母个数=%d\n小写字母个数=%d\n空格个数=%d\n其他字母个数=%d\n",up,low,space,other);
	
}


// 输出图形
void fun22(){
	int i,j;
	char sp=' '; 

	for(i=0;i<5;i++){
		
		for(j=i;j>0;j--){
			printf("%c",sp);
		}
		printf("*  *  *  *  *");
		
		printf("\n");
	}
}

void fun23(){
	char a='a';
	char b='A';

	printf("%d\n",a);
	printf("%c\n",b+1);

}

void fun24(){
	char a[]="hellow";
	char b[]=" world!";
	char c[20];

	int i=0,j=0;
	int len=0;
	 
	while(a[i]!='\0'){
		c[len]=a[i];
		i++;
		len++;
	}
	while(b[j]!='\0'){

		c[len]=b[j];
		j++;
		len++;
	}

	len=0;
	while(c[len]!='\0'){
		printf("%c",c[len]);
		len++;
	}

}

void fun25(){
	 int i=0; int j=0;
	char a[10];
	char b[10];
	gets(a);
	gets(b);
   
	while(a[i]!='\0'&&b[j]!='\0'){
		if(a[i]>b[j]){
			printf("%d",1);
			break;
		}else if(a[i]==b[j]){
			printf("%d",-1);
			break;
		}else{
			i++;
		    j++;
		}
	}
	if(a[i]!='\0'){
		printf("%d",1);
	}else if(b[j]!='\0'){
		printf("%d",-1);
	}else{
		printf("%d",0);
	}
}


// 编一个程序，读入用户输入的，以“.”结尾的一行文字，统计一共有多少个单词，并分别输出每个单词含有多少个字符。 
//（凡是以一个或多个空格隔开的部分就为一个单词）

void fun26(){

	char str[100];
	int i=0,word=0,num=0;
	int start=0,end=0;
	gets(str);
	
	// 字符首空格 去掉
	while(str[i] != '.'){
		if(str[i]==' '){
			i++;
		}else{
			break;
		}
	}

	//printf("%c\n",str[i]);
	while(str[i] != '.'){
		if(str[i]!=' '){
			num++;
			i++;
		}else{
			word++;
			printf("%d\n",num);
			num=0;
			while(str[i]==' '){
				i++;
			}
			//printf("%c\n",str[i]);
		}

	}
	printf("%d\n", num);
    printf("%d\n", word+1);

}




// 输出字母个数  单词个数  最多的字母
void fun27(){
	int word=0,smb=0,i=0,j=0,max=0,count=0;
	char tmp;
	char s[100];
	gets(s);

	// 字母个数
	while(s[i] != '\0'){
		if(s[i] != ' '){
			smb++;
		}
		i++;
	}

	i=0;
	printf("字母个数=%d\n",smb);

	// 单词个数

	while(s[i] != '\0'){
		if(s[i] == ' '){
			i++;
		}else{
			break;
		}
	}

	while(s[i] != '\0'){
		if(s[i] != ' '){
			i++;
		}else{
			word++;
			while(s[i] == ' '){
				i++;
			}
		}
	}
	printf("单词个数=%d\n",word+1);
	

	// 出现最多的字母 和次数
	i=0;
	while(s[i] != '\0'){
		tmp = s[i];
		j=0; count=0;
		while(s[j] != '\0'){
			if(tmp == s[j]){
				count++;
			}
			j++;
		}
		if(max<count){
			max=count;
		}
		i++;
	}

	printf("%d\n",max);


}

// 合法的IP地址
void fun28(){
	char *s;
	char ip[36];
	int flag=1;
	gets(ip);
	
	// 第一次调用 参数 s
	s=strtok(ip,"."); // 第二个参数字符串
	while(s != NULL){
		// 后序调用 参数 null
		s=atoi(s);

		if(s>255 || s<0){
			flag = 0;

		}
		printf("%d\n",s);
		s=strtok(NULL,".");
	}

	if(flag!=1){
		printf("%s\n", "非法IP");
	}else{
		printf("%s\n", "合法IP");
	}
}


// 连接两个字符串
void fun29(){

	char a[10];
	char b[10];
	char c[22];
	int i=0,j=0,k=0,p=0;
	gets(a);
	gets(b);

	while(a[i] != '\0'){
		k=0;
		while(c[k] != '\0'){
			if(c[k] == a[i]){
				break;
			}
			k++;
		}
		if(c[k]=='\0'){
			c[p]=a[i];
			p++;
			//printf("%c\n", a[i]);
		}
		i++; 

	}

	while(b[j] != '\0'){
		k=0;
		while(c[k] != '\0'){
			if(c[k] == b[j]){
				break;
			}
			k++;
		}
		if(c[k]=='\0'){
			c[p]=b[j];
			p++;
			//printf("%c\n", b[j]);
		}
		j++; 

	}

	k=0;
	while(c[k] != '\0'){
		if(c[k]>='a' && c[k]<='z'){
			printf("%c\n", c[k]);
		}
			
			k++;
	}

}

// 连接字符串
void fun30(){
	char a[100];
	char b[100];
	char c[200];
	int i=0,j=0;
	gets(a);
	gets(b);
	
	while(a[i] != '\0'){
	
		c[j] = a[i];
		i++;j++;
	}

	i=0;
	while(b[i] != '\0'){
		c[j] = b[i];
		i++; j++;
	}
	i=0;
	
	for(i=0; i<j; i++){
		printf("%c",c[i]);
	}
	printf("\n");

}



// n个数排序
void fun31(){
	int num[6];
	int i;
	for(i=0; i<6; i++){
		num[i] = getchar();
	}

	i=0;
	for(i=0; i<6; i++){
		printf("%d\n",num[i]);
	}
}

// 冒泡排序
void fun32(){

	int num[6];

	int i,j,n;
	int tmp;

	for(i=0;i<6;i++){
	
		printf("a[%d]\n",i);
		scanf("%d",&num[i]);
	}

	n = sizeof(num);
	printf("\n%d\n",n);
	n=6;
	// 冒泡排序
	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(num[j-1]<num[j]){
				tmp = num[j-1];
				num[j-1] = num[j];
				num[j] = tmp;
			}
		}	
	}
	
	printf("\n");
	
	for(i=0;i<6;i++){
	
		printf("%d\n",num[i]);
	}

}


// 判断守形数  
//itoa(num, str, 10);   
void fun33(){
	int a;
	int b;
	char ca[10],cb[10];
	//char *ca;
	//char *cb;

	int la,lb,flag=1;

	int i=0,j=0;
	// scanf 格式部分怎么样输入时就要一模一样
	scanf("%d", &a);

	b = a*a;

	// 整数转化为字符串 
	// 第一个参数：要转化的整数 第二个参数：存放转化的结果，第三个参数：转化的进制

	// itoa(num, str, 10);   atoi(s)
	itoa(a,ca,10);
	itoa(b,cb,10);

	la = strlen(ca);
	lb = strlen(cb);

	while(la<lb){
		lb--;
		i++;
	}

	for(j=0;j<la;j++){
		
		if(ca[j] != cb[i]){
			//printf("ca=%c,cb=%c\n",ca[j],cb[i]);
			flag =0;
			break;
		}else{
			i++;
		}
	}

	if(flag==1){
		printf("是守形数\n");
	}else{
		printf("不是守形数\n");
	}
	
	//printf("%d\n",i);
	

	//printf("%d\n%d\n",la,lb);

	printf("%s\n%s\n",ca,cb);


}

// atoi(s);
void fun34(){

	char a[4]= "123";

	int b;
	b=atoi(a);
	printf("%d\n",b);


}


// 八进制输出
void fun35(){

	// 八进制 %o  十六进制 %x
	int a=16;
	printf("%o\n",a);
}


// 算阶乘  无符号 unsigned int ;   %u   %5.2f
void fun36(){
	int n;
	unsigned int y1=1,y2=1;
	int i,j;
	scanf("%d",&n);
	
	for(i=1;i<=n;i+=2){
		y1*=i;
	}
	printf("y1=%u\n",y1);

	for(j=2;j<=n;j+=2){
		y2*=j;
	}
	printf("y2=%u\n",y2);


}

// 重复字符
void fun37(){
	char s[20];
	int i=0,j=0;
	gets(s);

	printf("%s\n", s);
	while(s[i] != '\0'){
		j=0;
		while(s[j] != '\0'){
			if(s[j] == s[i] && i != j){
				printf("%c,%d;",s[i],i+1);
				break;
			}else{
				j++;
			}
		}
		i++;
	}
	printf("\n");
	
}

// 回文字符串
void fun38(){
	char s[1000];
	//char r[1000];
	int len,i,j;

	int flag=1;
	gets(s);
	
	len = strlen(s);
	for(i=0,j=len-1;i<len && j>=0;i++,j--){
		if(s[i] != s[j]){
			flag=0;
			break;
		}
	}

	if(flag==1){
		printf("是回文字符串\n");
	}else{
		printf("不是回文字符串\n");
	}


}

// N阶楼梯
void fun39(){
	int n,two;

	int i,space,total=0;
	scanf("%d",&n);

	two = n/2;

	for(i=0;i<=two;i++){
		space = n-two*2+1;
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//一、改错题
/*
（1）程序的功能是：换数。例如:输入： 3和9  输出： 9和3
注释error的下一行中有错误
*/
#include "stdio.h"
void main()
{
   int x, y, t;

   printf("Please input two int numbers:");
   //===============error==============
   scanf("%d,%d", x, y );
   printf("x = %d, y = %d \n", x, y );

  //===============error==============
   t=x;x=t;y=x;
  
  printf("x = %d, y = %d \n", x, y );

}

//一、改错题
/*
（2）文件prog.c程序的功能是：任意输入一串字符，以“？”结束，
分别统计其中字母、数字、其他字符的个数。
注释error的下一行中有错误
*/
#include <stdio.h>
void main()
{
	char c ; int n1=0,n2=0,n3=0;
  	printf("input characters:");
	//===============error==============
  	while( c=getchar( );c!='?')
	{
	//===============error==============
  	  if ('a'<= ch <= 'Z')n1++;
    	  else if(c>='0'&&c<='9')n2++;
          else n3++;
	}
  	printf("n1=%d, n2=%d, n3=%d\n",n1,n2,n3);
}


//一、改错题
/*
（3）文件prog.c程序的功能是：是从键盘输入学号，然后输出学号中百位数字是3的学号，输入0时结束循环。

注释error的下一行中有错误
*/
#include <stdio.h>
void main()
{ long int num;
  scanf("%ld",&num);
	//==========  error ===========
  while(!num)
   { 
		//==========  error ===========
		if((num%100)/10==3)  
			printf("\n%ld\n",num);
        scanf("%ld",&num); 
   } 
}


//二、编程题
/*
（1）利用函数average()求一组数去掉一个最大数和去掉一个最小数后的平均数，
请编写average()函数。
*/
#include "stdio.h"
#include "test.h"
#define N 10
double average(double x[],int n)
{
	

}

void main()
{
	double a[N]={2,14.5,44.7,1,22.2,16,10.6,9,28.3,6};
	double aver;
	
	aver = average(a,N);
	printf("average = %lf  ",aver);


	test(a,10);
}

//二、编程题
/*
（2）程序<<<QN>>>利用函数fun()使数组a上半三角元素中的值全部置为0,
请编写函数void fun(int a[ ][N])，例如
   | 1 9 7 |                                  | 0 0 0 |
a= | 2 3 8 | ，则返回主程序后a数组中的值应为  | 2 0 0 |
   | 4 5 6 |                                  | 4 5 0 |

*/
#define  N  5

#include   "stdio.h"
#include   "conio.h"
#include   "stdlib.h"
#include   "test.h"

void  fun ( int a[][N] )
{

}

main ( )
{  int  a[N][N], i, j;
   printf("***** The array *****\n");
   for ( i =0;  i<N; i++ )
   {  for ( j =0; j<N; j++ )
     {  a[i][j] = rand()%20; printf( "%4d", a[i][j] ); }
        printf("\n");
   }
   fun ( a );
   printf ("THE  RESULT\n");
   for ( i =0;  i<N; i++ )
   {  for ( j =0; j<N; j++ ) printf( "%4d", a[i][j] );
      printf("\n");
   }
   test ( );
}


//二、编程题
/*
（3）程序利用函数primecount()求一组数中的质数个数，请编写primecount()函数。
*/
#include "stdio.h"
#include "math.h"
#include "test.h"

int primecount(int x[],int n)
{
	



}

void main()
{
	int a[10]={133,141,44,17,22,16,109,9,27,61};
	int count;

	count = primecount(a,10);
	printf("Prime Count =%d\n",count);

	test(a,10);
}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void main() 
{ 
      
	
	fun38();
} 

