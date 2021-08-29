#include <stdio.h>
#include <stdlib.h>

#define GET_LEN(x)(sizeof(x) / sizeof(int))

int main(int argc, char **argv)
{
    int a[] = { 5, 7, 9, 11, 88, 45, 37, 48 };
    int *ptr = NULL;
    ptr = a;

    int len = ( (int)GET_LEN(a) );

    printf("size of array: %d\n", sizeof(a));
    printf("Number of elements: %d\n", len);

    int i = 1;
    while(len--)
    {
        printf("%d\n", *ptr++);
        //ptr++; noob shit
    }

    //ptr is pointing out of range of array
    printf("ending value: %d\n", *--ptr);

    ptr = a;
    puts("reset pointer");
    printf("first num in array %d\n", ptr[0]);

    int arg = 1;
    while(argc--)
    {
	printf("arg %d: ", arg);
	puts(*argv++);
	arg++;
    }

    //lets read in a file because fuck it 
    FILE *fp = NULL;

    fp = fopen("test.txt", "r");

    if(fp == NULL) { puts("you done fucked up"); return - 1;}

    int filesize = 0;
    int filelimit = 64;
    char c = fgetc(fp);
    while(c != EOF)
    {
	printf("%c", c);
	c = fgetc(fp);
	filesize++;
    }

    fclose(fp);

    //now lets add some shit to it
    fp = fopen("test.txt", "a+");

    if(fp == NULL) { puts("You done fucked up"); return - 1;}

    char msg[] = "this is added to file\n";

    int stat = fprintf(fp, msg);

    fclose(fp);

    if(filesize >= filelimit)
    {
	system("rm test.txt; touch test.txt; echo 'New File' >> test.txt");
	printf("File size exceded %d bytes. deleting file\n", filelimit);
    }
    return 0;
}
