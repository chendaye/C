#include <stdio.h> 
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

// �ж��ǲ�������
int fun3(){
	int n,i;

	scanf("%d",&n);

	if(n<3){
		printf("����С��3");
		return 0;
	}else{
		for(i=2;i<n-1;i++){
			if(n%i==0){
				printf("��������");
				return 0;
			}
		}
		printf("������");
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

// ���Լ�� ��С������ ��С������=(m*n)/���Լ��
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
	printf("%d����С������\n%d�����Լ��\n",min,max);
}


// ����һ���ַ� ͳ����ĸ �ո� ���� �������ĸ���
void fun6(){
	char c;
	int word=0,space=0,num=0,other=0;
	c=getchar();

	while(c!='\n'){
		// �ַ� '0'~'9' ռһ���ֽ�  ���� 0-9 ռ2��4�ֽ�
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


// ��׳�
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

// ˮ�ɻ���
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

// ����
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

// �������
void fun12(){
	double sum=0.0;
	int a=1,b=2,c=2,d=3;
	int i=1;
	double m,n;
	double s;

	sum=2.0/1.0+3.0/2.0;
	while(i<=18){
		// ����
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


// ���ӳ���
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


// ������
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


// ���ַ����
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

// ��ӡͼ��  �ҵ�һ�е������Ÿ���������ż ���ڴ�ӡ��ͬ�ķ���
void fun17(){
	int i,j;
	// ������
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

	// ������
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


// ѡ�񷨶�10����������
void fun18(){
	int a[5];
	int i,j;
	int tmp;



	for(i=0;i<5;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}

	printf("\n");

	// ���5����
	for(j=0;j<5;j++){
		printf("%5d",a[j]);
	}
	printf("\n");
	i=0;j=0;

	// ����
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


// 3*3����Խ��ߺ�
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


// ��˳�����
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

// ��������
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
	printf("��д��ĸ����=%d\nСд��ĸ����=%d\n�ո����=%d\n������ĸ����=%d\n",up,low,space,other);
	
}


// ���ͼ��
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


// ��һ�����򣬶����û�����ģ��ԡ�.����β��һ�����֣�ͳ��һ���ж��ٸ����ʣ����ֱ����ÿ�����ʺ��ж��ٸ��ַ��� 
//��������һ�������ո�����Ĳ��־�Ϊһ�����ʣ�

void fun26(){

	char str[100];
	int i=0,word=0,num=0;
	int start=0,end=0;
	gets(str);
	
	// �ַ��׿ո� ȥ��
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




// �����ĸ����  ���ʸ���  ������ĸ
void fun27(){
	int word=0,smb=0,i=0,j=0,max=0,count=0;
	char tmp;
	char s[100];
	gets(s);

	// ��ĸ����
	while(s[i] != '\0'){
		if(s[i] != ' '){
			smb++;
		}
		i++;
	}

	i=0;
	printf("��ĸ����=%d\n",smb);

	// ���ʸ���

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
	printf("���ʸ���=%d\n",word+1);
	

	// ����������ĸ �ʹ���
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

// �Ϸ���IP��ַ
void fun28(){
	char *s;
	char ip[36];
	gets(ip);
	
	// ��һ�ε��� ���� s
	s=strtok(ip,"."); // �ڶ��������ַ���
	while(s != NULL){
		// ������� ���� null
		printf("%s\n",s);
		s=strtok(NULL,".");
	}

	



}



void main() 
{ 
      
	//char a[6]= "abs",b[6]="sdf";
	//int c;
	//c=strcmp(a,b);
	//printf("%d\n",c);
	fun28();
} 

// �ַ�����������


// �󳤶�
// int strlen ( const char *str )  �����ַ�����ʵ�ʳ��ȣ����� '\0'��


//  �����ַ���
// char *strcpy( char *dest, const char *src )  ��src��ָ����� '\0'��β���ַ������Ƶ�dest��ָ���������
// char *strncpy(char *dest, const char *src, size_t n)   ������src�ַ�������ǰn���ַ�������dest��ָ�ĵ�ַ


// �Ƚ��ַ���
// int strcmp( char *str1, char *str2 )  �Ƚ�str1��str2�Ĵ�С;  ��ȷ���0��str1����str2����1��str1С��str2����-1��
// strncmp


// �����ַ���
// char *strcat(char *dest, const char *src)  ������src�ַ�������������dest��ָ���ַ���β
// strncat


// ���� �ַ�λ��
// char* strchr(const *s, int c)
// �����ҳ�����s�ַ����е�һ�����ֲ���c�ĵ�ַ��Ȼ�󽫸��ַ����ֵĵ�ַ����

// void* memchr(const void *s, int c, size_t n); 
// ��buf��ָ�ڴ������ǰn���ֽڲ����ַ�c  ����һ�������ַ�cʱֹͣ���ҡ�����ɹ�������ָ���ַ�c��ָ�룻���򷵻�NULL  ��strchr��ͬ������������'\0'������

// char* strstr(const char *haystack, const char *needle)  
// Strstr()����ַ��� haystack����Ѱ�ַ���needle��������һ�γ��ֵĵ�ַ����  ����ָ���ַ�����һ�γ��ֵĵ�ַ�����򷵻�0


// �ָ��ַ���  
// char *strtok(char *s, const char *delim);
// �ֽ��ַ���Ϊһ���ַ�����sΪҪ�ֽ���ַ�����delimΪ�ָ����ַ���

// �����ַ���
// char *strset(char *s, char c);  
// ���ַ���s�е������ַ������ó��ַ�c

// void *memset(void *s, int ch, size_t n);  
// ��������һ���ڴ�������ĳ��������ֵ�����ǶԽϴ�Ľṹ�������������������һ����췽��  ��strset��ͬ������'\0'�����������Ҫ������Ҫ���õĿռ��С��

