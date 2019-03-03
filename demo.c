#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>

void fun1() 
{ 
        int sign=1;
		double pi=0.0,tmp=1.0;

		while(fabs(tmp)>1e-1){ 
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
		sum=sum + a*x*i;
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


void main() 
{ 
      
	
	fun34();
} 

// 字符串处理函数


// 求长度
// int strlen ( const char *str )  返回字符串的实际长度，不含 '\0'。


//  复制字符串
// char *strcpy( char *dest, const char *src )  把src所指向的以 '\0'结尾的字符串复制到dest所指向的数组中
// char *strncpy(char *dest, const char *src, size_t n)   将参数src字符串拷贝前n个字符至参数dest所指的地址


// 比较字符串
// int strcmp( char *str1, char *str2 )  比较str1和str2的大小;  相等返回0，str1大于str2返回1，str1小于str2返回-1；
// strncmp


// 连接字符串
// char *strcat(char *dest, const char *src)  将参数src字符串拷贝到参数dest所指的字符串尾
// strncat


// 查找 字符位置
// char* strchr(const *s, int c)
// 用来找出参数s字符串中第一个出现参数c的地址，然后将该字符出现的地址返回

// void* memchr(const void *s, int c, size_t n); 
// 从buf所指内存区域的前n个字节查找字符c  当第一次遇到字符c时停止查找。如果成功，返回指向字符c的指针；否则返回NULL  与strchr不同，它不会遇到'\0'而结束

// char* strstr(const char *haystack, const char *needle)  
// Strstr()会从字符串 haystack中搜寻字符串needle，并将第一次出现的地址返回  返回指定字符串第一次出现的地址，否则返回0


// 分割字符串  
// char *strtok(char *s, const char *delim);
// 分解字符串为一组字符串。s为要分解的字符串，delim为分隔符字符串

// 设置字符串
// char *strset(char *s, char c);  
// 把字符串s中的所有字符都设置成字符c

// void *memset(void *s, int ch, size_t n);  
// 作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法  与strset不同，遇到'\0'不会结束，需要给定所要设置的空间大小。


// itoa()：整型->字符串
/*
char *  itoa ( int value, char * buffer, int radix );
它包含三个参数：

value, 是要转换的数字；

buffer, 是存放转换结果的字符串；

radix, 是转换所用的基数，2-36。如，2：二进制，10：十进制，16：十六进制
*/

// ltoa()：长整型值->字符串

// ultoa()：无符号长整型值->字符串
// gcvt()：浮点型数->字符串，取四舍五入
// ecvt()：双精度浮点型值->字符串，转换结果中不包含十进制小数点
// fcvt()：指定位数为转换精度，其余同ecvt()

// atof()：字符串->双精度浮点型值
// atoi()：字符串->整型值

// atol()：字符串->长整型值
// strtod()：字符串->双精度浮点型值，并报告不能被转换的所有剩余数字
// strtol()：字符串->长整值，并报告不能被转换的所有剩余数字
// strtoul()：将字符串->无符号长整型值，并报告不能被转换的所有剩余数字。

/*
1. abs
  原型：extern int abs(int x);  
  功能：求整数x的绝对值  
  说明：计算|x|, 当x不为负时返回x，否则返回-x


  2. fabs	
  原型：extern float fabs(float x); 
  功能：求浮点数x的绝对值  
  说明：计算|x|, 当x不为负时返回x，否则返回-x

  13. ceil	
  原型：extern float ceil(float x);  
  功能：求不小于x的最小整数  
  说明：返回x的上限，如74.12的上限为75，-74.12的上限为-74。返回值为float类型。

  14. floor	
  原型：extern float floor(float x);
  功能：求不大于x的最达整数  
  说明：返回x的下限，如74.12的下限为74，-74.12的下限为-75。返回值为float类型。

  15. exp	
  原型：extern float exp(float x);
  功能：求e的x次幂  
  说明：e=2.718281828...

  16. fmod	
  原型：extern float fmod(float x, float y);
  功能：计算x/y的余数  
  说明：返回x-n*y，符号同y。n=[x/y](向离开零的方向取整)

  17. modf	
  原型：extern float modf(float num, float *i);  
  功能：将浮点数num分解成整数部分和小数部分。  
  说明：返回小数部分，将整数部分存入*i所指内存中。

  21. log	
  原型：extern float log(float x);
  功能：计算x的自然对数。  
  说明：x的值应大于零。


22. log10	
  原型：extern float log10(float x);
  功能：计算x的常用对数。  
  说明：x的值应大于零。\

  23. pow	
? 原型：extern float pow(float x, float y);??
? 功能：计算x的y次幂。??
? 说明：x应大于零，返回幂指数的结果。


24. pow10	
? 原型：extern float pow10(float x);??
? 功能：计算10的x次幂。??
? 说明：相当于pow(10.0,x)。

25. sqrt	
? 原型：extern float sqrt(float x);??
? 功能：计算x的平方根。??
? 说明：x应大于等于零。



*/