#include <iostream>
#include <fstream>
#include <string>
#include "HeaderatorIO.h"

using namespace std;

/* Basic */

string HeaderatorIO::InputString(string prompt)
{
	cout << prompt;

	string value;

	getline(cin, value);
	return value;
}

/* Files */

ifstream HeaderatorIO::OpenInFileStream(string prompt)
{
	ifstream file;

	do
	{
		string file_name = InputString(prompt);
		file.open(file_name);

	} while (!file.is_open());

	return file;
}

ofstream HeaderatorIO::OpenOutFileStream(string prompt)
{
	ofstream file;

	do
	{
		string file_name = InputString(prompt);
		file.open(file_name);

	} while (!file.is_open());

	return file;
}