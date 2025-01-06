#include <bits/stdc++.h>
using namespace std;
int n, m;
map<char, pair<int, int> > dir;
void _print(vector<string> &grid){
   for(int i = 0 ;i < n; i++){
	   cout << grid[i]<<endl;
   }
}
void move_to(pair<int, int> &pos, pair<int, int> delta, vector<string> &grid){
   pair<int, int> _next(pos.first+delta.first, pos.second+delta.second);
   while(grid[_next.first][_next.second] != '.' && grid[_next.first][_next.second] !='#'){
	   _next = {_next.first+delta.first, _next.second+delta.second};
   }
   if(grid[_next.first][_next.second]=='#')return;
   auto prev = _next;
   while(grid[prev.first][prev.second]!='@'){
	   _next = {prev.first-delta.first, prev.second-delta.second};
	   grid[prev.first][prev.second] = grid[_next.first][_next.second];
	   prev = _next;
   }
   pos = {prev.first+delta.first, prev.second+delta.second};
   grid[_next.first][_next.second] = '.';

}
int main(){
   dir['<']={0, -1};
   dir['>']={0, 1};
   dir['v']={1, 0};
   dir['^']={-1, 0};
   vector<string> grid;
   string line;
   while(true){
     getline(cin, line);
     if(line.empty()) break;
     grid.push_back(line);
   }
   string instructions="";
   while(cin>>line)instructions+=line;

   n = grid.size(), m = grid.front().size();

   pair<int, int> pos;
   for(int i = 0 ;i < n; i++){
      for(int j = 0; j < m; j++){
	     if(grid[i][j]=='@'){
		  pos={i,j};
		  break;
	     }
      }
   }
   for(auto move:instructions){
	   cout << move<<endl;
      move_to(pos, dir[move], grid);
   }
   long long res = 0;
   for(int i = 0 ; i < n; i++){
       for(int j = 0 ; j <m; j++){
	       if(grid[i][j]=='O') res += i*100L+j;
       }
   }
//   _print(grid);
   cout << res<<endl;
   return 0;
}
