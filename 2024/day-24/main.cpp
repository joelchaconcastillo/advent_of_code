#include <bits/stdc++.h>
using namespace std;
unordered_map<string, long long> nodes;
unordered_map<string, vector<string>>adjList;
unordered_map<string, tuple<string, string, string>> operations;

void parseInput(){
   string st;
   while(getline(cin, st)){
     if(st.empty())break;
     string label = st.substr(0, 3);
     nodes[label] = (int) st.back()-'0';
   }
   while(getline(cin, st)){
     stringstream ss(st);
     string node1, node2, node3, operation, trash;
     ss>>node1>>operation>>node2>>trash>>node3;
     adjList[node1].push_back(node3);
     adjList[node2].push_back(node3);
     operations[node3] = {node1, node2, operation};
   }

}
/*
 * assumptions based on full adder: 
 * Zn = (Xn ⊕ Yn) ⊕ Cn-1
 * Cn = (Xn * Yn) + (Cn-1 * (Xn ⊕ Yn))
 *
 * with C0 = (Xn * Yn)
 * */
string solve(){
   string res="";
   parseInput();
   set<string> wrong;
   unordered_map<char, bool> fixed = {
	{'x', true}, {'z', true}, {'y', true}
   };
   for(auto [node, operation]:operations){
	   auto [node1, node2, op] = operation;
	   if(op=="XOR" && !fixed[node[0]] && !fixed[node1[0]] && !fixed[node2[0]]) wrong.insert(node);
	   if(node[0]=='z' && op != "XOR" && node != "z45") wrong.insert(node);
	   for(auto _to:adjList[node]){
	       auto [_node1, _node2, _op] = operations[_to];
	       if( op=="AND" && _op !="OR" && node1 != "x00" && node2 != "x00") wrong.insert(node);
	       if( op=="XOR" && _op =="OR" ) wrong.insert(node);
	       if( op=="OR" && _op =="OR" ) wrong.insert(node);
	   }
   }
   for(auto _node:wrong) res +=_node+",";
   res.pop_back();
   return res;
}
int main(){
   cout << solve()<<endl;
   return 0;
}
