#include <stdio.h>
#include <stdlib.h>
#include </media/lorenzo/Work/code/headers/C/LDN_basic.h>


/* prototypes */
void Matrix_Scan(int *matrix, int const ROWS, int const COLS);
void Matrix_Print(int const *matrix, int const ROWS, int const COLS);
int* Matrix_Scan_File(char* const path, int* DIM_ptr);
void Matrix_Print_File(int* const matrix, char* const path, int const ROWS, int const COLS);
void Matrix_Bubble_Sort(int *matrix, int const ROWS, int const COLS);


/* 1-----scan Matrix */
void Matrix_Scan(int *matrix, int const ROWS, int const COLS)
{
    /* scan of the Matrix */
    printf("Scan the Matrix:\n");
    for(int i = 0; i < ROWS; i++)
    {
        printf("Row %d\n", i+1);
        for(int j = 0; j < COLS; j++)
        {
            printf("Element %d%d: ", i+1, j+1);
            scanf("%d",&matrix[i*COLS + j]);
        }
    }

    /* exit */
    return;
}


/* 2-----print Matrix */
void Matrix_Print(int const *matrix, int const ROWS, int const COLS)
{
    /* printf of the Matrix */
    printf("\n\nPrint the Matrix:\n");
    for(int i = 0; i < ROWS; i++)
    {
        printf("Row %d\n", i+1);
        for(int j = 0; j < COLS; j++)
        {
            printf("%d%d: %d\t", i+1, j+1, matrix[i*COLS + j]);
            if (j == COLS -1)
            {
                printf("\n");
            }
        }
    }

    /* exit */
    return;
}


/* 3-----scan Matrix from a file */
int* Matrix_Scan_File(char* const path, int* DIM_ptr)
{
    /* variables initialization */
    int ROWS, COLS, *matrix;
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

    /* scan the dimensions */
    for(int i = 0; i < 2; i++)
    {
        fscanf(fp, "%d", &(DIM_ptr[i]));
    }
    ROWS = DIM_ptr[0];
    COLS = DIM_ptr[1];

    /* matrix initialization */
    matrix = (int*)malloc(ROWS * COLS * sizeof(int));

    /* scan the Matrix */
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &matrix[i * COLS + j]);
        }
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return matrix;
}


/* 4-----print Matrix on a file */
void Matrix_Print_File(int* const matrix, char* const path, int const ROWS, int const COLS)
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

    /* print the dimensions */
    fprintf(fp, "%d %d\n", ROWS, COLS);

    /* print the Matrix */
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            fprintf(fp, "%d ", matrix[i * COLS + j]);
        }
        fprintf(fp, "\n");
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return;
}


/* Bubble Sort Matrix */
void Matrix_Bubble_Sort(int *matrix, int const ROWS, int const COLS)
{
    /* Bubble Sort */
    printf("\nStart of the Bubble Sort...");
    for(int i = 0; i < (ROWS * COLS) - 1; i++)
    {
        for(int j = 0; j < (ROWS * COLS) - i - 1; j++)
        {
            if(matrix[j] > matrix[j+1])
            {
                Swap(&matrix[j],&matrix[j+1]);
            }
        }
    }
    printf("\nMatrix has been Sorted!\n");

    /* exit */
    return;
}