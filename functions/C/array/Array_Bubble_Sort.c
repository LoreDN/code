/* Bubble Sort Array */
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