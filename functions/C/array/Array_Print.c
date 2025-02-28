/* print Array */
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