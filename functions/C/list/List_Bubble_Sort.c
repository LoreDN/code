/* Bubble Sort List */
void List_Bubble_Sort(Node *list)
{
    /* variables initialization */
    int DIM = 0;
    Node *node = NULL;

    /* empty List */
    if(list == NULL)
    {
        printf("\nImpossible to sort an Empty List!\n");

        /* exit */
        return;
    }    
    
    /* calculate List dimension */
    node = list;
    while(node != NULL)
    {
        DIM++;
        node = node->next;
    }
    
    /* Bubble Sort */
    printf("\nStart of the Bubble Sort...");
    for(int i = 1; i < DIM; i++)
    {
        node = list;
        for(int j = 1; j < DIM; j++)
        {
            if(node->number > (node->next)->number)
            {
                Swap_Node(node,node->next);
            }
            node = node->next;
        }
    }
    printf("\nList has been Sorted!\n");

    /* exit */
    return;
}