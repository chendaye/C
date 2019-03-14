#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// 猴子吃桃
void fun1(){
	int i,total=1;

	for(i=1;i<10;i++){
		total = (total+1)*2;
	}

	printf("%d\n",total);
}


// 生兔子问题 == 斐波拉契数列
// 从第三个数开始 每一个数=前两个数之和
void fun2(){
	long int f1,f2;
	int i;
	f1=f2=1;  // 前两个月都是一对兔子
	//40个月就好了，多了也没意思了是吧
	for(i=1;i<=20;i++) 
	{	
		printf("%12ld %12ld",f1,f2); //这样每个月的数字就不会在一起了，中间会有空格，因为是长整形所以ld 12ld就是说走总共占12位
		if(i%2==0) printf("\n");
		f1=f1+f2; //这个月等于前两个月之和啊
		f2=f1+f2; //同上
	}
}

// 整数分解质因数   不用考虑什么质数
void fun3(){
	int n;
	int i;
	
	scanf("%d",&n);

    printf("%d=",n);
	// 因数从2开始 尝试
	for(i=2;i<=n;i++){
		while(n>=i){
			if(n%i==0){
				printf("%d",i);
				if(n!=i){
					printf("*");
				}
				// 每找到一个因数 用n除 剩下的继续分解因数
				n=n/i;
			}else{
				break;
			}
		}
	}
	printf("\n");
}


// 找一个整数出现的位置 和次数
void fun4(){

	int num[10];
	int i,key,count=0;
	scanf("%d",&key);
	printf("\n");
	for(i=0;i<10;i++){
		printf("num[%d]=",i);
		scanf("%d",&num[i]);
		printf("\n");
	}

	for(i=0;i<10;i++){
		if(key==num[i]){
			count++;
			printf("位置%d\n",i+1);
		}
	}
	printf("出现次数%d\n",count);

}

// 大于A的最小不重复数

int funto5(int n){
	// 判断是不是重复数
	char str[100];
	int i=1;
	itoa(n,str,10);
	while(str[i] != '\0'){
		if(str[i-1] == str[i]){
			return 1;
		}else{
			i++;
		}
	}
	return 0;

}

void fun5(){
	int n,flag;
	int i;
	scanf("value =%d",&n);

	for(i=n+1;i<1000;i++){
		flag = funto5(i);
		if(flag==1){
			printf("%d\n",i);
			return;
		}
	}

	printf("没有小于1000的\n");
	
}


// 算分段函数
void fun6(){
	double  x;
	double  res;
	scanf("%lf",&x);
	//printf("%6.4lf\n",x);
	if(x>0){
		res = (sqrt(x)+exp(x))/(5*x+5);
	}else{
		// 把60度 转化为弧度
		res = (2/3 + sin(3.1415926/180*60))*abs(x);
	}

	printf("%6.4lf\n",res);
}


// 按assic码值排序
void fun7(){

	char str[100];
	int len,i,j;
	char tmp;
	gets(str);

	len = strlen(str);
	printf("%d\n",len);
	// 冒泡排序
	for(i=0;i<len;i++){
		for(j=len-1;j>=i;j--){
			if(str[j]<str[j-1]){
				tmp = str[j];
				str[j] =str[j-1];
				str[j-1] = tmp;
			}
		}
	}
	printf("\n");
	i=0;
	while(str[i] != '\0'){
		printf("%c",str[i]);
		i++;
	}
	printf("\n");


}

// 2到1000之间的有完数  因式之和=自身
void fun8(){
	int tmp,i,j,n;
	int sum;
	for(i=2;i<=1000;i++){
		tmp = i;
		j=2;
		sum=0;
		while(j<=tmp){
			if(tmp%j==0){
				sum+=j;
				
				tmp=tmp/j;
			}else{
				j++;
			}
		}
		if(sum == i){
			printf("%d\n",i);
		}
	}

}

// 判断字符的合法性
// 辅助数组标记
// '0' - 48 = 0
// 
void fun9(){
	char str[100];
	int len;
	int num[10];
	int i;
	int sum=0;
	int sw;
	gets(str);
	len = strlen(str);

	for(i=0;i<10;i++){
		num[i]=0;
	}

	if(len < 10 ){
		printf("长度必须大于等于10！\n");
		return;
	}else if(!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))){
		printf("首字母必须是字母!\n");
		return;
	}else{
		printf("fuck\n");
		for(i=0;i<len;i++){
			if(str[i] == '=' || str[i] == '*'){
				printf("不能含有= *");
				return;
			}
			

			if(str[i]>='0' && str[i]<='9'){
				// 字符数字化为整型
				sw=str[i]-48;
				if(num[sw] == 0){
					printf("%d\n",sw);
					num[sw] = 1;
				}else{
					printf("数字不能重复！%c,%d\n",str[i],sw);
					return;
				}
			}
		}

		for(i=0;i<10;i++){
			if(num[i]==1){
				sum++;
			}
		}

		 // ，没有>= <=
		printf("%d\n",sum);
		if(sum<=6 && sum >=2){
			printf("合格！");
		}else{
			printf("不重复的数字要2-6个%d\n",sum);
		}


	}


}

