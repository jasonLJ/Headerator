#ifndef HEADERATOR_BOX_DRAWING_CONSTANTS_H_
#define HEADERATOR_BOX_DRAWING_CONSTANTS_H_

#include <string>

using namespace std;

namespace HeaderatorIO

{
	/* Miscellaneous Strings */

	const string kInputPrompt(">>> ");
	const string kEllipses("...");

	/* Miscellaneous Characters */

	const char kEmpty = ' ';

	/* Thin Box Characters */

	const char kThinHorizontal = char(196);
	const char kThinVertical = char(179);

	const char kThinUpLeft = char(217);
	const char kThinUpRight = char(192);
	const char kThinDownLeft = char(191);
	const char kThinDownRight = char(218);

	const char kThinHorizontalUp = char(193);
	const char kThinHorizontalDown = char(194);
	const char kThinVerticalLeft = char(180);
	const char kThinVerticalRight = char(195);

	const char kThinCross = char(197);
}
#endif