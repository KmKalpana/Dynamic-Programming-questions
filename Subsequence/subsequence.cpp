#include <bits/stdc++.h>
using namespace std;
vector<string> getSequence(string p, string str)
{
	if (str.length() == 0)
	{
		vector<string> e;
		e.push_back(p);
		return e;
	}

	char ch = str[0];
	vector<string> left = getSequence(p+ch,str.substr(1));
	vector<string> right = getSequence(p,str.substr(1));
	for(int i=0; i<right.size(); i++)
	{
	    left.push_back(right[i]);
	}
	return left;
}
int main()
{
	string str="rwpddkvbnnuglnagtvamxkqtwhqgwbqgfbvgkwyuqkdwhzudsxvjubjgloeofnpjqlkdsqvruvabjrikfwronbrdyyjnakstqjac";
	string p="";
	vector<string> st=getSequence(p,str);
    for(int i=0; i<st.size(); i++)
    {
        cout<<st[i]<<" ";
    }
	return 0;
}
