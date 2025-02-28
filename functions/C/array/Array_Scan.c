/* scan Array */
void Array_Scan(int *array, int const DIM)
{
    /* scan of the Array */
    printf("Scan the Array:\n");
    for(int i = 0; i < DIM; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d",&array[i]);
    }

    /* exit */
    return;
}
