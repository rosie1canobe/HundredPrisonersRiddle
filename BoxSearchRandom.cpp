#include "BoxSearchRandom.h"
#include "Defines.h"

#include <iostream>

using namespace std;


BoxSearchRandom::BoxSearchRandom()
   : mRandomGuesses()
{
}

BoxSearchRandom::~BoxSearchRandom()
{}

int BoxSearchRandom::FindBox(Boxes& boxes, int boxNum, bool printGuesses)
{
   int count = 1;

   mRandomGuesses.PopulateRandom();

   if (printGuesses)
   {
      cout << endl << "Random Box Order:" << endl;
      mRandomGuesses.PrintBoxes();
      cout << endl << endl;
   }

   for (int i = 0; i < TOTAL_BOXES; i++)
   {
      if (boxes.At(mRandomGuesses.At(i)) == boxNum)
         break;
      count++;
   }
   return count;
}

