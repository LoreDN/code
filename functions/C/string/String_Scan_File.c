/* scan String from a file */
char* String_Scan_File(char *string, char const *path)
{
    /* variables initialization */
    char temp[MAX_LENGTH];
    FILE *fp;

    /* open the file */
    fp = fopen(path, "r");

    /* file not open */
    if (fp == NULL)
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

    /* get a String */
    fscanf(fp, "%[^\n]", temp);

    /* copy the String */
    string = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(string,temp);

    /* close the file */
    fclose(fp);

    /* exit */
    return string;
}