#include <stdio.h>
#include <stdlib.h>
#include </media/lorenzo/Work/code/headers/C/LDN_basic.h>


/* prototypes */
void Array_Scan(int *array, int const DIM);
void Array_Print(int const *array, int const DIM);
int* Array_Scan_File(char* const path, int* DIM_ptr);
void Array_Print_File(int* const array, char* const path, int const DIM);
void Array_Bubble_Sort(int *array, int const DIM);


/* 1-----scan Array */
void Array_Scan(int *array, int const DIM)
{
    /* scan of the Array */
    printf("Scan the Array:\n");
    for(int i = 0; i < DIM; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d",&array[i]);
    }

    /* exit */
    return;
}


/* 2-----print Array */
void Array_Print(int const *array, int const DIM)
{
    
    /* print of the Array */
    printf("\n\nPrint the Array:\n");
    for(int i = 0; i < DIM; i++)
    {
        printf("Element %d: %d\t", i+1, array[i]);
        if(i == DIM - 1)
        {
            printf("\n");
        }
    }

    /* exit */
    return;
}


/* 3-----scan Array from a file */
int* Array_Scan_File(char* const path, int* DIM_ptr)
{
    /* variables initialization */
    int DIM, *array;
    FILE *fp = NULL;

    /* open the file */
    fp = fopen(path,"r");
    
    /* file not open */
    if(fp == NULL)
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

    /* scan the dimension */
    fscanf(fp, "%d", &(*DIM_ptr));
    DIM = *DIM_ptr;

    /* Array initialization */
    array = (int*)malloc(DIM * sizeof(int));

    /* scan the Array */
    for(int i = 0; i < DIM; i++)
    {
        fscanf(fp, "%d", &array[i]);
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return array;
}


/* 4-----print Array on a file */
void Array_Print_File(int* const array, char* const path, int const DIM)
{
    /* variables initialization */
    FILE *fp = NULL;

    /* open the file */
    fp = fopen(path,"w");
    
    /* file not open */
    if(fp == NULL)
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

    /* print the dimension */
    fprintf(fp, "%d\n", DIM);

    /* print the Array */
    for(int i = 0; i < DIM; i++)
    {
        fprintf(fp, "%d ", array[i]);
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return;
}


/* 5-----Bubble Sort Array */
void Array_Bubble_Sort(int *array, int const DIM)
{    
    /* Bubble Sort */
    printf("\nStart of the Bubble Sort...");
    for(int i = 0; i < DIM - 1; i++)
    {
        for(int j = 0; j < DIM - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                Swap(&array[j],&array[j+1]);
            }
        }
    }
    printf("\nArray has been Sorted!\n");

    /* exit */
    return;
}