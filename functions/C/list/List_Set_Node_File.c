/* Node initialization from a file */
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