/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO: write your program here
    // Remember:
    //   * The first command-line argument in argv is always the name of the
    //     program.
    //   * You can convert from char* to string just by assignment:
    //         string infile = argv[1];
    //   * You should (eventually) have code that deals with the case that your
    //     user gave you too few or too many command-line arguments.
    // Good luck!  Remember to ask for help!
    if (argc == 4) {
      //read input arguments
      string inFile = argv[1];
      string trans = argv[2];
      string outFile = argv[3];
      //read in ppm file
      int *readFile = read_ppm(inFile);
      int width = ppm_width(inFile);
      int height = ppm_height(inFile);
      //if statements of transformations
      if (trans == "noRed"){
        noRed(width, height, readFile);
      } else if (trans == "noGreen") {
        noGreen(width, height, readFile);
      } else if (trans == "noBlue") {
        noBlue(width, height, readFile);
      } else if (trans == "invert") {
        invert(width, height, readFile);
      } else if (trans == "grayscale") {
        grayscale(width, height, readFile);
      } else if (trans == "flipHorizontally") {
        flipHorizontally(width, height, readFile);
      } else if (trans == "flipVertically") {
        flipVertically(width, height, readFile);
      } else {
        cout << "Invalid transformation is given. Please try again." << endl;
        return 0;
      }
      //write the input ppm file onto a new ppm file
      write_ppm(outFile, width, height, readFile);
      delete[] readFile;

    } else {
      cout << "Invalid input. Please try again." << endl;
    }
    return 0;
}
