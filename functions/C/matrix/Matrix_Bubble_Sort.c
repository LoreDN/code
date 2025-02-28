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