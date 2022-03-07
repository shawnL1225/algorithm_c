#include <stdio.h>
#include <string.h>
int myhash (int userID, int p, int m){
    return   userID * userID % p % m;
}

void main(){
    int p, m, n;
    scanf("%d%d%d", &p, &m, &n);
    char table[m/8+1]; // Declare m/8+1 byte space
    memset(table, 0, sizeof(table)); //initialize table to zero

    while(n--){
        int id;
        scanf("%d", &id);
        int hash_num = myhash(id, p, m); //do hash function
        int ind = 1 << (hash_num%8); //shift 1 to get the index in each byte e.g. 0000 0100

        if(table[hash_num/8] & ind ) { //"AND bit op" with origin table and index 
            printf("%d %d\n",id , 0);   //get whether the hash_number has showed up
        }else{
            table[hash_num/8] |= ind ; //"OR bit op" the record new hash_number has showed
            printf("%d %d\n",id , 1);
        }
         
        
    }
}
