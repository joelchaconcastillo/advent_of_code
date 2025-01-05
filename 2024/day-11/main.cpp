#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<string> stones;
   string stone;
   while(cin>>stone)stones.push_back(stone);
   for(int ii = 0; ii<25; ii++){
	   cout << ii+1<<" "<<stones.size()<<endl;
       vector<string>newStones;
       for(auto &stoneStr:stones){
	  if(stoll(stoneStr) == 0) newStones.push_back("1");
	  else if(stoneStr.size() % 2==0){
	     newStones.push_back(stoneStr.substr(0, stoneStr.size()/2));
	     newStones.push_back(stoneStr.substr(stoneStr.size()/2, stoneStr.size()/2));
	  }else newStones.push_back( to_string(stoll(stoneStr)*2024LL));
       }
       //for(auto ii:newStones)cout << ii<<" ";
       //cout <<endl;
       stones=newStones;
   }
   cout << stones.size()<<endl;
   return 0;
}
