#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main()
{
	string filename("example");
	ifstream infile_cas("./FluentMesh/" + filename + ".cas");
	if(!infile_cas)
		return -99999;
	string lineS;
	string Begin_S("(0 \"Grid:\")"),End_S("(0 \"Node flags:\")");
	vector<string> vec_s;
	for(;lineS != Begin_S;getline(infile_cas,lineS));
	while(lineS != End_S)
	{
		vec_s.push_back(lineS);
		getline(infile_cas,lineS);
	}

	ofstream outfile_msh("./Mesh/" + filename + ".msh");
	if(!outfile_msh)
		return -77777;
	string s("(");
	for(auto It = vec_s.begin();It != vec_s.end();)
	{
		auto s_it = It -> end();
		if(It -> back() == ')') It -> pop_back();
		if(It -> back() == ')') It -> pop_back();
		outfile_msh << *It;
		if(s != *(++It))
			outfile_msh << endl;
		else
			outfile_msh << *(It++) <<endl;
	}
}