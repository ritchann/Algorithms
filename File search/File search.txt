#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string> 
#include <algorithm> 
#include <cstdlib> 
#include <vector> 
#include <cmath> 
#include <set> 
#include <iterator> 
#include <map>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <cassert>
#include <cstddef>
#include <windows.h>
#include <direct.h>
#include <io.h>

using namespace std;

bool Search(string waydir)
{
	_finddata_t data;
	intptr_t handle, handle_pred;
	string base = waydir, strsearch = "", dop = "", strname = "bobo.txt", hp = "", vv = "";
	strsearch = base + "*";
	const char *str = strsearch.c_str();
	queue<string> a;
	handle = _findfirst(str, &data);
	while (_findnext(handle, &data) == 0)
	{
		if (data.name == strname)
		{
			hp = waydir;
			vv = hp + "\\" + data.name;
			const char *str1 = vv.c_str();
			const char *FName = str1; 
			char ch = 0;
			ifstream in1(FName);
			string buf;
			while (getline(in1, buf))
				cout << buf << endl;
			in1.close();
			return 1;
		}
	char end = '\0';
		if (data.attrib&_A_SUBDIR)
		{
			if (data.attrib&_A_HIDDEN || data.attrib&_A_RDONLY || data.attrib&_A_ARCH) {}
			else
			{
                                string gh = ".." + end;
				if (data.name != gh)
				{
				dop = "";
				dop = base + data.name;
				a.push(dop);
                              }
			}
		}
	}
	while (!a.empty())
	{
		strsearch = "";
		hp = a.front();
		strsearch = hp + "\\*";
		a.pop();
		const char *str = strsearch.c_str();

		handle = _findfirst(str, &data);
		while (_findnext(handle, &data) == 0)
		{

			if (data.name == strname)
			{
				vv = hp + "\\" + data.name;
				const char *str1 = vv.c_str();
				const char *FName = str1; 
				char ch = 0;
				ifstream in1(FName);
				string buf;
				while (getline(in1, buf))
					cout << buf << endl;
				in1.close();
				return 1;
			}
			if (data.attrib&_A_SUBDIR)
			{
				if (data.attrib&_A_HIDDEN || data.attrib&_A_RDONLY || data.attrib&_A_ARCH || data.attrib&_A_SYSTEM) {}
				else
				{
					dop = hp + "\\" + data.name;
					a.push(dop);
				}
			}
		}
	}
	_findclose(handle);
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	if (Search("D:\\") || Search("C:\\"))
		cout << "We found the file" << endl;
	else
		cout << "We didn't find the file" << endl;
	system("pause");
}
