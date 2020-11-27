/*  probID: 14-2-NextVowel  */

char vowel[] = {'a','e','i','o','u','A','E','I','O','U'};
int isVowel(char c)
{
    for(int i=0;i<10;i++)
    {
        if(c == vowel[i]) return 1;
    }
    return 0;
}
char *NextVowel(char* ptr)
{
    // printf("%c",*ptr);
    while(*ptr)
    {
        if(isVowel(*ptr))
            return ptr;
        ptr++;
    }
    return '\0';
}
//回傳用 '\0' 不要NULL 