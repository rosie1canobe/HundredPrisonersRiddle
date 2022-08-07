// PrisonRiddleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Defines.h"
#include "Boxes.h"
#include "IBoxSearch.h"
#include "BoxSearchRandom.h"
#include "BoxSearchClosedLoop.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;


int main()
{
   // Seed random number generator.
   srand(static_cast<unsigned int>(time(0)));

   Boxes boxes;
   boxes.PopulateRandom();
//   boxes.PrintBoxes();

   BoxSearchRandom randomSearch;
   BoxSearchClosedLoop CLSearch;
   int answer = 9;

//   int numGuessesRandom = randomSearch.FindBox(boxes, answer, false);
//   cout << "(Random) It took " << numGuessesRandom
//      << " guesses to get the answer (" << answer << ")." << endl;

//   int numGuessesClosed = CLSearch.FindBox(boxes, answer, false);
//   cout << "(Closed Loop) It took " << numGuessesClosed
//      << " guesses to get the answer (" << answer << ")." << endl;
   int numSuccesses = 0;
   int totalRuns = 100000;

   for (int numRuns = 0; numRuns < totalRuns; numRuns++)
   {
      // New loop, regenerate the boxes randomly.
      boxes.PopulateRandom();

      int numGuessesPrisoner = 0;
      bool prisonersSucceed = true;
      for (int prisoner = 0; prisoner < TOTAL_BOXES; prisoner++)
      {
         numGuessesPrisoner = CLSearch.FindBox(boxes, prisoner, false);

         if (numGuessesPrisoner > (TOTAL_BOXES / 2))
         {
            //cout << "Prisoner " << prisoner << " failed with " << numGuessesPrisoner << " guesses." << endl;
            prisonersSucceed = false;
            break;
         }
      }

      if (prisonersSucceed)
      {
         numSuccesses++;
        //cout << "Amazing!  the prisoners actually succeeded!!!!" << endl;
      }
   }

   cout << "Out of " << totalRuns << " runs, prisoners succeeded " << numSuccesses << " times." << endl;
   cout << " Successs Rate: " <<
      (static_cast<double>(numSuccesses) / static_cast<double>(totalRuns)) * 100.0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
