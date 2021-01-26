/* probID: 13-1-StringLength */
int StringLength(char* s)
{
    int i=0;
    while(*s){i++;s++;}
    return i;
}
