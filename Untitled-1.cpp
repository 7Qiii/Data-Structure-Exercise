#include<iostream>
#include<vector>
#include<string>
#include<cstddef>
using namespace std;
#define eleType int
class library
{
public:
	string name, author;
	string price;

	void add(string name1, string author1, string price1)
	{
		name = name1;
		author = author1;
		price = price1;
	}
	
	
};
int find(vector<library>&b, string name_)
	{   
		int size = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].name == name_)
			{
				size++;
			}
		}
		return size;
	}
	
bool remove(vector<library>&a, string name_, string author_)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].name == name_ && a[i].author == author_)
			{
				a.erase(a.begin() + i);
				return true;
			}
		}
		return false;
	}
string cinname(const string& str) {
    size_t leftPos = str.find('(');
    size_t rightPos = str.find(')', leftPos);
    return str.substr(leftPos + 1, rightPos - leftPos - 1);
}

string cinauthor(const string& str) {
    size_t firstLeft = str.find('(', str.find('(') + 1); 
    size_t firstRight = str.find(')', firstLeft); 
    return str.substr(firstLeft + 1, firstRight - firstLeft - 1); 
}

string cinprice(const string& str) {
    size_t lastLeft = str.find_last_of('('); 
    size_t lastRight = str.find(')', lastLeft); 
    return str.substr(lastLeft + 1, lastRight - lastLeft - 1); 
}


int main()
{
	int k=0;
	while (cin >> k)
	{   
        cin.ignore();
		vector<library>a;
		for (int i = 0; i < k; i++)
		{   
			library ans;
			string example;
			
			getline(cin, example);
			size_t rightPos = example.find_first_of(' ');
			string subexample = example.substr(0, rightPos );
			if (subexample == "ADD")
			{
				ans.add(cinname(example), cinauthor(example), cinprice(example));
                int res=0;
                for(int i=0;i<a.size();i++)
                {
                    if(a[i].name==ans.name&&a[i].author==ans.author) res++;
                }
                if(res==0){
				a.push_back(ans);
                cout<<"SUCCESS"<<endl;
                }
                else{
                    cout<<"FAIL"<<endl;
                }
				
			}
			if (subexample == "REMOVE")
			{
				if (remove(a, cinname(example), cinauthor(example))){
                    cout<<"SUCCESS"<<endl;
				}
                else{
                    cout<<"FAIL"<<endl;
                }
			}
            if(subexample=="FIND")
            {
                cout<<find(a,cinname(example))<<endl;
            }

		}

	}
}