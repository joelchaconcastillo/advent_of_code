#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> topologicalSort(unordered_map<int, int> &inDegree, unordered_map<int, vector<int>>&adjList){
   queue<int> q;
   unordered_map<int, int> num2Index;
   for(auto [node, counter]: inDegree){
	   if(counter==0) q.push(node);
   }
   int index = 0;
   while(!q.empty()){
	auto current = q.front(); q.pop();
	num2Index[current]=index++;
	for(auto _to: adjList[current]){
	    inDegree[_to]--;
	    if(inDegree[_to]==0) q.push(_to);
	}
   }
   return num2Index;
}
int main(){
    string line;
    int num1, num2, num;
    long long res = 0;
    char del;
    set<pair<int, int>> edge_list;
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
	set<int> marked;
	unordered_map<int, int> inDegree;
	while(ss>>num>>del) row.push_back(num), marked.insert(num), inDegree[num]=0;
	ss>>num; row.push_back(num); marked.insert(num), inDegree[num]=0;
	unordered_map<int, vector<int>> adj_list;
	for(auto [_from, _to]:edge_list){
		if(marked.find(_from) == marked.end() || marked.find(_to) == marked.end()) continue;
		adj_list[_from].push_back(_to);
		inDegree[_to]++;
	}
	auto num2Index = topologicalSort(inDegree, adj_list);
	bool check=true;
	for(int i = 0 ; i+1 < row.size(); i++){
	   check &= num2Index[row[i]]<num2Index[row[i+1]];
	}
	if(check)
	res += row[row.size()/2];
    }
    cout <<res <<endl;
}
