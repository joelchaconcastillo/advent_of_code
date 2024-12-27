#include <bits/stdc++.h>
using namespace std;
int a, b, n=71, m=71;
vector<vector<int>>directions = {
	{0,-1},
     {-1,0}, {1,0},
         {0, 1}
   };
int bfs(set<pair<int, int>> &marked){
   queue<tuple<int, int, int>>q;
   q.push({0,0,0});
   int res = INT_MAX;
   while(!q.empty()){
      auto [x, y, dist] = q.front(); q.pop();
      if(x == n-1 && y == m-1){
	      res = dist;
	      break;
      }
      if(marked.find({x,y})!=marked.end())continue;
      marked.insert({x,y});
      for(auto dir:directions){
	 tuple<int, int, int> next(x+dir[0], y+dir[1], dist+1);
	 auto [xx,yy,d] = next;
	 if(xx<0||xx>=n || yy<0||yy>=m)continue;
	 if(marked.find({xx,yy})!=marked.end())continue;
	 q.push(next);
      }
   }
   return res;
}
int main(){
   set<pair<int, int>>marked;
   vector<pair<int, int>> removing;
   char comma;
   while(cin>>a>>comma>>b) removing.push_back({a,b});
   for(int i = 0 ;i < 1024; i++) marked.insert(removing[i]);
   cout << bfs(marked) <<endl;
   return 0;
}
