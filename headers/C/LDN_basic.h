/* prototypes */
void Swap(int *a, int *b);

/* 1-----swap */
void Swap(int *a, int *b)
{
    /* variable initialization */
    int temp;

    /* swap */
    temp = *a;
    *a = *b;
    *b = temp;

    /* exit */
    return;
}