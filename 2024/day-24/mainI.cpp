#include <bits/stdc++.h>
using namespace std;
unordered_map<string, long long> nodes;
unordered_map<string, vector<string>>adjList;
unordered_map<string, tuple<string, string, string>> operations;
unordered_map<string, int> inDegree;
vector<string> topSortKahn(){
   queue<string> q;
   for(auto [label, deg]:inDegree) if(deg==0)q.push(label);
   vector<string> topologicalSorting;
   while(!q.empty()){
       auto current = q.front(); q.pop();
       topologicalSorting.push_back(current);
       for(auto _to:adjList[current]){
	   inDegree[_to]--;
	   if(inDegree[_to]==0)q.push(_to);
       }
   }
   return topologicalSorting;
}
int apply(int a, int b, string oper){
   if(oper == "XOR") return a^b;
   else if( oper == "AND")return a&b;
   else return a|b;
}
long long solve(){
   string st;
   while(getline(cin, st)){
     if(st.empty())break;
     string label = st.substr(0, 3);
     nodes[label] = (int) st.back()-'0';
     inDegree[label]=0;
   }
   while(getline(cin, st)){
     stringstream ss(st);

     string node1, node2, node3, operation, trash;
     ss>>node1>>operation>>node2>>trash>>node3;
     inDegree[node3]+=2;
     adjList[node1].push_back(node3);
     adjList[node2].push_back(node3);
     operations[node3] = {node1, node2, operation};
   }
   auto topologicalSorting = topSortKahn();
   for(auto _node:topologicalSorting){
	   if(!operations.count(_node))continue;
	  auto [nodeA, nodeB, oper] = operations[_node];
	  nodes[_node] = apply(nodes[nodeA], nodes[nodeB], oper);
   }
   long long res = 0;
   for(auto [label, val]:nodes){
       if(label[0]!='z')continue;
       long long bit = stoi(label.substr(1,label.size()-1));
       if(val) res |= (1LL<<bit);
   }
   return res;
}
int main(){
   cout << solve()<<endl;
   return 0;
}
