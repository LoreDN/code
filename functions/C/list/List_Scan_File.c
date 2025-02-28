/* scan List from a file */
Node* List_Scan_File(char* const path)
{
    /* variables initialization */
    int DIM;
    Node *list = NULL, *node = NULL;
    FILE *fp = NULL;

    /* open the file */
    fp = fopen(path,"r");
    
    /* file not open */
    if(fp == NULL)
    {
        printf("\nError: file not found!\n");

        /* exit */
        return NULL;
    }
    /* file open correctly */
    else
    {
        printf("\nFile %s found!\n", path);
    }

    /* scan the dimension */
    fscanf(fp, "%d", &DIM);

    /* scan the List */
    for(int i = 0; i < DIM; i++)
    {
        /* empty List */
        if(list == NULL)
        {
            /* create a new Node */
            list = (Node*)malloc(sizeof(Node));
            /* Node initialization */
            List_Set_Node_File(list,1,fp);
            node = list;
        }
        /* existing List */
        else
        {            
            /* create a new Node */
            node->next = (Node*)malloc(sizeof(Node));
            /* Node initialization */
            List_Set_Node_File(node->next,node->position + 1,fp);

            /* next Node */
            node = node->next;
        }
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return list;
}