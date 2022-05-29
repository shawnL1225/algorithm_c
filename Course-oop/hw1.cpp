#include <bits/stdc++.h>
using namespace std;

int nodesNum, dstNum, linkNum;
vector<int> dstId;

class Link {
  public:
  int node1,node2;
  int oldw, neww;
};
class Node {
  public:
  int id;
  map<int,int> next_old, next_new;
};

int main(){
  // input
  cin >> nodesNum >> dstNum >> linkNum;
  Link links[linkNum*2]; //double direction
  Node nodes[nodesNum];
  //init node id
  for(int i=0;i<nodesNum;i++) nodes[i].id = i;
  //input dst nodes
  for(int i=0;i<dstNum;i++){
    int dst_num;
    cin >> dst_num;
    dstId.push_back(dst_num);
  }
  //input link
  int lid;
  for(int i=0;i<linkNum;i++){
    cin >> lid >> links[i].node1 >> links[i].node2 >> links[i].oldw >> links[i].neww;
  }
  for(int i=lid+1;i<linkNum*2;i++){ //input another direction
    links[i].node1 = links[i-lid-1].node2;
    links[i].node2 = links[i-lid-1].node1;
    links[i].oldw = links[i-lid-1].oldw;
    links[i].neww = links[i-lid-1].neww;
  }
  
  int dis[dstNum][nodesNum];
    //each dst do a bellman ford - old weight
  for(int i=0;i<dstNum;i++){
    for(int j=0;j<nodesNum;j++){ //init dis with max int
      dis[i][j] = 0x3f3f3f3f;
    }

    dis[i][dstId[i]] = 0; //start point set 0
    for(int k=0;k<nodesNum-1;k++){ //run n-1 time

      for(auto l :links){
        
        if(dis[i][l.node2] > dis[i][l.node1] + l.oldw){ //if distance get smaller
          dis[i][l.node2] = dis[i][l.node1] + l.oldw; //update dis
          nodes[l.node2].next_old[dstId[i]] = l.node1; //update next path
        }else if(dis[i][l.node2] == dis[i][l.node1] + l.oldw){ //if same weight, choose small one
           if(nodes[l.node2].next_old[dstId[i]] > l.node1)
           nodes[l.node2].next_old[dstId[i]] = l.node1;
        }
      }
    }
  }

  //each dst do a bellman ford - new weight
  for(int i=0;i<dstNum;i++){
    for(int j=0;j<nodesNum;j++){
      dis[i][j] = 0x3f3f3f3f;
    }

    dis[i][dstId[i]] = 0;
    for(int k=0;k<nodesNum-1;k++){

      for(auto l :links){
        
        if(dis[i][l.node2] > dis[i][l.node1] + l.neww){
          dis[i][l.node2] = dis[i][l.node1] + l.neww;
          nodes[l.node2].next_new[dstId[i]] = l.node1;
        }else if(dis[i][l.node2] == dis[i][l.node1] + l.neww){ 
          if(nodes[l.node2].next_new[dstId[i]] > l.node1){
            nodes[l.node2].next_new[dstId[i]] = l.node1;
          } 
        }
      }
    }
  }


  
  for(auto n : nodes){
    cout << n.id << endl; //node id
    for(auto d : dstId){
      if(n.id == d) continue;//skip itself
      cout << d <<' '<< n.next_old[d] << endl;
    }
  }
  for(auto n : nodes){
    if(n.next_old == n.next_new) continue; //old & new 's next table are same, skip

    cout << n.id << endl;
    for(auto d : dstId){
      if(n.id == d) continue; //skip itself
      if(n.next_old[d] == n.next_new[d]) continue; //old & new 's next table are same, skip
      cout << d <<' '<< n.next_new[d] << endl;
    }
  }


  return 0;
}