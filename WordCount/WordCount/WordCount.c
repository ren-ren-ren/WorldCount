#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//ͳ���ַ���
void CharCount()
{
    FILE *fp;
    int charCount = 0;
    if((fp = fopen("test.txt","r")) == NULL)
    {
        printf("�ļ���ʧ��.");
		exit(1);
    }
    while(fgetc(fp) != EOF)
    {
            charCount++;
    }
	fclose(fp);
    printf("�ַ���Ϊ��%d��.\n",charCount);
}
//ͳ�Ƶ�����
void WordCount() 
{
    FILE *fp;
	char ch;
    int wordCount = 1;
    if((fp = fopen("test.txt","r")) == NULL)
    {
        printf("�ļ���ʧ��.");
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
    printf("������Ϊ��%d��.\n",wordCount);
}

int main(int argc,char *argv[])
{
	//ͳ�Ƶ�����
    if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        WordCount();
    }
	//ͳ���ַ���
    if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        CharCount();
    }
    return 0;
}
