
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int id;
    int x, y;
    int isChoosen; 
} Node;
Node nodes[100000];

typedef struct 
{
    int id;
    int node1, node2;
    double distance;
}Link;
Link links[100000];

int node_num, link_num; //input variable
double power, biasc_noise;

int choosenLink_num = 0; 
int choosenTransmits[100000];
Link choosenLinks[100000];

double square(int num){
    return num*num;
}
double cube(double num){
    return num*num*num;
}
double distance(Node node1, Node node2){ //count distance of two nodes
    return sqrt(square(node1.x - node2.x) + square(node1.y - node2.y));
}

double sinr(Node receive, Node transmit){ //calculate sinr
    double interferenceSum = 0; 
    for(int i=0;i<choosenLink_num;i++){ // iterate each choosen transmit nodes
        Node interTransNode = nodes[choosenTransmits[i]];
        if(interTransNode.id == transmit.id) continue; // if it is mainTransmit, skip
        interferenceSum += power/cube(distance(interTransNode, receive));//sum up denominator of sinr
    }
    double mainTransmit = power/cube(distance(transmit, receive)); // numerator of sinr
    return mainTransmit/(interferenceSum + biasc_noise);
}

int checkAffect(){
    for(int i=0;i<choosenLink_num;i++){  //check every transmit node
        Link link = choosenLinks[i]; 
        if(sinr(nodes[link.node2], nodes[link.node1]) <= 1 ) //if one node affect return fail
            return 0;
    } 
    return 1;
}

int compare(const void *a, const void *b){ //qsort compare function
    Link *node1 = (Link*)a; 
    Link *node2 = (Link*)b;
    if (node1->distance < node2->distance ) //compare the distance of nodes
        return -1;
    else if (node1->distance > node2->distance )
        return 1;
    else
        return 0;  
}
int main(){
    //input data
    scanf("%d%d%lf%lf", &node_num, &link_num, &power, &biasc_noise);
    for(int i=0; i<node_num; i++){
        scanf("%d%d%d", &nodes[i].id, &nodes[i].x, &nodes[i].y);
        nodes[i].isChoosen = 0;
    }
    for(int i=0; i<link_num; i++){
        scanf("%d%d%d", &links[i].id,  &links[i].node1,  &links[i].node2);
        int id1 = links[i].node1, id2 = links[i].node2;
        links[i].distance = distance(nodes[id1], nodes[id2]); //calculate distance of the link
    }

    qsort(links,link_num,sizeof(links[0]), compare); 

    for(int i=0; i<link_num; i++){ //iterate every links
        Link l = links[i]; 
        //if the node has been choosen, skip
        if(nodes[l.node1].isChoosen == 1 || nodes[l.node2].isChoosen == 1){ 
            continue;
        }
        choosenLinks[choosenLink_num] = l; // assume now transmit is in the transnitsArr
        choosenTransmits[choosenLink_num++] = nodes[l.node1].id; 
        // if it's sinr > 1 && it won't affect the other chosen nodes, choose
        if(!checkAffect(nodes[l.node2])){
            choosenLink_num--;
        }else{
            nodes[l.node1].isChoosen = 1; //set the two node states 
            nodes[l.node2].isChoosen = 1;
        }
    }

    printf("%d\n", choosenLink_num); //print ans
    for(int i=0;i<choosenLink_num;i++){
        printf("%d %d %d\n", choosenLinks[i].id, choosenLinks[i].node1,  choosenLinks[i].node2);
    }

}
