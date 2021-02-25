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
int rec(int b, int e, int integers[], char symbols[]);

int expr_evaluation(int n, int type[], int integers[], char symbols[]){
    return rec(0, n-2, integers, symbols);
}

int rec(int b, int e, int integers[], char symbols[]){

    if(b == e) return integers[b];
    // if(symbols[b] == '(' && symbols[e] == ')'){
    //     b++;e--;
    // }
    int param = 0;
    int ctOutside=0;
    for(int i = e;i>=b;i--){
        if(symbols[i] == ')') param++;
        else if(symbols[i] == '(') param--;
        else if(param == 0)ctOutside++;
    }
    if(ctOutside == 0 && symbols[b] == '(' && symbols[e] == ')') {
        b++; e--;
    }
    
    int segment=-1;
    for(int i = e;i>=b;i--){
        if(symbols[i] == ')') param++;
        else if(symbols[i] == '(') param--;

        if(param==0 && (symbols[i] == '+' || symbols[i]== '-')){
            segment = i;
            break;
        }
    }
    if(segment == -1){
        for(int i = e;i>=b;i--){
            if(symbols[i] == ')') param++;
            else if(symbols[i] == '(') param--;

            if(param==0 && (symbols[i] == '*' || symbols[i]== '/')){
                segment = i;
                break;
            }
        }
    }
    // printf("%c\n",symbols[segment]);

    if(symbols[segment] == '+'){
        return rec(b, segment-1, integers, symbols) + rec(segment+1, e, integers, symbols);
    }else if(symbols[segment] == '-'){
        return rec(b, segment-1, integers, symbols) - rec(segment+1, e, integers, symbols);
    }else if(symbols[segment] == '*'){
        return rec(b, segment-1, integers, symbols) * rec(segment+1, e, integers, symbols);
    }else if(symbols[segment] == '/'){
        return rec(b, segment-1, integers, symbols) / rec(segment+1, e, integers, symbols);
    }
}