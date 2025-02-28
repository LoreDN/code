/* Node initialization */
void List_Set_Node(Node *node, int const pos)
{
    /* elements compilation */
    do{
        printf("\nInsert the number: ");
        scanf("%d", &(node->number));
    }while(node->number < 0);
    node->position = pos;

    /* next Node pointer set */
    node->next = NULL;

    /* exit */
    return;
}