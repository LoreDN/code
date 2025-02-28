#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 999 


/* prototypes */
char* String_Scan(char *string);
void String_Print(char const *string);


/* 1-----scan String */
char* String_Scan(char *string)
{
    /* variables initialization */
    char temp[MAX_LENGTH];

    /* get a String */
    printf("Enter a String: ");
    fgets(temp, MAX_LENGTH, stdin);

    /* copy the String */
    string = (char*)malloc(strlen(temp));
    strcpy(string,temp);

    /* exit */
    return string;
}


/* 2-----print String */
void String_Print(char const *string)
{
    /* empty String */
    if (string == NULL)
    {
        printf("The String is empty\n");
    }
    /* existing String */
    else
    {
        printf("The String is: ");
        puts(string);
    }

    /* exit */
    return;
}


/* 3-----scan String from a file */
char* String_Scan_File(char *string, char const *path)
{
    /* variables initialization */
    char temp[MAX_LENGTH];
    FILE *fp;

    /* open the file */
    fp = fopen(path, "r");

    /* file not open */
    if (fp == NULL)
    {
        printf("\nError: file not found!\n");

        /* exit */
        return NULL;
    }
    /* file open correctly */
    else
    {
        printf("\nFile %s found!\n", path);
    }

    /* get a String */
    fscanf(fp, "%[^\n]", temp);

    /* copy the String */
    string = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(string,temp);

    /* close the file */
    fclose(fp);

    /* exit */
    return string;
}


/* 4-----print String on a file */
void String_Print_File(char const *string, char const *path)
{
    /* empty String */
    if (string == NULL)
    {
        printf("The string is empty\n");
    }
    /* existing String */
    else
    {
        /* variables initialization */
        FILE *fp;

        /* open the file */
        fp = fopen(path, "w");

        /* file not open */
        if (fp == NULL)
        {
            printf("\nError: file not found!\n");

            /* exit */
            return;
        }
        /* file open correctly */
        else
        {
            printf("\nFile %s found!\n", path);
        }

        /* print the String */
        fputs(string, fp);

        /* close the file */
        fclose(fp);
    }

    /* exit */
    return;
}