/* print Tree */
void Tree_Print(Leaf *tree, int const depth, int const father, int const child)
{
    /* empty Tree */
    if (tree == NULL)
    {
        printf("\nEmpty Tree!\n");
    }
    /* existing Tree */
    else
    {
        /* Leaf print */
        if(depth == 0)
        {
            printf("\n|------ Root: %d\n", tree->number);
        }
        else
        {
            /* print current Leaf */
            for (int i = 0; i < depth; i++)
            {
                printf("       ");
            }
            printf("|------ Leaf %d.%d: %d\n", depth, father + child + 1, tree->number);
        }

        /* children print */
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            if(tree->next[i] != NULL)
            {
                Tree_Print(tree->next[i], depth + 1, father + child, father + child + i);
            }
        }
    }
    
    /* exit */
    return;
}