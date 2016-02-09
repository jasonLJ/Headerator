#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "BoxDrawingConstants.h"
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

/* Boxes */

void HeaderatorIO::PrintBox(ostream& out_stream, string text)
{
	int internal_space = kBoxWidth - 2;

	// Top of the box
	PrintSurround(out_stream, kThinDownRight, kThinDownLeft, kThinHorizontal, internal_space);
	PrintLineBreak(out_stream);

	// Empty spaces leading down to middle line
	int blank_lines = kBoxHeightRadius - 1;

	for (int i = 0; i < blank_lines; i++)
	{
		PrintSurround(out_stream, kThinVertical, kThinVertical, kEmpty, internal_space);
		PrintLineBreak(out_stream);
	}

	// Print the message line
	string middle_line = AlignCenter(text, internal_space);
	out_stream << kThinVertical << middle_line << kThinVertical << endl;

	// Empty spaces leading down to bottom line
	for (int i = 0; i < blank_lines; i++)
	{
		PrintSurround(out_stream, kThinVertical, kThinVertical, kEmpty, internal_space);
		PrintLineBreak(out_stream);
	}

	// Bottom line
	PrintSurround(out_stream, kThinUpRight, kThinUpLeft, kThinHorizontal, internal_space);
	PrintLineBreak(out_stream);
}

void HeaderatorIO::PrintLinesBox(ostream& out_stream, vector<string> lines, int maximum_lines)
{
	int internal_space = kBoxWidth - 2;

	// Top of the box
	PrintSurround(out_stream, kThinDownRight, kThinDownLeft, kThinHorizontal, internal_space);
	PrintLineBreak(out_stream);

	// Print the lines
	int line_count = lines.size() > maximum_lines ? maximum_lines : lines.size();

	for (int i = 0; i < line_count; i++)
	{
		string current_line = lines.at(i);
		
		// Replace tabs with 4 spaces
		string 

		// See if we need to shorten this line to make it fit within the box
		if (current_line.length() > internal_space)
		{
			current_line = current_line.substr(0, internal_space - kEllipses.length());
			current_line += kEllipses;
		}

		out_stream << kThinVertical << current_line;

		int right_padding = internal_space - current_line.length();

		for (int i = 0; i < right_padding; i++)
			cout << kEmpty;

		cout << kThinVertical << endl;
	}

	// Bottom line
	PrintSurround(out_stream, kThinUpRight, kThinUpLeft, kThinHorizontal, internal_space);
	PrintLineBreak(out_stream);
}

string HeaderatorIO::InputStringBox(string prompt)
{
	PrintBox(cout, prompt);
	string input;

	cout << kInputPrompt;
	getline(cin, input);

	return input;
}

bool HeaderatorIO::InputChoiceBox(string prompt, string choice_box, char true_value, char false_value, bool case_sensitive)
{
	PrintBox(cout, prompt);
	char input;

	do
	{
		cin.clear();
		cout << choice_box << " " << kInputPrompt;
		input = cin.get();
		cin.ignore(1);

	} while (input != true_value && input != false_value);

	return input == true_value;
}

/* Box Helpers */

void HeaderatorIO::PrintSurround(ostream& out_stream, char left, char right, char middle, int repititions)
{
	out_stream << left;

	for (int i = 0; i < repititions; i++)
		out_stream << middle;

	out_stream << right;
}

/* Miscellaneous */

void HeaderatorIO::ClearScreen()
{
	system("cls");
}

void HeaderatorIO::PrintLineBreak(ostream& out_stream)
{
	out_stream << endl;
}

string HeaderatorIO::AlignCenter(string s, int width, char filler)
{
	int string_length = s.length();

	if (string_length > width)
	{
		s = s.substr(0, width + 1);
		string_length = s.length();
	}

	int total_padding = width - string_length;
	int left_padding = total_padding / 2;
	int right_padding = total_padding - left_padding;

	string aligned_string;

	// Print left padding
	for (int i = 0; i < left_padding; i++)
		aligned_string += filler;

	// Add the sting in the middle
	aligned_string += s;

	// Print right padding
	for (int i = 0; i < right_padding; i++)
		aligned_string += filler;

	return aligned_string;
}