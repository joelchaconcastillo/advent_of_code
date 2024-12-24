#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<long long> stones;
   long long stone;
   while(cin>>stone)stones.push_back(stone);
   for(int ii = 0; ii<25; ii++){
       vector<long long>newStones;
       for(auto st:stones){
	  string stoneStr = to_string(st);
	  if(st==0) newStones.push_back(1);
	  else if(stoneStr.size() % 2==0){
	     newStones.push_back( stoll(stoneStr.substr(0, stoneStr.size()/2)));
	     newStones.push_back( stoll(stoneStr.substr(stoneStr.size()/2, stoneStr.size()/2)));
	  }else newStones.push_back(st*2024);
       }
       stones=newStones;
   }
   cout << stones.size()<<endl;
   return 0;
}
