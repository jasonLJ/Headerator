#include <string>
#include <vector>
#include "Function.h"

using namespace std;
using namespace HeaderatorEngine;

/* Initialization */

Function::Function(vector<string> lines)
{
	this->lines_ = lines;
}

/* Getters */

vector<string> Function::GetLines()
{
	return lines_;
}

vector<string> Function::GetArguments()
{
	string first_line = GetLines().at(0);
	
	// Separate out just the arguments from the function identifier
	int arguments_beginning = first_line.find("(") + 1;
	int arguments_ending = first_line.find(")") - 1;

	string arguments_line = first_line.substr(arguments_beginning, arguments_ending + 1);

	// Search through the arguments line for each individual argument
	bool done_searching_arguments = false;
	vector<string> arguments;
	int next_argument_index;

	do
	{
		// Find the next comma, which might not even be there :^o
		int next_comma_index = arguments_line.find(",");

		// See if we're done searching
		if (next_comma_index == string::npos)
		{
			done_searching_arguments = true;
			next_argument_index = arguments_line.length();
		}
		else {
			next_argument_index = next_comma_index;
		}
		
		// Pull the current argument
		string current_argument = arguments_line.substr(0, next_argument_index);
		arguments.push_back(current_argument);

		// Chop up the arguments line if we're still searching
		if (!done_searching_arguments)
			// + 1 so that we get rid of the comma too
			arguments_line = arguments_line.substr(0, next_argument_index + 1);

	} while (!done_searching_arguments);

	return arguments;
}

string Function::GetName()
{
	return "";
}

string Function::GetIdentifier(bool include_return_type, bool include_arguments)
{
	return "";
}

int Function::GetLineCount()
{
	return 0;
}