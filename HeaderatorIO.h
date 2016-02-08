#pragma once

using namespace std;

namespace HeaderatorIO
{

	/* Basic */

	string InputString(string prompt = "");

	/* Files */

	ifstream OpenInFileStream(string prompt = "");

	ofstream OpenOutFileStream(string prompt = "");

}
