#include <bits/stdc++.h>
using namespace std;
long long getCombo(int val, map<string, long long> &registers){
   if(val>=0 && val<=3)return val;
   if(val==4)return registers["A"];
   if(val==5)return registers["B"];
   if(val==6)return registers["C"];
   return 0;
}
string solve(map<string, long long> registers, vector<pair<int, int>>opcode){
   int instruc_pointer=0;
   string res="";
   while(instruc_pointer<opcode.size()){
	int op = opcode[instruc_pointer].first, comb = getCombo(opcode[instruc_pointer].second, registers), literal = opcode[instruc_pointer].second;
	if(op==0) registers["A"] = registers["A"]/(1<<comb);
	else if(op==1) registers["B"] ^= literal;
	else if(op==2) registers["B"] = comb%8;
	else if(op==3){
	   if(registers["A"]!=0 && instruc_pointer != literal){
		   instruc_pointer = literal;
		   continue;
	   }
	}else if(op==4) registers["B"] ^= registers["C"];
	else if(op==5) res += to_string(comb%8)+",";
	else if(op==6) registers["B"] = registers["A"]/(1<<comb);
	else if(op==7) registers["C"] = registers["A"]/(1<<comb);

	instruc_pointer++;
   }
   res.pop_back();
   return res;
}
int main(){
   map<string, long long> registers;
   scanf("Register A: %lld\n", &registers["A"]);
   scanf("Register B: %lld\n", &registers["B"]);
   scanf("Register C: %lld\n", &registers["C"]);
   vector<pair<int, int>>opcode;
   int op, combo;
   scanf("Program: ");
   while(scanf("%d,%d,", &op, &combo)!=EOF){
	   opcode.push_back({op, combo});
   }
   cout << solve(registers, opcode)<<endl;

   return 0;
}
