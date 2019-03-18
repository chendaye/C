// 输入一行字符 统计字母 空格 数字 和其他的个数
void fun6()
{
    char c;
    int word = 0, space = 0, num = 0, other = 0;
    c = getchar();

    while (c != '\n')
    {
        // 字符 '0'~'9' 占一个字节  整数 0-9 占2或4字节
        if (c >= '0' && c <= '9')
        {
            num++;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            word++;
        }
        else if (c == ' ')
        {
            space++;
        }
        else
        {
            other++;
        }

        c = getchar();  //  xu'na循环输入
    }
    printf("word=%d,space=%d,num=%d,other=%d\n", word, space, num, other);
}

// S=a + aa + aaa  n=3  a2=a1*10 + a
void fun7(int a)
{
    int n, i = 1;
    double sum = 0.0;
    int m, x;
    scanf("%d", &n);

    while (i <= n)
    {
        m = n - i;
        x = 1;
        while (m > 0)
        {
            x *= 10;
            m--;
        }
        sum = sum + a * x * i; //  a*x  有 i 个  a00 有1个  a0有2个  a有3个
        i++;
    }

    printf("%f\n", sum);
}

// 选择法对10个整数排序
void fun18()
{
    int a[5];
    int i, j;
    int tmp;

    for (i = 0; i < 5; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }

    printf("\n");

    // 输出5个数
    for (j = 0; j < 5; j++)
    {
        printf("%5d", a[j]);
    }
    printf("\n");
    i = 0;
    j = 0;

    // 选择排序
    for (i = 0; i < 5; i++)
    {
        for (j = i; j < 5; j++)
        {
            if (a[j] > a[i])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    for (j = 0; j < 5; j++)
    {
        printf("%5d", a[j]);
    }

    printf("\n");
}

// 3*3矩阵对角线和
void fun19()
{
    int a[3][3];
    int i, j;
    int sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            //printf("a[%d][%d]=",i,j);
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                sum += a[i][j];
            }
        }
    }

    printf("%d\n", sum);
}

// 合法的IP地址
void fun28()
{
    char *s;
    char ip[36];
    int flag = 1;
    gets(ip);

    // 第一次调用 参数 s
    s = strtok(ip, "."); // 第二个参数字符串
    while (s != NULL)
    {
        // 后序调用 参数 null
        s = atoi(s);

        if (s > 255 || s < 0)
        {
            flag = 0;
        }
        printf("%d\n", s);
        s = strtok(NULL, ".");
    }

    if (flag != 1)
    {
        printf("%s\n", "非法IP");
    }
    else
    {
        printf("%s\n", "合法IP");
    }
}

// n个数排序
void fun31()
{
    int num[6];
    int i;
    for (i = 0; i < 6; i++)
    {
        num[i] = getchar();
    }

    i = 0;
    for (i = 0; i < 6; i++)
    {
        printf("%d\n", num[i]);
    }
}

// 冒泡排序
void fun32()
{

    int num[6];

    int i, j, n;
    int tmp;

    for (i = 0; i < 6; i++)
    {

        printf("a[%d]\n", i);
        scanf("%d", &num[i]);
    }

    n = sizeof(num);
    printf("\n%d\n", n);
    n = 6;
    // 冒泡排序
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (num[j - 1] < num[j])
            {
                tmp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = tmp;
            }
        }
    }

    printf("\n");

    for (i = 0; i < 6; i++)
    {

        printf("%d\n", num[i]);
    }
}

// 把str2 接到 str1 后面； 注意用数组
void fun1()
{
    char str1[100] = "chen";
    char str2[100] = "daye";
    char *str3;
    strcat(str1, str2);
    printf("%s\n", str1);
}

// strcat
void fun2()
{
    char str1[100] = "chen";
    char str2[100] = "daye";
    char *str3;
    strcpy(str1, str2);
    printf("%s\n", str1);
}

// strchr 返回地址 没有返回0
void fun3()
{
    char str[100] = "chendaye666";
    char c = 'z';
    int a;
    a = strchr(str, c);
    printf("%d\n", a);
}

void fun4()
{
    char str1[100] = "chendaye66";
    char str2[10] = "zz";
    int a;
    char s;

    a = strstr(str1, str2);
    s = a;
    printf("%s\n", s);
    printf("%d\n", a);
}

void fun5()
{
    char num[1000];
    int sign[10];
    int i, j;
    gets(num);
    for (i = 0; i < 10; i++)
    {
        sign[i] = 0;
    }
    j = 0;
    while (num[j] != '\0')
    {
        printf("%c\n", num[j]);
        switch (num[j])
        {
        case '0':
            sign[0]++;
            break;
        case '1':
            sign[1]++;
            break;
        case '2':
            sign[2]++;
            break;
        case '3':
            sign[3]++;
            break;
        case '4':
            sign[4]++;
            break;
        case '5':
            sign[5]++;
            break;
        case '6':
            sign[6]++;
            break;
        case '7':
            sign[7]++;
            break;
        case '8':
            sign[8]++;
            break;
        case '9':
            sign[9]++;
            break;
        default:
            break;
        }
        j++;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d:%d\n", i, sign[i]);
    }
}

