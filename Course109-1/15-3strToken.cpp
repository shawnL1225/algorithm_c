#include <bits/stdc++.h>
using namespace std;
char _my_buffer;
int _is_my_buffer_filled = 0;

char peek_next_char()
{
    if(_is_my_buffer_filled == 0)
    {
        _my_buffer = getchar();
        _is_my_buffer_filled = 1;
    }
    return _my_buffer;

}
char my_getchar()
{
    if(_is_my_buffer_filled == 1)
    {
        _is_my_buffer_filled = 0;
        return _my_buffer;
    }
    else
    {
        return getchar();
    }
    
}
void read_identifier()
{
    string s="";
    while(1)
    {
        char c = peek_next_char();
        if(isalpha(c) || c == '_' || isdigit(c))
        {
            c = my_getchar();
            s += c;
        }
        else break;
    }
    cout << '\"' << s << '\"' <<endl;

}
void read()
{
    char c = my_getchar();
    printf("%c\n",c);
}
void read_number()
{
    char c = peek_next_char();
    while(isdigit(c))
    {
        c = my_getchar();
        printf("%c",c);
        c = peek_next_char();
        
    }
    printf("\n");
}
void read_punc()
{
    char c = my_getchar();
    printf("%c\n",c);
}
void read_operator()
{
    char c = my_getchar();
    printf("%c\n",c);
}
int main(){
    char c;
    while(1)
    {
        c = peek_next_char();
        if(c == EOF) break;
        if(c == ' ' || c=='\n'||c=='\t'||c=='\r')
            my_getchar();
        else if(isalpha(c) || c == '_') 
            read_identifier();
        // else if(c== ','||c=='.'||c=='?'||c== '\''||c==':') 
        //     read_punc();
        else if(isdigit(c)) 
            read_number();
        // else if(c== '+'||c=='-'||c=='*'||c== '/'||c=='('||c==')') 
            // read_operator();
        else
            read();
    }
}