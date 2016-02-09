#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "SourceHeaderPair.h"
#include "File.h"
#include "HeaderatorIO.h"
#include "Headerator.h"

using namespace std;
using namespace HeaderatorEngine;
using namespace HeaderatorIO;

/* Initialization */

Headerator::Headerator(vector<SourceHeaderPair> file_pairs)
{
	this->file_pairs_ = file_pairs;
}

/* Getters */

vector<SourceHeaderPair> Headerator::GetFilePairs()
{
	return file_pairs_;
}

/* Generation */

vector<File> Headerator::GenerateHeaders()
{
	/* Parsing */

	ClearScreen();

	for (SourceHeaderPair pair : GetFilePairs())
	{
		cout << pair.header.GetName() << ", " << pair.source.GetName() << endl;
		PrintLinesBox(cout, pair.header.GetLines(), 25);
		PrintLinesBox(cout, pair.source.GetLines(), 25);
	}

	vector<File> out_files;

	return out_files;
}