#include <bits/stdc++.h>

int main(){
    char s[60];
    while(scanf("%c",s)){
        bool suc = 1;
        int len = strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]!=s[len-1-i]){
                suc = 0;
                break;
            }
        }
        if(suc) printf("YES\n");
        else printf("NO\n");
        
    }


    return 0;
}