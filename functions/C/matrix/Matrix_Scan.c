/* scan Matrix */
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