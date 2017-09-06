#include <stdio.h>
#include <stdlib.h>

char c1, c2, c3;
char *cp;

void setup()
{
	c1 = 'a'; //97
	c2 = 'b'; //98
	c3 = 'c'; //99
	cp = &c1;
}

//参数 指针的指针
int findchar(char **strings, char value)
{
	char *string;
	string = *strings;
	while (string !=NULL)
	{
		while (*string != '\0')
		{
			if (*string == value)
			{
				return 1;
			}
			string++;
		}
		string = *strings++;
	}
	return 0;
}

int* findint(int key, int array[], int arraylen)
{
	int i;
	int *point;
	
	for (i = 0; i < arraylen; i++)
	{
		point = array++;
		if (*point == key)
		{
			return point;
		}
	}
	return NULL;
}

void swap(int *x, int*y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int leapyear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

typedef struct
{
	unsigned long id;
	int score;
} record;

int idcmp(const void *s1, const void *s2)
{
	record *p1 = (record *)s1;
	record *p2 = (record *)s2;

	if (p1->id > p2->id)
	{
		return 1;
	}
	else if (p1->id == p2->id)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int scorecmp(const void *s1, const void *s2)
{
	record *p1 = (record *)s1;
	record *p2 = (record *)s2;

	if (p1->score > p2->score)
	{
		return 1;
	}
	else if (p1->score == p2->score)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

typedef void(*intFunc)(int i);

void foreachNums(int *nums, int len, intFunc func)
{
	int i;
	for (i = 0; i < len; i++)
	{
		int n = nums[i];
		func(n);
	}
}

void pintint(int i)
{
	printf("value= %d\n",i);
}
void add100(i)
{
	printf("value= %d\n", i+100);
}


int maxnum(int *nums, int len)
{
	int i;
	int max = nums[0];
	for (i = 1; i < len; i++)
	{
		if (max < nums[i])
		{
			max = nums[i];
		}
	}

	return max;
}

typedef int(*compareFunc)(void *data1, void *data2);


void *maxNum(void *data, int unitSize, int size,compareFunc func)
{
	int i;
	char *ptr = (char*)data;
	char *max = ptr;

	for (i = 1; i < size; i++)
	{
		char *item = ptr + i*unitSize;
		if (func(item, max)>0)
		{
			max = item;
		}
	}

	return max;
}

int intcompare(void *data1, void *data2)
{
	int *ptr1 = (int*)data1;
	int *ptr2 = (int*)data2;

	return *ptr1 - *ptr2;

}

typedef struct
{
	char *name;
	int age;
}Dog;

int dogcompare(void *data1, void *data2)
{
	Dog *dog1 = (Dog*)data1;
	Dog *dog2 = (Dog*)data2;
	
	//return dog1->age - dog2->age;
	return dog2->age - dog1->age;
}

int main()
{
	int *nums = (int*)malloc(sizeof(int) * 10);
	nums[0] = 1;
	nums[1] = 8;
	free(nums);

	int i = 10;
	int *p = &i;
	int **pp = &p;
	
	printf("二级指针变量pp指向地址:%d\n", pp);
	printf("变量p的地址:%d\n", &p);
	printf("一级指针变量p指向地址:%d\n", p);
	printf("变量i的地址:%d\n", &i);

	printf("i= %d\n", i);
	printf("p= %d\n", p);
	printf("*p= %d\n", *p);
	printf("pp= %d\n", pp);
	printf("*pp= %d\n", *pp);
	printf("**pp= %d\n", **pp);

	printf("&i= %d\n", &i);
	printf("&p= %d\n", &p);	
	printf("&pp= %d\n", &pp);
	

#if(0)
	int nums[] = {1,5,666,2355,665};	
	//printf("value= %d\n", maxnum(nums,5));
	int *ptr = maxNum(nums,sizeof(int),sizeof(nums)/sizeof(int),intcompare);
	//printf("value= %d\n", *ptr);

	Dog dogs[] = {{"沙皮",3},{"哈士奇",10},{"腊肠",5},{"京巴",8},{"藏獒",2}};

	//Dog *pdog = maxNum(dogs,sizeof(Dog),sizeof(dogs)/sizeof(Dog),dogcompare);

	//printf("value= %d%s\n", pdog->age,pdog->name);

	qsort(dogs,sizeof(dogs)/sizeof(Dog),sizeof(Dog), dogcompare);
	int i;
	for (i = 0; i < sizeof(dogs)/sizeof(Dog); i++)
	{
		Dog dog = dogs[i];
		printf("value= %d|%s\n", dog.age,dog.name);
	}


	int nums[] = {1,5,666,2355,665};

	foreachNums(nums, sizeof(nums) / sizeof(int), pintint);
	foreachNums(nums, sizeof(nums) / sizeof(int), add100);


	record recordArray[] = { { 3, 99 }, { 5, 87 }, { 4, 56 }, { 2, 100 }, { 1, 17 } };

	int recordCount = sizeof(recordArray) / sizeof(record);
	printf("排序前: \n");

	for (int i = 0; i < recordCount; i++)
	{
		printf("%8d %8u %8d\n", i, recordArray[i].id, recordArray[i].score);
	}

	//qsort(recordArray, recordCount, sizeof(record), idcmp);
	qsort(recordArray, recordCount, sizeof(record), scorecmp);

	printf("排序后: \n");

	for (int i = 0; i < recordCount; i++)
	{
		printf("%8d %8u %8d\n", i, recordArray[i].id, recordArray[i].score);
	}


	int year;
	int result;

	int(*p)(int year);
	p = leapyear;

	//result = leapyear(2016);
	result = (*p)(2015);
	printf("%d\n", result);



	int m=10;
	int n =20;

	printf("m: %d\n", m);
	printf("n: %d\n", n);

	swap(&m,&n);
	printf("m: %d\n", m);
	printf("n: %d\n", n);



	int a[10] = {1,3,5,7,9,0,2,4,6,8};
	int *result;
	result = findint(6,a,10);
	if(result == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		printf("找到了: %d\n", *result);

		*result = *result*10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
	

	//数组strs中有5个指针,每个字符指针都指向一个字符串
	char *strs[5];
	char *s1 = "A string";
	char *s2 = "Another";
	char *s3 = "Third";
	char *s4 = "Last";
	char *s5 = NULL; //也可以写 NULL

	strs[0] = s1;
	strs[1] = s2;
	strs[2] = s3;
	strs[3] = s4;
	strs[4] = s5;

	//strs是一个指针数组,每个成员都是指针,指向第一个成员指针的地址 所以是指针的指针
	if (findchar(strs, 'k'))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}



	setup();
	printf("%c,%c,%c\n", c1, c2, c3);
	printf("%d,%d,%d\n", c1,c2,c3);
	printf("%d,%d,%d\n", &c1, &c2, &c3);

	printf("%d\n", &c1);
	printf("%d\n", cp);
	printf("%d\n", &cp);
	printf("%d\n", *cp);
	printf("%d\n", *cp+1);
	printf("%d\n", *(cp-1));
	printf("%d\n", ++cp);


	int a;
	int b;
	float c;

	a = 12;
	b = -1;
	c = 3.14;
	printf("%d\n", &a);

	long i = (long)&a;

	*(int*)i = 36;
	printf("%d\n", a);
#endif
	
	system("pause");
	return 0;
}