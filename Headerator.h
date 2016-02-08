#ifndef HEADERATOR_IO_H_
#define HEADERATOR_IO_H_

using namespace std;

namespace HeaderatorEngine
{
	class Headerator
	{

		/* Members */

		vector<SourceHeaderPair> file_pairs_;

	public:

		/* Initialization */

		Headerator(vector<SourceHeaderPair> file_pairs);

		/* Getters */

		vector<SourceHeaderPair> GetFilePairs();

		/* Generation */

		vector<File> GenerateHeaders();

	};
}

#endif