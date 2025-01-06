#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
int n, m;
map<char, pair<int, int> > dir={
	{{'<'},{0,-1}},
	{{'>'},{0,1}},
	{{'v'},{1,0}},
	{{'^'},{-1,0}}
};
void _print(vector<string> &grid){
   for(int i = 0 ;i < n; i++){
	   cout << grid[i]<<endl;
   }
}
void _move(int &crow, int &ccol, int delta_row, int delta_col){
   queue<tuple<int, int> >q;
   vector<tuple<int, int>> positions;
   q.push({crow, ccol});
   set<pair<int, int>>marked;
   while(!q.empty()){
     auto [row, col] = q.front(); q.pop();
     if(marked.find({row,col})!=marked.end())continue;
     marked.insert({row,col});
     positions.push_back({row, col});
     if(grid[row+delta_row][col+delta_col]=='#') return;
     if(grid[row+delta_row][col+delta_col]=='.') continue;
     if(grid[row+delta_row][col+delta_col] == '[')q.push({row+delta_row, col+delta_col}), q.push({row+delta_row, col+delta_col+1});
     if(grid[row+delta_row][col+delta_col] == ']')q.push({row+delta_row, col+delta_col}), q.push({row+delta_row, col+delta_col-1});
   }
   reverse(positions.begin(), positions.end());
   for(auto [row,col]:positions){
      grid[row+delta_row][col+delta_col]=grid[row][col];
      grid[row][col]='.';
   }
   crow=crow+delta_row;
   ccol=ccol+delta_col;
}

void transform(){
   vector<string> newGrid;
   for(int i = 0 ; i < n; i++){
      string row="";
      for(int j = 0 ; j < m; j++){
	  if(grid[i][j]=='.') row+="..";
	  if(grid[i][j]=='#') row+="##";
	  if(grid[i][j]=='O') row+="[]";
	  if(grid[i][j]=='@') row+="@.";
      }
      newGrid.push_back(row);
   }
   grid=newGrid;
   n=grid.size(), m=grid.front().size();
}
int main(){
   string line;
   while(true){
     getline(cin, line);
     if(line.empty()) break;
     grid.push_back(line);
   }
   string instructions="";
   while(cin>>line)instructions+=line;

   n = grid.size(), m = grid.front().size();
   transform();
   _print(grid);
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
      if(move=='<') _move(pos.first, pos.second, 0, -1);
      if(move == '>') _move(pos.first, pos.second, 0, 1);
      if(move == '^') {_move(pos.first, pos.second,-1,0); }
      if(move == 'v') {_move(pos.first, pos.second, 1,0); }
   }
   long long res = 0;
   for(int i = 0 ; i < n; i++){
       for(int j = 0 ; j <m; j++){
	       if(grid[i][j]=='[') res += i*100L+j;
       }
   }
   _print(grid);
   cout << res<<endl;
   return 0;
}
