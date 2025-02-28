/* scan String */
char* String_Scan(char *string)
{
    /* variables initialization */
    char temp[MAX_LENGTH];

    /* get a String */
    printf("Enter a String: ");
    fgets(temp, MAX_LENGTH, stdin);

    /* copy the String */
    string = (char*)malloc(strlen(temp));
    strcpy(string,temp);

    /* exit */
    return string;
}