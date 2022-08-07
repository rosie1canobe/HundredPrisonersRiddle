#include "BoxSearchClosedLoop.h"
#include "Defines.h"

BoxSearchClosedLoop::BoxSearchClosedLoop()
{
}

BoxSearchClosedLoop::~BoxSearchClosedLoop()
{
}

int BoxSearchClosedLoop::FindBox(Boxes& boxes, int boxNum, bool printGuesses)
{
   int numGuesses = 1;
   int curBoxIndex = boxNum;
   while ((boxes.At(curBoxIndex) != boxNum) && (numGuesses <= TOTAL_BOXES))
   {
      curBoxIndex = boxes.At(curBoxIndex);
      numGuesses++;
   }

   return numGuesses;
}

