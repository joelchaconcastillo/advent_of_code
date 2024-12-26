#include <bits/stdc++.h>
using namespace std;
int n, m;
set<pair<int , pair<int, int>>> marked;
vector<string> grid;
map<int, pair<int, int>> directions;
//0: right, 1: down, 2:left, 3:up

long long bfs(pair<int, int> pos, pair<int, int>end){
	//priority_queue<vector<long long>>q; //dist, row, col, dir
	priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> q;
	q.push({0, pos.first, pos.second, 0});
	map<vector<long long>, long long> min_dist;//noqa: for simplicity it uses map but it is no efficient for this use case
	long long res = INT_MAX;
	while(!q.empty()){
	     auto current = q.top(); q.pop();
	     pair<int, int> cur_pos(current[1], current[2]);
	     int dir = current.back();
	     if(cur_pos == end) res = min(res, current[0]);
	     vector<long long> tup = {current[1],current[2],current[3]};

	     if(min_dist.find(tup) != min_dist.end() && min_dist[tup] > current[0]){
	        min_dist[tup]=current[0];
	     }else if(min_dist.find(tup) != min_dist.end() && min_dist[tup] < current[0]) continue;
	     else min_dist[tup]=current[0];
  	     for(int i = 0; i < 4; i++){
	       long long cost = current[0]+1L;
	       if(i==1 || i==3)cost+=1000L;
	       else if(i==2)cost+=2000L;
	       pair<int, int> next = {cur_pos.first+directions[(dir+i)%4].first, cur_pos.second+directions[(dir+i)%4].second};
	       if(grid[next.first][next.second]=='#')continue;
	       vector<long long> tupnext = {next.first, next.second,cost};
	       if(min_dist.find(tupnext) != min_dist.end() && min_dist[tupnext] <= cost) continue;
	       q.push({cost, next.first, next.second, (dir+i)%4});
	     } 
	}
	return res;
}
int main(){
  directions[0] = {0,1};
  directions[1] = {1,0};
  directions[2] = {0,-1};
  directions[3] = {-1,0};
  string line;
  while(cin>>line)grid.push_back(line);
  n = grid.size(), m = grid.front().size();
  pair<int, int> start, end;
  for(int i = 0 ; i < n;  i++){
      for(int j = 0; j < m; j++){
	      if(grid[i][j]=='S')start = {i,j};
	      if(grid[i][j]=='E')end = {i,j};
      }
  }
  long long res = bfs(start, end);
  cout << res <<endl;
  return 0;
}
