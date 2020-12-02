#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100] = "This is an apple.";
    char str2[100] = "This is a banana.";

    printf("str1 = %s\nstr2 = %s\n\n", str1, str2);
    printf("The result of strcmp(str1,str2) is %d\n", strcmp(str1,str2));

    //

    printf("\nCut str1 into tokens using \" \":\n");

    char *ptr = strtok(str1, " ");

    while( ptr )
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    //

    char str3[100] = "A number/of/tokens here";

    printf("\n\nstr3 = %s\n", str3);
    printf("\nTokenize str3 using \" /\":\n\n");

    ptr = strtok(str3, " /");

    while( ptr )
        printf("%s\n", ptr), ptr = strtok(NULL, " /");

    //

    return 0;
}