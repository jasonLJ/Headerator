#ifndef HEADERATOR_FUNCTION_H_
#define HEADERATOR_FUNCTION_H_

using namespace std;

namespace HeaderatorEngine
{
	class Function
	{

		/* Members */

		vector<string> lines_;

	public:

		/* Initialization */

		Function(vector<string> lines);

		/* Getters */

		vector<string> GetLines();

		string GetName();

		vector<string> GetArguments();

		string GetIdentifier(bool include_return_type = true, bool include_arguments = true);

		int GetLineCount();

		/* Setters */
		
	};
}

#endif