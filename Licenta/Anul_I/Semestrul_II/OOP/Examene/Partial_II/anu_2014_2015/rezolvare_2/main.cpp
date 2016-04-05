#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<vector>

using namespace std;

bool splitString(string input, string delimiter)
{
	char *pch;
	char *str = (char*)input.c_str();
	int k = 0;
	pch = strtok(str, delimiter.c_str());
	while (pch != NULL)
	{
		if (atoi(pch) >= 10)
			k = 1;
		pch = strtok(NULL, delimiter.c_str());
	}
	if (k == 0)
		return true;
	return false;
}

int main()
{
	string str = "1+2+3-4-10";

	cout << splitString(str,"+-");

	return 0;
}