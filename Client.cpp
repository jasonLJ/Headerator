#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SourceHeaderPair.h"
#include "Headerator.h"
#include "HeaderatorIO.h"

using namespace std;
using namespace HeaderatorEngine;
using namespace HeaderatorIO;

int main()
{
	/* Setup */

	bool finished = true;

	do {

		/* File Input Prompting */

		bool inputting = true;
		vector<SourceHeaderPair> pairs;

		do
		{
			ClearScreen();

			// Grab the header
			string header_file_name = InputStringBox("Header File Name?");
			cout << header_file_name;
			File header(header_file_name);
			header.ReadFile();

			ClearScreen();

			// Grab the source
			string source_file_name = InputStringBox("Source File Name?");
			File source(source_file_name);
			source.ReadFile();

			ClearScreen();

			// Create and add the pair
			SourceHeaderPair new_pair = { header, source };
			pairs.push_back(new_pair);

			// Show which files have already been input
			vector<string> file_names;

			for (SourceHeaderPair pair : pairs)
			{
				file_names.push_back(pair.header.GetName());
				file_names.push_back(pair.source.GetName());
			}

			PrintBox(cout, "Current Files...");
			PrintLinesBox(cout, file_names);

			// Ask if adding another file
			const char Yes = 'y';
			const char No = 'n';

			inputting = InputChoiceBox("More Files?", "([Y]es | [N]o)", Yes, No);

		} while (inputting);

		/* Generate Headers */

		Headerator headerator(pairs);
		vector<File> headers = headerator.GenerateHeaders();

	} while (!finished);

	/* Exiting */

	cout << endl << "Exiting...";
	cin.get();
	return EXIT_SUCCESS;
}