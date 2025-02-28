/* print Matrix */
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