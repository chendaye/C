#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// ���ӳ���
void fun1(){
	int i,total=1;

	for(i=1;i<10;i++){
		total = (total+1)*2;
	}

	printf("%d\n",total);
}


// ���������� == 쳲���������
// �ӵ���������ʼ ÿһ����=ǰ������֮��
void fun2(){
	long int f1,f2;
	int i;
	f1=f2=1;  // ǰ�����¶���һ������
	//40���¾ͺ��ˣ�����Ҳû��˼���ǰ�
	for(i=1;i<=20;i++) 
	{	
		printf("%12ld %12ld",f1,f2); //����ÿ���µ����־Ͳ�����һ���ˣ��м���пո���Ϊ�ǳ���������ld 12ld����˵���ܹ�ռ12λ
		if(i%2==0) printf("\n");
		f1=f1+f2; //����µ���ǰ������֮�Ͱ�
		f2=f1+f2; //ͬ��
	}
}

// �����ֽ�������   ���ÿ���ʲô����
void fun3(){
	int n;
	int i;
	
	scanf("%d",&n);

    printf("%d=",n);
	// ������2��ʼ ����
	for(i=2;i<=n;i++){
		while(n>=i){
			if(n%i==0){
				printf("%d",i);
				if(n!=i){
					printf("*");
				}
				// ÿ�ҵ�һ������ ��n�� ʣ�µļ����ֽ�����
				n=n/i;
			}else{
				break;
			}
		}
	}
	printf("\n");
}


// ��һ���������ֵ�λ�� �ʹ���
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
			printf("λ��%d\n",i+1);
		}
	}
	printf("���ִ���%d\n",count);

}

// ����A����С���ظ���

int funto5(int n){
	// �ж��ǲ����ظ���
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

	printf("û��С��1000��\n");
	
}


// ��ֶκ���
void fun6(){
	double  x;
	double  res;
	scanf("%lf",&x);
	//printf("%6.4lf\n",x);
	if(x>0){
		res = (sqrt(x)+exp(x))/(5*x+5);
	}else{
		// ��60�� ת��Ϊ����
		res = (2/3 + sin(3.1415926/180*60))*abs(x);
	}

	printf("%6.4lf\n",res);
}


// ��assic��ֵ����
void fun7(){

	char str[100];
	int len,i,j;
	char tmp;
	gets(str);

	len = strlen(str);
	printf("%d\n",len);
	// ð������
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

// 2��1000֮���������  ��ʽ֮��=����
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

// �ж��ַ��ĺϷ���
// ����������
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
		printf("���ȱ�����ڵ���10��\n");
		return;
	}else if(!((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))){
		printf("����ĸ��������ĸ!\n");
		return;
	}else{
		printf("fuck\n");
		for(i=0;i<len;i++){
			if(str[i] == '=' || str[i] == '*'){
				printf("���ܺ���= *");
				return;
			}
			

			if(str[i]>='0' && str[i]<='9'){
				// �ַ����ֻ�Ϊ����
				sw=str[i]-48;
				if(num[sw] == 0){
					printf("%d\n",sw);
					num[sw] = 1;
				}else{
					printf("���ֲ����ظ���%c,%d\n",str[i],sw);
					return;
				}
			}
		}

		for(i=0;i<10;i++){
			if(num[i]==1){
				sum++;
			}
		}

		 // ��û��>= <=
		printf("%d\n",sum);
		if(sum<=6 && sum >=2){
			printf("�ϸ�");
		}else{
			printf("���ظ�������Ҫ2-6��%d\n",sum);
		}


	}


}

void fun10(){
	
	// ����ת�ַ���  ע���ַ���Ҫ������洢
	int n=123;
	char  y[4];
	// �ַ���ת����  �ַ���������  ˫����
	char s[4]="123";
	int x;
	

	// �ַ���������
	x = atoi(s );
	printf("%d\n", x);

	// ���ֵ��ַ���  2����ʾת����2�����ַ���
	itoa(n,y,2);
	printf("%s\n",y);

	// ���������ַ�ת���� ����
	printf("%d\n",'6'-48);
}

void main(){

	
	fun10();
	
}

// ������ sqrt()
// arcsin(x)arccos(x)arctan(x)arccot(x)

// sin(x*180/3.1415926)

// arcsin(x)arccos(x)arctan(x)arccot(x)
//�������Ǻ���֮ǰ�ȰѽǶȻ���ɻ��ȣ����÷����Ǻ���֮��ѻ��Ȼ���ɽǶ�
//1��=��/180��0.01745���ȣ�1����=180/�С�57.3��


// �ַ����� - 48 = ��������