/* scan Matrix from a file */
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

    /* Matrix initialization */
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