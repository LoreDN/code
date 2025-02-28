/* print Matrix on a file */
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