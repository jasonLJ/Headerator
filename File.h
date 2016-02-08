#ifndef HEADERATOR_FILE_H_
#define HEADERATOR_FILE_H_

using namespace std;

namespace HeaderatorEngine
{
	class File
	{

		/* Members */

		string file_name_;
		vector<string> lines_;

	public:

		/* Initialization */

		File(string file_name);

		File(string file_name, vector<string> lines);

		/* Getters */

		string GetName();

		vector<string> GetLines();

		string GetLine(int line_number);

		int GetLineCount();

		/* Setters */

		void SetName(string file_name);

		void SetLines(vector<string> lines);

		void SetLine(string line, int line_number);

		/* File Reading */

		void ReadFile();

		void ReadFile(string file_name);

		void ReadFile(ifstream& file_stream);

	};
}

#endif