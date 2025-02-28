/* print List */
void List_Print(Node *list)
{
    /* empty List */
    if(list == NULL)
    {
        printf("\nEmpty list!\n");
    }
    /* existing List */
    else
    {
        /* print until stop Node */             
        printf("\nPrint the list:");
        for(Node *node = list; node != NULL; node = node->next)
        {
            /* elements print */
            printf("\nNode %d:\n\tNumber: %d", node->position, node->number);
        }
        printf("\n");
    }

    /* exit */
    return;
}