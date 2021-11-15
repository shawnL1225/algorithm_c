#include<stdio.h>
// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue data structure
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(
		sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(
		queue->capacity * sizeof(int));
	return queue;
}
int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}
int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	// printf("%d enqueued to queue\n", item);
}
int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}
int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}
int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}


int num_node, num_edge, packSize;
int node_weight[5000];
int graph[5000][5000];
int tree[5000][5000];
int parent[5000];
int prev[5000];
int visited[5000];
int inTree[5000];
int total_cost=0;
// typedef struct Node Node;
// typedef struct Node
// {
//     int id;
//     int weight;
//     Node *parent;
//     Node **children;

// };

void BFS(struct Queue* Q){
    while(!isEmpty(Q)){
        int node = front(Q);
        dequeue(Q);

        if(node == 0) break;

        //if has path and not visited, push into queue
        for(int i=0;i<num_node;i++){
            if(graph[node][i] && !visited[i]){
                enqueue(Q, i);
                visited[i] = 1;
                prev[i] = node;
            }
        }
    }
}


int DFS(int node){
    //initialize subtree weight as the weight of itself
    int sub_weight = node_weight[node]; 
    for(int i=0;i<num_node;i++){
        if(!visited[i] && tree[node][i]){ //if has child in Tree && not visit, plus all the child weight 
            sub_weight += DFS(i);
            visited[i] = 1;
        }
    }
    // if is root no need to tramsmit package up to parent node, return;
    if(node == 0) return 0;
    //count total cost
    total_cost += sub_weight/packSize;
    if(sub_weight%packSize) total_cost+=1;
    // printf("node: %d, cost: %d\n",node, total_cost);
    //return current subtree weight
    return sub_weight;
}
int main(){

    scanf("%d%d%d", &num_node, &num_edge, &packSize);
    // input nodes
    int ID, W;
    for(int i=0; i<num_node; i++){
        scanf("%d%d",&ID, &W);
        node_weight[i] = W;
    }
    // input edges & construct path graph
    int E, p1, p2;
    for(int i=0;i<num_edge; i++){
        scanf("%d%d%d", &E, &p1, &p2);
        graph[p1][p2] = 1;
        graph[p2][p1] = 1;
    }


    //interate every node to find shortest path to root
    for(int i=num_node-1; i>=1; i--){
        if(inTree[i]) continue;

        //clear previous bfs status
        memset(visited,0,sizeof(visited));
        memset(prev,-1,sizeof(prev));
        struct Queue* queue = createQueue(1000);

        //push start node
        enqueue(queue, i);
        visited[i] = 1;
        BFS(queue);

        //trace the path from i to root, and connect each node 
        int trace = 0;
        // printf("trace: \n");
        while(prev[trace]){
            // printf("%d ", trace);
            int next = prev[trace];
            if(next == -1) break;
            //construct tree (child)
            tree[trace][next] = 1;
            inTree[next] = 1;
            //construct tree (parent)
            parent[next] = trace;
            trace = next; //find next trace node
        }
        // printf("\n");
    }

    //DFS to count total cost
    memset(visited, 0, sizeof(visited));
    DFS(0);
    // printf("total cost:%d", total_cost);

    for(int i=0;i<num_node;i++){
        printf("%d %d\n",i, parent[i]);
    }


}