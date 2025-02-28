#include <stdio.h>
#include <stdlib.h>
#include </media/lorenzo/Work/code/headers/C/LDN_basic.h>


/* Node definition */
typedef struct List {
    /* elements */
    int number;
    int position;
    /* Node pointer */
    struct List *next;
}Node;


/* prototypes */
void List_Set_Node(Node *node, int const pos);
Node* List_Add_Node(Node *list);
void List_Print(Node *list);
void List_Set_Node_File(Node *node, int const pos, FILE *fp);
Node* List_Scan_File(char* const path);
void List_Print_File(Node* const list, char* const path);
void Swap_Node(Node *a, Node *b);
void List_Bubble_Sort(Node *list);
Node* List_Remove_Node(Node *list, int const del);


/* 1-----Node initialization */
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


/* 2-----add a Node to the List */
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


/* 3-----print List */
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


/* 4-----Node initialization from a file */
void List_Set_Node_File(Node *node, int const pos, FILE *fp)
{
    /* elements compilation */
    fscanf(fp, "%d", &(node->number));
    node->position = pos;

    /* next Node pointer set */
    node->next = NULL;

    /* exit */
    return;
}


/* 5-----scan List from a file */
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


/* 6------print List on a file */
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


/* 7-----swap Node */
void Swap_Node(Node *a, Node *b)
{
    /* variable initialization */
    int temp;

    /* swap the number */
    temp = a->number;
    a->number = b->number;
    b->number = temp;

    /* swap the position */
    temp = a->position;
    a->position = b->position;
    b->position = temp;

    /* exit */
    return;
}


/* 8-----Bubble Sort List */
void List_Bubble_Sort(Node *list)
{
    /* variables initialization */
    int DIM = 0;
    Node *node = NULL;

    /* empty List */
    if(list == NULL)
    {
        printf("\nImpossible to sort an Empty List!\n");

        /* exit */
        return;
    }    
    
    /* calculate List dimension */
    node = list;
    while(node != NULL)
    {
        DIM++;
        node = node->next;
    }
    
    /* Bubble Sort */
    printf("\nStart of the Bubble Sort...");
    for(int i = 1; i < DIM; i++)
    {
        node = list;
        for(int j = 1; j < DIM; j++)
        {
            if(node->number > (node->next)->number)
            {
                Swap_Node(node,node->next);
            }
            node = node->next;
        }
    }
    printf("\nList has been Sorted!\n");

    /* exit */
    return;
}


/* 9-----remove a Node from the List */
Node* List_Remove_Node(Node *list, int const del)
{
    /* variables initialization */
    Node *node, *prec, *succ;    
    
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
            prec = node;
        }
        else if(i == del)
        {
            /* removal of the Node */
            succ = node->next;
            free(node);

            /* List modification */
            if (i == 1)
            {
                /* List = 2° node */
                list = succ;

                /* update the position */
                while(succ != NULL)
                {
                    succ->position--;
                    succ = succ->next;
                }
            }
            else
            {
                /* List = List modified */
                prec->next = succ;

                /* update the position */
                while(succ != NULL)
                {
                    succ->position--;
                    succ = succ->next;
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