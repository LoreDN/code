/* print String */
void String_Print(char const *string)
{
    /* empty String */
    if (string == NULL)
    {
        printf("The String is empty\n");
    }
    /* existing String */
    else
    {
        printf("The String is: ");
        puts(string);
    }

    /* exit */
    return;
}