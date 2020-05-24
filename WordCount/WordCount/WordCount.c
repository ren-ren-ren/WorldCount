#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//统计字符数
void CharCount()
{
    FILE *fp;
    int charCount = 0;
    if((fp = fopen("test.txt","r")) == NULL)
    {
        printf("文件打开失败.");
		exit(1);
    }
    while(fgetc(fp) != EOF)
    {
            charCount++;
    }
	fclose(fp);
    printf("字符数为：%d个.\n",charCount);
}
//统计单词数
void WordCount() 
{
    FILE *fp;
	char ch;
    int wordCount = 1;
    if((fp = fopen("test.txt","r")) == NULL)
    {
        printf("文件打开失败.");
		exit(1);
    }
	ch = fgetc(fp);
    while(ch != EOF)
    {
        if (ch == ' ' || ch == ',')
        {
			wordCount++;
			ch = fgetc(fp);
        }
		else
		{
			ch = fgetc(fp);
		}
    }
	fclose(fp);
    printf("单词数为：%d个.\n",wordCount);
}

int main(int argc,char *argv[])
{
	//统计单词数
    if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        WordCount();
    }
	//统计字符数
    if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        CharCount();
    }
    return 0;
}
