#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main(){

	char a[10];
	//char *a;
	int i=0,j=0;
	scanf("%s",&a);  // �����ո�ض�  gets() ����
	i = strlen(a);
	j = sizeof(a)/sizeof(a[0]);
	printf("%s\n", a);
	printf("%d\n", i);
	printf("%d\n",j);
}