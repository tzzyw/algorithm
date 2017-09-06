#if(0)
#define _CRT_SECURE_NO_DEPRECATE
#include "CriticalPath.h"  
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_LENGTH 26 //索引表最大长度
#define WORD_LENGTH 20 //单词最大长度

//单词
typedef struct Word
{
	char English[WORD_LENGTH];
	char Chinese[WORD_LENGTH];
	struct Word *next;
}Word, *PWordList;

//索引项
typedef struct
{
	char ch;        //索引值
	PWordList pWord;//指向单词链表
}Index;


Index indexTable[MAX_LENGTH];  //索引表
int length;                    //索引表长度

//二分查找法查找索引表,若找到返回下标，查找失败，返回要插入的位置
int binarySearch(char ch, int low, int high)
{
	int mid = (low + high) / 2;
	if (low>high)
		return low;
	if (indexTable[mid].ch == ch)
		return mid;
	else if (indexTable[mid].ch>ch)
		binarySearch(ch, low, mid - 1);
	else
		binarySearch(ch, mid + 1, high);
}

//从文件中读入单词，建立字典
void createDictionary()
{
	FILE *fp;
	char str[WORD_LENGTH * 3];
	PWordList Pword = 0;
	int i, j, m = 0, index;

	if ((fp = fopen("document/dictionary.txt", "r")) == NULL){
		printf("can not open file!\n");
		exit(0);
	}

	while (!feof(fp)){
		Pword = (PWordList)malloc(sizeof(Word));
		i = j = m = 0;
		fgets(str, WORD_LENGTH * 3, fp);
		while (str[i] != '\n'){
			if (m == 0){
				if (str[i] == ' '){
					m = 1;
					Pword->English[j] = '\0';
					j = 0;
				}
				else{
					if (str[i] >= 'A'&&str[i] <= 'Z')
						str[i] += 32;
					Pword->English[j++] = str[i];
				}
			}
			if (m == 1){
				if (str[i] != ' ')
					Pword->Chinese[j++] = str[i];
			}
			i++;
		}
		Pword->Chinese[j] = '\0';

		//取单词的首字母，查找索引表，若存在，把这个单词插入这个索引指向的分组中，不存在，则插入索引和单词
		index = binarySearch(Pword->English[0], 0, length - 1);
		if (indexTable[index].ch == Pword->English[0]){//查到该索引
			Pword->next = indexTable[index].pWord;
			indexTable[index].pWord = Pword;
		}
		else{//查找失败
			for (i = length; i >= index; i--)
				indexTable[i + 1] = indexTable[i];
			length++;
			indexTable[index].ch = Pword->English[0];
			Pword->next = NULL;
			indexTable[index].pWord = Pword;
		}

		//	printf("%-10s%-10s\n",word.English,word.Chinese);
	}

	if (fclose(fp)){
		printf("can not close file!\n");
		exit(0);
	}
}

//查找单词,不成功返回NULL，成功返回这个单词
PWordList search(char *word)
{
	int i = 0, index;
	PWordList p = 0;
	PWordList pWord = NULL;
	while (word[i]){
		if (word[i] >= 'A'&&word[i] <= 'Z')
			word[i] += 32;
		i++;
	}
	index = binarySearch(word[0], 0, length - 1);
	if (indexTable[index].ch == word[0]){//查到该索引
		p = indexTable[index].pWord;
		while (p){
			if (strcmp(p->English, word) == 0){
				pWord = (PWordList)malloc(sizeof(Word));
				strcpy(pWord->Chinese, p->Chinese);
				strcpy(pWord->English, p->English);
				pWord->next = NULL;
				break;
			}
			p = p->next;
		}
	}
	return pWord;
}

int main()
{
	PWordList p = 0;
	char word[WORD_LENGTH];
	createDictionary();
	printf("请输入要查找的单词：\n");
	gets(word);
	p = search(word);
	if (p){
		printf("找到该单词：\n%-20s%-20s\n", p->English, p->Chinese);
		free(p);
	}
	else
		printf("你查找的单词不存在!\n");

	system("pause");
	return 0;

}
#endif