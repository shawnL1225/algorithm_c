#include <bits/stdc++.h>
using namespace std;
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  cout <<s<<endl;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='+') continue;
    else cout<<s[i]<<"+";
  }
  cout<<s[s.size()-1];
  return 0;
}