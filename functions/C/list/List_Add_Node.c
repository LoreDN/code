/* add a Node to the list */
Node* List_Add_Node(Node *list)
{
    /* variable initialization */
    Node *node;
    
    /* empty List */
    if(list == NULL)
    {
        /* create a new Node */
        list = (Node*)malloc(sizeof(Node));
        /* Node initialization */
        List_Set_Node(list,1);
    }
    /* existing List */
    else
    {
        /* search in the List */
        node = list;
        while(node->next != NULL)
        {
            node = node->next;
        }
        
        /* create a new Node */
        node->next = (Node*)malloc(sizeof(Node));
        /* Node initialization */
        List_Set_Node(node->next,node->position + 1);
    } 

    /* exit */
    return list;
}