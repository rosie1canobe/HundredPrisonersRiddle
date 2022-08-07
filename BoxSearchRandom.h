#pragma once

#include "Boxes.h"
#include "IBoxSearch.h"

class BoxSearchRandom : public IBoxSearch
{
public:
   BoxSearchRandom();

   virtual ~BoxSearchRandom();

   virtual int FindBox(Boxes& boxes, int boxNum, bool printGuesses);

private:
   Boxes mRandomGuesses;
};
