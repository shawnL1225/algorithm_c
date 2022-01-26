#include <stdio.h>
#include <string.h>
unsigned int myhash (unsigned int userID, unsigned int p, unsigned int m){
    if(userID < m) return userID;
    return userID * userID % p % m;
}
unsigned int hash2 (unsigned int num, unsigned int m){
    return (num-1)%m;
}
unsigned int hash3 (unsigned int num){
    return (num-1)%1019;
}

void main(){
    unsigned int p, m, n;
    scanf("%u%u%u", &p, &m, &n);
    unsigned char table[m/8+1]; // Declare m/8+1 byte space
    memset(table, 0, sizeof(table)); //initialize table to zero

    while(n--){
        unsigned int id;
        scanf("%u", &id);
        unsigned int hash_num = myhash(id, p, m); //do hash function
        unsigned int ind = 1 << (hash_num%8); //shift 1 to get the index in each byte e.g. 0000 0100
        
        // if(table[hash_num/8] & ind){ //if the bit has been taken, do second hash
        //     hash_num = hash2(hash_num, m);
        //     ind = 1 << (hash_num%8);
        // }
        
        


        if(table[hash_num/8] & ind ) { //"AND bit op" with origin table and index 
            printf("%d %d\n",id , 0);   //get whether the hash_number has showed up
        }else{
            table[hash_num/8] |= ind ; //"OR bit op" the record new hash_number has showed
            printf("%d %d\n",id , 1);
        }
         
        
    }
}
