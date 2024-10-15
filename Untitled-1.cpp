Description
Please implement a simple program to manage a digital library. You  need to realize the operations on the library  including:  

(1)  Add a book: Each book is recorded as a triple (name, author,  price). The name and author of a book is presented as a string and the price is  presented as a float number.

(2)  Remove a book given its  name and author.

(3)  Find a book given its  name. If multiple books have a same name, all the matched books should be  found.

Input
The input consists of T operations. The number T is given in the  first line of the input. Each one of the following T lines contains a string  representing an operation. Each operation is belonging to one of the following  3  formats:

(1) ADD (name) (author)  (price)

(2) REMOVE (name)  (author)

(3) FIND  (name)

Output
The output consists of T lines. The No i  lines presents the result of the No. i operation. The result is belonging to one  of the following 3 cases:

(1) The case when the operation input is ‘ADD (name) (author) (price)’. If  there is another book in the library with the same name and author as the input,  print ‘FAIL’. Otherwise, add the book into the library and print  ‘SUCCESS’

(2) The case when the operation input is ‘REMOVE (name) (author)’. If  there is no book in the library with the same name and author as the input,  print ‘FAIL’. Otherwise, remove the book from the library and print  ‘SUCCESS’.

(3) The case when the operation input is ‘FIND (name)’. Print the  count of the books in the library with the name as the input.

Sample Input
6
ADD (Data Structure) (Clifford A. Shaffer) (30.50)
ADD (Data Structure) (Clifford A. Shaffer) (100.50)
ADD (Data Structure) (Will A. Shaffer) (10.50)
REMOVE (Data Structure) (Jimmy Lud)
FIND (Data Structure) 
REMOVE (Data Structure) (Will A. Shaffer)


Sample Output
SUCCESS
FAIL
SUCCESS
FAIL
2
SUCCESS





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
