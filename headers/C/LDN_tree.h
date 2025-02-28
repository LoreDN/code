#include <stdio.h>
#include <stdlib.h>


/* Leaf definition */
#define MAX_CHILDREN 2
typedef struct Tree {
    /* elements */
    int number;
    int depth, father, child;
    /* Leaf pointer */
    struct Tree *next[MAX_CHILDREN];
}Leaf;


/* prototypes */
void Tree_Set_Leaf(Leaf *leaf, int const depth, int const father, int const child);
Leaf* Tree_Add_Leaf(Leaf *tree, int const depth, int const father, int const child);
void Tree_Print(Leaf *tree);


/* 1-----Leaf initialization */
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
    /* position compilation */
    leaf->depth = depth;
    leaf->father = father;
    leaf->child = child;

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
            leaf->next[i] = Tree_Add_Leaf(leaf->next[i], leaf->depth + 1, leaf->father + leaf->child, leaf->father + leaf->child + i);
        }
    }

    /* exit */
    return;
}


/* 2-----add Leaf to the Tree */
Leaf* Tree_Add_Leaf(Leaf *tree, int const depth, int const father, int const child)
{
    /* Leaf initialization */
    tree = (Leaf*)malloc(sizeof(Leaf));
    Tree_Set_Leaf(tree, depth, father, child);
    
    /* exit */
    return tree;
}


/* 3-----print Tree */
void Tree_Print(Leaf *tree)
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
        if(tree->depth == 0)
        {
            printf("\n|------ Root: %d\n", tree->number);
        }
        else
        {
            /* print current Leaf */
            for (int i = 0; i < tree->depth; i++)
            {
                printf("       ");
            }
            printf("|------ Leaf %d.%d: %d\n", tree->depth, tree->father + tree->child + 1, tree->number);
        }

        /* children print */
        for (int i = 0; i < MAX_CHILDREN; i++)
        {
            if(tree->next[i] != NULL)
            {
                Tree_Print(tree->next[i]);
            }
        }
    }
    
    /* exit */
    return;
}