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
	cout << file_name << "lKLKL";
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
	return lines_.at(line_number);
}

int File::GetLineCount()
{
	return 0;
}

/* Setters */

void File::SetName(string file_name)
{
	file_name_ = file_name;
}

void File::SetLines(vector<string> lines)
{
	lines_ = lines;
}

void File::SetLine(string line, int line_number)
{
	lines_.at(line_number) = line;
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
	file_stream.close();
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