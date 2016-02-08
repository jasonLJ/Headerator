#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "SourceHeaderPair.h"
#include "File.h"
#include "Headerator.h"

using namespace std;
using namespace HeaderatorEngine;

/* Initialization */

Headerator::Headerator(vector<SourceHeaderPair> file_pairs)
{
	this->file_pairs_ = file_pairs;
}

/* Getters */

vector<SourceHeaderPair> Headerator::GetFilePairs()
{
	vector<SourceHeaderPair> out_pairs;

	return out_pairs;
}

/* Generation */

vector<File> Headerator::GenerateHeaders()
{
	/* Parsing */

	vector<File> out_files;

	return out_files;
}