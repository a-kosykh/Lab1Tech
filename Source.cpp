#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{

    ifstream fileout1, fileout2;

    vector<size_t> hashes1, hashes2;

    fileout1.open("file1.txt");
    fileout2.open("file2.txt");
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

    /*cout << "The original vector : " << endl;
    for (unsigned int i = 0; i < (hashes.end() - hashes.begin()); i++)
        cout << hashes[i] << endl;
        */


    fileout1.open("file1.txt");
    fileout2.open("file2.txt");

    for (unsigned int i =0; i < 4; i++)
    {
        cout << hashes1[i] << endl;
        cout << hashes2[i] << endl;
    }

    vector<size_t>::iterator iter1, iter2;
    string str1, str2;
    bool p;
    if (!fileout1.is_open())
        cout << "File could not be opened" << endl;
    else
    {
        cout << "These strings are different :" << endl;
        cout << "**************************************" << endl;
        while (getline(fileout1, str1))
        {
            p = 0;
            for (iter2 = hashes2.begin(); iter2 != hashes2.end(); ++iter2)
            {
                if (hash<string>{}(str1) == *iter2)
                {
                    p = 1;
                }
            }
            if(p == 0)
            {
                cout << str1 << endl;
                cout << "----------------------------------" << endl;
            }
        }

    }

    if (!fileout2.is_open())
        cout << "File could not be opened" << endl;
    else
    {
        while (getline(fileout2, str2))
        {
            p = 0;
            for (iter1 = hashes1.begin(); iter1 != hashes1.end(); ++iter1)
            {
                if (hash<string>{}(str2) == *iter1)
                {
                    p = 1;
                }
            }
            if(p == 0)
            {
                cout << str2 << endl;
                cout << "----------------------------------" << endl;
            }
        }

    }


    fileout1.close();
    fileout2.close();

    system("pause");
    return 0;
}

