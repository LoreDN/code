/* print String on a file */
void String_Print_File(char const *string, char const *path)
{
    /* empty String */
    if (string == NULL)
    {
        printf("The string is empty\n");
    }
    /* existing String */
    else
    {
        /* variables initialization */
        FILE *fp;

        /* open the file */
        fp = fopen(path, "w");

        /* file not open */
        if (fp == NULL)
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

        /* print the String */
        fputs(string, fp);

        /* close the file */
        fclose(fp);
    }

    /* exit */
    return;
}