#include <bits/stdc++.h>
using namespace std;
unordered_map<string, unordered_map<string, bool> > sparse_matrix;
unordered_set<string>computers;
bool canBeMerged(const set<string> &clique, const string &node){
   bool check=true;
   for(auto inner_node:clique){
       if(!sparse_matrix[node].count(inner_node))return false;
   }
   return check;
}
string solve(){
   string password="";
   set<set<string>>cliques;
   for(auto i:computers) cliques.insert({i});//each clique is the own point
   set<string> maxClique;
   bool hasChanged=true;
   while(hasChanged){ //repeat process until there are not changes
      hasChanged=false;
      set<set<string> > new_cliques;
      for(auto &clique:cliques){
	 auto cpy_clique = clique;
         for(auto &node:computers){
	     if(canBeMerged(cpy_clique, node))cpy_clique.insert(node), hasChanged=true;
	 }
	 new_cliques.insert(cpy_clique);
         if(maxClique.size() < clique.size())maxClique=clique;
      }
      cliques = new_cliques;
   }
   for(auto node:maxClique) password+=node+",";
   password.pop_back();
   return password;
}
int main(){
   string st;
   while(cin>>st){
     string A = st.substr(0,2), B = st.substr(3,2);
     computers.insert(A);
     computers.insert(B);
     sparse_matrix[A][B]=true;
     sparse_matrix[B][A]=true;
   }
   cout << solve()<<endl;
}
