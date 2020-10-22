#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<long long int> vec;
int main()
{
   long long int n, start=1,en,last,now;
   cin >> n;
   long long int sqrtn = sqrt(n);
   en = n;
   last = n+1;
   for(int i=2;i<sqrtn;i++)
   {
       while(n%i==0)
       {
           vec.push_back(i);
           vec.push_back(n/i);
           n/=i;
       }
       

   }

   if(vec.size()==0)
   {
       cout << start<<' '<<en;
       return 0;
   }
   sort(vec.begin(),vec.end());

   for(int i=0;i<vec.size();i++)
   {


       start *=vec[i];
       en /= vec[i];

       now = start+en;
       if(now>last)
       {
           cout <<start/vec[i]<<' '<<en*vec[i];
           break;
       }
       last = now;


   }
    return 0;
}


