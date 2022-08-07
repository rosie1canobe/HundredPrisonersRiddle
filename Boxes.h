#pragma once
#include <vector>

class Boxes
{
public:
   Boxes();

   void PopulateRandom();

   void PrintBoxes();

   int At(int index);

private:
   std::vector<int> mBoxData;
};
