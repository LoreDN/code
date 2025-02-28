/* remove a Node from the List */
Node* List_Remove_Node(Node *list, int const del)
{
    /* variables initialization */
    Node *node, *old, *new;    
    
    /* empty List */
    if(list == NULL)
    {
        printf("\nImpossible to remove a node from an Empty List!\n");

        /* exit */
        return list;
    }
    
    /* Node selection */
    node = list;
    for(int i = 1; node != NULL; i++)
    {
        if(i == del - 1)
        {
            /* saving the Node to update */
            old = node;
        }
        else if(i == del)
        {
            /* removal of the Node */
            new = node->next;
            free(node);

            /* List modification */
            if (i == 1)
            {
                /* List = 2° node */
                list = new;

                /* update the position */
                while(new != NULL)
                {
                    new->position--;
                    new = new->next;
                }
            }
            else
            {
                /* List = List modified */
                old->next = new;

                /* update the position */
                while(new != NULL)
                {
                    new->position--;
                    new = new->next;
                }
            }

            /* successfull exit */
            return list;
        }

        /* next Node */
        node = node->next;
    }

    /* removal failed */
    printf("\n\nThe removal has failed!!!\n\n");

    /* unsuccessfull exit */
    return list;

}