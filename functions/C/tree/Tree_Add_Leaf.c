/* add a Leaf to the Tree */
Leaf* Tree_Add_Leaf(Leaf *tree, int const depth, int const father, int const child)
{
    /* Leaf initialization */
    tree = (Leaf*)malloc(sizeof(Leaf));
    Tree_Set_Leaf(tree, depth, father, child);
    
    /* exit */
    return tree;
}