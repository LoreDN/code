/* print List on a file */
void List_Print_File(Node* const list, char* const path)
{
    /* variables initialization */
    FILE *fp = NULL;

    /* open the file */
    fp = fopen(path,"w");
    
    /* file not open */
    if(fp == NULL)
    {
        printf("\nError: file not found!\n");

        /* exit */
        return;
    }
    /* file open correctly */
    else
    {
        printf("\nFile %s found!\n", path);
    }

    /* empty List */
    if(list == NULL)
    {
        fprintf(fp, "\nEmpty list!\n");
    }
    /* existing List */
    else
    {
        /* print until stop Node */             
        fprintf(fp, "\nList:");
        for(Node *node = list; node != NULL; node = node->next)
        {
            /* elements print */
            fprintf(fp, "\nNode %d:\n\tNumber: %d", node->position, node->number);
        }
    }

    /* close the file */
    fclose(fp);

    /* exit */
    return;
}