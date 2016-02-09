#pragma once

using namespace std;

namespace HeaderatorIO
{
	/* Constants */

	// Box Properties
	const int kBoxWidth = 80;
	const int kBoxHeightRadius = 2;

	/* Basic */

	string InputString(string prompt = "");

	/* Files */

	ifstream OpenInFileStream(string prompt = "");

	ofstream OpenOutFileStream(string prompt = "");

	/* Boxes */

	void PrintBox(ostream& out_stream, string text);

	void PrintLinesBox(ostream& out_stream, vector<string> lines, int maximum_lines = kBoxHeightRadius * 2);

	string InputStringBox(string prompt);

	bool InputChoiceBox(string prompt, string choice_box, char true_value, char false_value, bool case_sensitive = false);

	/* Box Helpers */

	void PrintSurround(ostream& out_stream, char left, char right, char middle, int repititions);

	/* Miscellaneous */

	void ClearScreen();

	void PrintLineBreak(ostream& out_stream);

	string AlignCenter(string s, int width, char filler = ' ');
}
