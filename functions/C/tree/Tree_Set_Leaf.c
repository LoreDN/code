/* Leaf initialization */
void Tree_Set_Leaf(Leaf *leaf, int const depth, int const father, int const child)
{
    /* variables initialization */
    int children;
    
    /* Leaf print */
    if(depth == 0)
    {
        printf("\nRoot:");
    }
    else
    {
        printf("Leaf %d.%d:", depth, father + child + 1);
    }
    /* elements compilation */
    do{
        printf("\nInsert the number: ");
        scanf("%d", &(leaf->number));
    }while(leaf->number < 0);

    /* children number */
    do{
        printf("\nHow many children has this Leaf? Children: ");
        scanf("%d", &children);
    }while(children < 0 || children > MAX_CHILDREN);

    /* children pointers set */
    for(int i = 0; i < MAX_CHILDREN; i++)
    {
        leaf->next[i] = NULL;
        
        /* child pointer */
        if(i < children)
        {
            leaf->next[i] = Tree_Add_Leaf(leaf->next[i], depth + 1, father + child, father + child + i);
        }
    }

    /* exit */
    return;
}