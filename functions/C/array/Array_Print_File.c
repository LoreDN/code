/* print Array on a file */
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