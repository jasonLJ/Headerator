#ifndef HEADERATOR_SOURCE_HEADER_PAIR_H_
#define HEADERATOR_SOURCE_HEADER_PAIR_H_

#include "File.h"

using namespace std;
using namespace HeaderatorEngine;

struct SourceHeaderPair
{
	File header;
	File source;
};

#endif