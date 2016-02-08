#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "File.h"

using namespace std;
using namespace HeaderatorEngine;

/* Initialization */

File::File(string file_name)
{
	this->file_name_ = file_name;
}

File::File(string file_name, vector<string> lines)
{
	this->file_name_ = file_name;
	this->lines_ = lines;
}

/* Getters */

string File::GetName()
{
	return file_name_;
}

vector<string> File::GetLines()
{
	return lines_;
}

string File::GetLine(int line_number)
{

}

int File::GetLineCount()
{

}

/* Setters */

void File::SetName(string file_name)
{

}

void File::SetLines(vector<string> lines)
{

}

void File::SetLine(string line, int line_number)
{

}

/* File Reading */

void File::ReadFile()
{
	ReadFile(GetName());
}

void File::ReadFile(string file_name)
{
	ifstream file_stream(file_name);
	ReadFile(file_stream);
}

void File::ReadFile(ifstream& file_stream)
{
	vector<string> lines;
	string current_line;

	while (getline(file_stream, current_line))
	{
		lines.push_back(current_line);
	}

	SetLines(lines);
}