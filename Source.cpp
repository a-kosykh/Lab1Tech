#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) // added commentary
{
	setlocale(LC_ALL, "Russian");
	
	string file1 = argv[1];
	string file2 = argv[2];

	ifstream fileout1, fileout2;

	vector<size_t> hashes1, hashes2;

	fileout1.open(file1.c_str());
	fileout2.open(file2.c_str());
	
	if (!fileout2.is_open())
		cout << "File could not be opened" << endl;
	else
	{

		string str2;
		while (getline(fileout2, str2))
			hashes2.insert(hashes2.end(), hash<string>{}(str2));

	}

	if (!fileout1.is_open())
		cout << "File could not be opened" << endl;
	else
	{

		string str1;
		while (getline(fileout1, str1))
			hashes1.insert(hashes1.end(), hash<string>{}(str1));

	}

	fileout1.close();
	fileout2.close();

	fileout1.open(file1.c_str());
	fileout2.open(file2.c_str());

	vector<size_t>::iterator iter1, iter2;
	string str1, str2;
	unsigned i1 = 0, i2 = 0;
	bool p;
	
	if (!fileout1.is_open())
		cout << "File could not be opened" << endl;
	else
	{
		while (getline(fileout1, str1))
		{
			i1++;
			p = 0;
			for (iter2 = hashes2.begin(); iter2 != hashes2.end(); ++iter2)
			{
				if (hash<string>{}(str1) == *iter2)
				{
					p = 1;
				}
			}
			if (p == 0)
			{
				cout << "file1 " << i1 << " " << str1 << endl;
			}
		}

	}

	if (!fileout2.is_open())
		cout << "File could not be opened" << endl;
	else
	{
		while (getline(fileout2, str2))
		{
			i2++;
			p = 0;
			for (iter1 = hashes1.begin(); iter1 != hashes1.end(); ++iter1)
			{
				if (hash<string>{}(str2) == *iter1)
				{
					p = 1;
				}
			}
			if (p == 0)
			{
				cout << "file2 " << i2 << " " << str2 << endl;
			}
		}

	}


	fileout1.close();
	fileout2.close();


	system("pause");
	return 0;
}
