#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> edge_list;
vector<vector<int>>updates;

vector <int> topologicalSort(unordered_map<int, int> &inDegree, unordered_map<int, vector<int>>&adjList){
   queue<int> q;
   vector<int> path;
   for(auto [node, counter]: inDegree){
	   if(counter==0) q.push(node);
   }
   int index = 0;
   while(!q.empty()){
	auto current = q.front(); q.pop();
	path.push_back(current);
	for(auto _to: adjList[current]){
	    inDegree[_to]--;
	    if(inDegree[_to]==0) q.push(_to);
	}
   }
   return path;
}
void read_data(){
    string line;
    int num1, num2, num;
    char del;
    while(true){
	getline(cin, line);
	if(line.empty())break;
	stringstream ss(line);
	ss >> num1 >> del>>num2;
	edge_list.insert({num1, num2});
    }
    while(true){
	getline(cin, line);
	if(line.empty()) break;
	stringstream ss(line);
	vector<int> row;
	while(ss>>num>>del) row.push_back(num);
	ss>>num; row.push_back(num); 
	updates.push_back(row);
    }
}
long long solve(){
   long long res = 0;
   for(auto pages:updates){
	set<int> marked;
	unordered_map<int, int> inDegree;
	for(auto page:pages){
		marked.insert(page);
		inDegree[page]=0;
	}
	unordered_map<int, vector<int>> adj_list;
	for(auto [_from, _to]:edge_list){
		if(marked.find(_from) == marked.end() || marked.find(_to) == marked.end()) continue;
		adj_list[_from].push_back(_to);
		inDegree[_to]++;
	}
	auto path = topologicalSort(inDegree, adj_list);
	if(path != pages) res += path[path.size()/2];
   }
   return res;
}
int main(){
    read_data();
    auto res = solve(); 
    cout <<res <<endl;
}
