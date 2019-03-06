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

void main(){

	
	fun10();
	
}

// 开根号 sqrt()
// arcsin(x)arccos(x)arctan(x)arccot(x)

// sin(x*180/3.1415926)

// arcsin(x)arccos(x)arctan(x)arccot(x)
//调用三角函数之前先把角度换算成弧度，调用反三角函数之后把弧度换算成角度
//1度=π/180≈0.01745弧度，1弧度=180/π≈57.3度


// 字符数字 - 48 = 整型数字