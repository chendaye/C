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



// �ݹ�ʵ�ִ�һԪ
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


// ȥ�������С����ƽ����
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

// ��һ�����е���������

// ������ �� sizeof(x)/sizeof((x)[0])
void fun14(){
	int n[6] = {2,4,7,8,13,17};

	int count=0;
	int i = 0,j;
	int flag;
	int len=0;
	//������ ��
	len= sizeof(n)/sizeof(n[0]);

	while(i<len){
		flag = 1; // ����������
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

// �ַ�
void fun15(){
	char s[7]="qwerty";
	int len = sizeof(s)/sizeof(s[0]);

	int len2 = strlen(s);

	printf("%d\n%d\n",len,len2);  // len=7  '\0' Ҳ������; len2=6
}


// ��ӡͼ��
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

// ��ӡ쳲��������У�30��������ͳ�����е�����

// �ж��Ƿ��������� Ҫ�ų�1
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
		flag = 0; // 1 ��������
	}
	return flag;
}
// 쳲��������еĵݹ�
void fun17(int f1, int f2, int count, int total){

	if(total>30){
		return;
	}else{
		if(is_prime(f1) == 1){
			count++;
			printf("%d��������\n", f1);
		}
		if(is_prime(f2) == 1){
			count++;
			printf("%d��������\n", f2);
		}

		printf("\n");

		printf("  %d  %d\n", f1,f2);

		// 쳲��������еĵݹ�
		f1 = f1+f2;
		f2 = f1+f2;
		total+=2;

		// �ݹ�
		fun17(f1,f2,count,total);

	}
}

// ��������2��3��5���������������8������ӡ��ʾ�������
void fun18(){
	int ball[] = {2,3,5};

	int i,j,k;

	// ����i��
	for(i=1;i<=2;i++){
		// ����j��
		for(j=1;j<=3;j++){
			// ����ĸ��� ��=5 
			k = 8-i-j;
			if(k <= 5){
				// Ҫ��Ĳ��������У� ����ÿ������ж��ٸ�
				printf("%d��,%d��,%d��\n", i,j,k);
			}
		}
	}
	
}


// �����ָ�

int c[10]; 
void fun(int n,int m,int index){ //m��ʾ��һ���ӵ�����n��ʾʣ��û�ӵ���֮�� 
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
			// �ݹ�
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


// ��ӡip
void fun20(){

	char ip[20];
	char str[20];
	int num,i=1;

	// ���ص���һ����ַ
	char *s;
	gets(ip);

	// �ڶ����������ַ���
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
