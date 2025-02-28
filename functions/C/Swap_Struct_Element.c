/* swap strcut element */
void Swap_Struct_Element(struct *a, struct *b)
{
    /* variable initialization */
    int temp;

    /* swap */
    temp = a->number;
    a->number = b->number;
    b->number = temp;

    /* exit */
    return;
}