/*  probID: W4-1-Expression  */
// #include<stdio.h>

// int expr_evaluation(int n, int type[], int integers[], char symbols[]);

// int main()
// {

//     int times,n,ans;
//     scanf("%d", &times);

//     int type[10001];
//     int integers[10001];
//     char symbols[10001];

//     int i, j;
//     for(i=0;i<times;i++)
//     {

//         scanf("%d", &n);

//         for(j=0;j<n;j++)
//             scanf("%d", &type[j]);
            
//         for(j=0;j<n;j++)
//             scanf("%d", &integers[j]);
            
//         for(j=0;j<n;j++)
//             scanf(" %c", &symbols[j]);

//         ans = expr_evaluation(n,type,integers,symbols);

//         printf("%d\n", ans);

//     }

//     return 0;
// }
int rec(int s, int e, int integers[], char symbols[]);

int expr_evaluation(int n, int type[], int integers[], char symbols[]){
    return rec(0, n-2, integers, symbols);
}

int rec(int s, int e, int integers[], char symbols[]){

    if(s == e) return integers[s];

    int last=-1;
    for(int i = e;i>=s;i--){
        if(symbols[i] == '+' || symbols[i]== '-'){
            last = i;
            break;
        }
    }
    if(last == -1) last = e-1;
    // printf("%c\n",symbols[last]);

    if(symbols[last] == '+'){
        return rec(s, last-1, integers, symbols) + rec(last+1, e, integers, symbols);
    }else if(symbols[last] == '-'){
        return rec(s, last-1, integers, symbols) - rec(last+1, e, integers, symbols);
    }else if(symbols[last] == '*'){
        return rec(s, last-1, integers, symbols) * rec(last+1, e, integers, symbols);
    }else if(symbols[last] == '/'){
        return rec(s, last-1, integers, symbols) / rec(last+1, e, integers, symbols);
    }
}