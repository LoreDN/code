/* scan Array from a file */
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