#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

		ifstream in_file = OpenInFileStream("In file: ");
		ofstream out_file = OpenOutFileStream("Out file: ");

		/* Generate Headers */


		/* Cleanup */

		in_file.close();
		out_file.close();

	} while (!finished);

	/* Exiting */

	cin.get();
	return EXIT_SUCCESS;
}