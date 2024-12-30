#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
vector<vector<int>>directions = {
   {-1,0},
{0,-1}, {0, 1},
   {1,0}
};
pair<int, int> S, E;
int n, m, min_improvement=100, max_cheating = 20;
vector<vector<int>> dist2End;
void explorative_bfs(){
   queue<tuple<int, int, int>>q;//row, col, time
   q.push({E.first, E.second, 0});
   set<pair<int, int>>marked;
   while(!q.empty()){
     auto [row, col, dist] = q.front(); q.pop();
     if(marked.count({row, col}))continue;
     marked.insert({row, col});
     dist2End[row][col]=dist;
     for(auto delta:directions){
	 int next_row = row+delta[0], next_col = col+delta[1];
	 if(next_row < 0 || next_row>=n || next_col<0 || next_col>=m)continue;
	 if(marked.count({next_row, next_col}))continue;
	 if(grid[next_row][next_col]=='#')continue;
	 q.push({next_row, next_col, dist+1});
     }
   }
}
int manhatan_dist(pair<int, int> A, pair<int, int> B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}
set<pair<int, int>> marked;
long long cheating_from(int row, int col, int max_cheating, int score){
   long long res = 0;
   for(int deltax=-max_cheating; deltax<=max_cheating; deltax++){
     int current_row = row+deltax;
     if(current_row<=0 || current_row>=n-1)continue;
     for(int deltay=-max_cheating; deltay<=max_cheating; deltay++){
       int current_col = col+deltay;
       if(current_col<=0 || current_col>=m-1)continue;
       if(grid[current_row][current_col]=='#')continue;
       if(marked.count({current_row, current_col}))continue;
       int dist = manhatan_dist({row, col}, {current_row, current_col});
       if(dist>max_cheating)continue;
       int current_score = dist2End[row][col];
       int next_score = dist + dist2End[current_row][current_col];
       int improvement = current_score-next_score;
       if(improvement >= min_improvement) res++;
     }
   }
   return res;
}
long long bfs_with_cheat(int max_cheating){
   long long res = 0;
   queue<tuple<int ,int, int>> q;
   q.push({S.first, S.second, 0});
   while(!q.empty()){
     auto [row, col, dist] = q.front(); q.pop();
     if(marked.count({row, col}))continue;
     marked.insert({row, col});
     res += cheating_from(row, col, max_cheating, dist);
     for(auto delta:directions){
	 int next_row = row+delta[0], next_col = col+delta[1];
	 if(next_row < 0 || next_row>=n || next_col<0 || next_col>=m)continue;
	 if(marked.count({next_row, next_col}))continue;
	 if(grid[next_row][next_col]=='#')continue;
	 q.push({next_row, next_col, dist+1});
     }
   }
   return res;
}
long long solve(){
   dist2End.assign(n, vector<int>(m, INT_MAX));
   explorative_bfs();
   return bfs_with_cheat(max_cheating);
}
int main(){
   string line;
   while(cin>>line)grid.push_back(line);
   n = grid.size(), m=grid.front().size();
   for(int i =0 ; i < n; i++){
      for(int j = 0 ;j < m; j++){
	   if(grid[i][j]=='S')S={i,j};
	   if(grid[i][j]=='E')E={i,j};
      }
   }
   cout << solve() <<endl;
   return 0;
}
