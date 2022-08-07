#include "Defines.h"
#include "Boxes.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

Boxes::Boxes()
   : mBoxData()
{}

void Boxes::PopulateRandom()
{
   mBoxData.clear();
   int newValue;

   vector<int> data;

   for (int i = 0; i < TOTAL_BOXES; i++)
   {
      data.push_back(i);
   }

   for (int n = TOTAL_BOXES; n > 0; n--)
   {
      newValue = rand() % n;

      mBoxData.push_back(data[newValue]);

      data.erase(data.begin() + newValue);
   }
}

void Boxes::PrintBoxes()
{
   for (int i = 0; i < TOTAL_BOXES; i++)
   {
      if (mBoxData[i] < 10)
         cout << " ";

      cout << mBoxData[i];

      if ((i + 1) % 20 == 0)
         cout << endl;
      else if (i != (TOTAL_BOXES - 1))
         cout << " ";

   }
}


int Boxes::At(int index)
{
   return mBoxData[index];
}