void fun6()
{
    printf("%d\n", 'a' - 'A');
    printf("%d\n", 'Z' - 'z');
    printf("%d\n", '1' - 1);
}

void fun7()
{
    // 十进制到二进制
    int num;
    int arr[32];
    int c, i = 0;
    scanf("%d", &num);
    while (num != 0)
    {
        c = num % 2; // 除2取余数
        arr[i] = c;
        num /= 2; // 不断除2
        i++;
    }
    for (i--; i >= 0; i--)
    {
        // 逆序输出
        printf("%d", arr[i]);
    }
    printf("\n");
}

void fun8()
{
    // 十进制转 八进制
    int num;
    // printf("%o\n", num); 直接输出
    int arr[32];
    int c, i = 0;

    scanf("%d", &num); // &
    while (num != 0)
    {
        c = num % 8;
        arr[i] = c;
        num /= 8;
        i++;
    }
    for (i--; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void fun9()
{
    // 十进制到十六进制
    int num;
    // printf("%x\n", num); 直接输出
    char arr[32];
    int c, i = 0;
    char ox[16] = "0123456789ABCDEF"; // 十六进制
    scanf("%d", &num);
    while (num != 0)
    {
        c = num % 16;
        arr[i] = ox[c];
        num /= 16;
        i++;
    }
    for (i--; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

void fun10()
{
    // 二进制到十进制  二进制用整型存储
    long bin;
    int ten = 0;
    int c, i = 0;
    scanf("%ld", &bin);
    while (bin != 0)
    {
        c = bin % 10;
        bin /= 10; // 取每一位上的数
        ten += c * pow(2, i);
        i++;
    }
    printf("%d\n", ten);
}

void fun11()
{
    // 八进制转十进制  八进制用十进制存储
    int o;
    int ten = 0;
    int c, i = 0;

    scanf("%d", &o);
    while (o != 0)
    {
        c = o % 10;
        o /= 10;
        ten = c * pow(8, i);
        i++;
    }
    printf("%d\n", ten);
}

void fun12()
{
    // 十六进制 到 十进制 直接格式化打印
    int num = 0;
    printf("输入一个十六进制数: ");
    scanf("%x", &num);
    printf("十六进制数 %x 转换为十进制为 %d\n", num, num);
}

// 开根号 sqrt()
// arcsin(x)arccos(x)arctan(x)arccot(x)

// sin(x*180/3.1415926)

// arcsin(x)arccos(x)arctan(x)arccot(x)
//调用三角函数之前先把角度换算成弧度，调用反三角函数之后把弧度换算成角度
//1度=π/180≈0.01745弧度，1弧度=180/π≈57.3度

// 字符数字 - 48 = 整型数字

// +++++++++++++++++++++++++++++++++++++++++++++字符串+++++++++++++++++++++++++++++++++++++++++

// scanf() 以Space、Enter、Tab结束一次输入，不会舍弃最后的回车符
// getchar() 以Enter结束输入，也不会舍弃最后的回车符
// gets() 以Enter结束输入（空格不结束），接受空格，会舍弃最后的回车符！

// int strlen ( const char *str )  返回字符串的实际长度，不含 '\0'。

// 分割字符串
// char *strtok(char *s, const char *delim);
// 分解字符串为一组字符串。s为要分解的字符串，delim为分隔符字符串

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

// 设置字符串
// char *strset(char *s, char c);
// 把字符串s中的所有字符都设置成字符c

// void *memset(void *s, int ch, size_t n);
// 作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法  与strset不同，遇到'\0'不会结束，需要给定所要设置的空间大小。

// itoa()：整型值->字符串 char *  itoa ( int value, char * buffer, int radix ); value, 是要转换的数字 buffer, 是存放转换结果的字符串 radix ??
// ltoa()：长整型值->字符串
// ultoa()：无符号长整型值->字符串
// atoi()：字符串->整型值
// atol()：字符串->长整型值
// atof()：字符串->双精度浮点型值

// gcvt()：浮点型数->字符串，取四舍五入
// ecvt()：双精度浮点型值->字符串，转换结果中不包含十进制小数点
// fcvt()：指定位数为转换精度，其余同ecvt()

// strtod()：字符串->双精度浮点型值，并报告不能被转换的所有剩余数字
// strtol()：字符串->长整值，并报告不能被转换的所有剩余数字
// strtoul()：将字符串->无符号长整型值，并报告不能被转换的所有剩余数字。

// +++++++++++++++++++++++++++++++++++++++++++++数学+++++++++++++++++++++++++++++++++++++++++

// sqrt  extern float sqrt(float x);  计算x的平方根
// abs   extern int abs(int x);    求整数x的绝对值  fabs extern float ceil(float x);  求浮点数x的绝对值
// ceil  不小于x的最小整数  floor  extern float floor(float x); 求不大于x的最达整数
// exp   extern float exp(float x);  求e的x次幂
// pow   extern float pow(float x, float y); 计算x的y次幂
// modf  extern float modf(float num, float *i); 将浮点数num分解成整数部分和小数部分；返回小数部分，将整数部分存入*i所指内存中
// fmod  extern float fmod(float x, float y);  计算x/y的余数
// log   extern float log(float x);  计算x的自然对数    log10  extern float log10(float x);  计算x的常用对数