void fun10(){
	
	// 整型转字符串  注意字符串要用数组存储
	int n=123;
	char  y[4];
	// 字符串转整型  字符串是数组  双引号
	char s[4]="123";
	int x;
	

	// 字符串到数字
	x = atoi(s );
	printf("%d\n", x);

	// 数字到字符串  2：表示转化成2进制字符串
	itoa(n,y,2);
	printf("%s\n",y);

	// 单个数字字符转化成 整数
	printf("%d\n",'6'-48);
}



// 递归实现凑一元
int fun11(s,n){
	
    int a[3]= {1,2,5};
	int count=0; 
	int i;
	if(n>2){
		if(s==0)
		    return 1;
		else
			return 0;
	}else{
		for(i=0;s>=i*a[n];i++){
			count = count + fun11(s-i*a[n],n+1);
		}	
	}
	return count;
}


void fun12(){

	char c ; int n1=0,n2=0,n3=0;
  	printf("input characters:");
	//===============error==============
  	while( c=getchar( )&& c!='?')
	{
	//===============error==============
  	  if ('a'<= c <= 'Z')n1++;
    	  else if(c>='0'&&c<='9')n2++;
          else n3++;
	}

	printf("n1=%d, n2=%d, n3=%d\n",n1,n2,n3);
}


// 去掉最大最小数求平均数
void fun13(){
	int max; 
	int min;
	int i=0;
	int len=0;
	int total = 0;
	int num[7] = {34,23,56,78,123,456,567};
    double res=0.0;

	max=num[0];
	min=num[0];
	while(num[i]){
		if(max<num[i]){
			max = num[i];
		}

		if(min > num[i]){
			min = num[i];
		}
		i++;
		len++;
	}
	i=0;
	len--;

	for(i=0;i<len;i++){
		if(num[i] != max && num[i] != min){
			total+=num[i];
		}
	}
	res = total/len;

	printf("%lf\n", res);
}

// 求一组数中的质数个数

// 求数组 长 sizeof(x)/sizeof((x)[0])
void fun14(){
	int n[6] = {2,4,7,8,13,17};

	int count=0;
	int i = 0,j;
	int flag;
	int len=0;
	//求数组 长
	len= sizeof(n)/sizeof(n[0]);

	while(i<len){
		flag = 1; // 假设是质数
		for(j=2;j<n[i];j++){
			if(n[i]%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1){
			count++;
		}
		i++;
	}

	printf("%d\n",count);

}

// 字符
void fun15(){
	char s[7]="qwerty";
	int len = sizeof(s)/sizeof(s[0]);

	int len2 = strlen(s);

	printf("%d\n%d\n",len,len2);  // len=7  '\0' 也在其中; len2=6
}


// 打印图形
void fun16(){
	int n[] = {9,8,7,6,5,4,3,2,1};
	int i,j;

	for(i=0;i<8;i++){
		for(j=0;j<i+1;j++){
			printf("*");
		}

		while(j<9){
			printf("%d",n[j]);
			j++;
		}
		printf("\n");
	}
}

// 打印斐波拉契数列（30个数）并统计其中的质数

// 判断是否是质数， 要排除1
int is_prime(long p){
	int i;
	int flag = 1;
	for(i=2;i<p;i++){
		if(p%i == 0){
			flag = 0;
			break;
		}
	}

	if(p == 1){
		flag = 0; // 1 不是质数
	}
	return flag;
}
// 斐波拉契数列的递归
void fun17(int f1, int f2, int count, int total){

	if(total>30){
		return;
	}else{
		if(is_prime(f1) == 1){
			count++;
			printf("%d：是质数\n", f1);
		}
		if(is_prime(f2) == 1){
			count++;
			printf("%d：是质数\n", f2);
		}

		printf("\n");

		printf("  %d  %d\n", f1,f2);

		// 斐波拉契数列的递归
		f1 = f1+f2;
		f2 = f1+f2;
		total+=2;

		// 递归
		fun17(f1,f2,count,total);

	}
}

// 袋子里有2红3绿5黄球，随机从中摸出8个，打印显示所有组合
void fun18(){
	int ball[] = {2,3,5};

	int i,j,k;

	// 红球i个
	for(i=1;i<=2;i++){
		// 绿球j个
		for(j=1;j<=3;j++){
			// 黄球的个数 《=5 
			k = 8-i-j;
			if(k <= 5){
				// 要求的并不是排列； 而是每个球各有多少个
				printf("%d红,%d绿,%d黄\n", i,j,k);
			}
		}
	}
	
}


// 整数分割

int c[10]; 
void fun(int n,int m,int index){ //m表示上一个加的数，n表示剩余没加的数之和 
	int i,j;
	if(n==0){
		for(i=0;i<index-1;i++){
			printf("%d + ",c[i]);
		}
		printf("%d\n",c[index-1]);
	}
	for(j=n;j>0;j--){
		if(j<=m){
			c[index] = j;
			// 递归
			fun(n-j,j,index+1);	
		}
	}
	
}

void fun19(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		fun(n,n,0);
	} 
	return 0;
}


// 打印ip
void fun20(){

	char ip[20];
	char str[20];
	int num,i=1;

	// 返回的是一个地址
	char *s;
	gets(ip);

	// 第二个参数是字符串
	s = strtok(ip, ".");
	while(s != NULL){
		num = atoi(s);
		itoa(num,str,2);
		printf("%s",str);
		
		if(i<=3){
			printf(".");
		    i++;
		}else{
			printf("\n");
		}
		
		s = strtok(NULL,".");
	}
}

void main(){

	fun20();
}
