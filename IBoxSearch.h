#pragma once

#include "Boxes.h"

class IBoxSearch
{
public:
   virtual ~IBoxSearch() {}
   virtual int FindBox(Boxes& boxes, int boxNum, bool printGuesses) = 0;
};
