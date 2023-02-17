#pragma once
#include "Error.h"
#include "LT.h"
#include "IT.h"

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <queue>
#pragma once
#include "Error.h"

namespace Polish {
	void startPolish(LT::LexTable& LT);
	bool polishNotation(int i, LT::LexTable& LT);
}