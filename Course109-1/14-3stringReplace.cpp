/*  probID: 14-3-StringReplace  */
// #include <bits/stdc++.h>
// using namespace std;

// char *StringReplace(char*,const char*,const char*);

// char *NextSlash( char *ptr )
// {
//     while( *ptr != '/' )
//         ptr++;
//     return ptr;
// }

// char *ExtractToken( char *target, char *ptr )
// {
//     char *nxt_ptr = NextSlash(++ptr);
//     int len = nxt_ptr - ptr;

//     strncpy(target, ptr, len);
//     *(target+len) = 0;

//     return nxt_ptr;
// }

// int main()
// {
//     char buf[20000];
//     char s[10000],t[100],r[100];

//     while(fgets(buf,20000,stdin))
//     {

//         char *ptr = NextSlash(buf);

//         ptr = ExtractToken(s,ptr);
//         ptr = ExtractToken(t,ptr);
//         ExtractToken(r,ptr);

//         printf("%s\n",StringReplace(s,t,r));
//     }

//     return 0;
// }

# include <string.h>
char new_s[2000000];
char *StringReplace(char* s,const char* t,const char* r)
{

    memset(new_s,0,sizeof(new_s));
    char* new_ptr = new_s;

    int i=0;
    int isEnd=0;
    while(1)
    {
        char* ptr = strstr(s,t);
        if(ptr == NULL)
            {ptr = s+strlen(s);isEnd = 1;}

        for(;s<ptr;s++,i++)
        {
            new_s[i] = *s;
        }

        if(isEnd) {return new_ptr;}


        for(int j=0;j<strlen(r);j++,i++)
        {
            new_s[i] = r[j];
        }
        s+=strlen(t);

    }


}
