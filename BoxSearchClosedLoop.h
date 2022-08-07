#pragma once

#include "IBoxSearch.h"

class BoxSearchClosedLoop : public IBoxSearch
{
public:
   BoxSearchClosedLoop();
   virtual ~BoxSearchClosedLoop();
   virtual int FindBox(Boxes& boxes, int boxNum, bool printGuesses);
};


