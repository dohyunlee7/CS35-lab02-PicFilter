/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2019
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    // TODO: implement this function correctly
    int r = 0;
    for (int i = 0; i < width; i++) {
      if (i < x){
        r += 3;
      } else {
        r += 0;
      }
      for (int j = 0; j < width; j++){
        if (j < y){
          r += 3;
        } else {
          r += 0;
        }
      }
    }
    return r;
}

void noRed(int width, int height, int* ppm) {
  // TODO: this image transformation
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y);
      ppm[r] = 0;
    }
  }
}
void noGreen(int width, int height, int* ppm){
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y) + 1;
      ppm[r] = 0;
    }
  }
}
void noBlue(int width, int height, int* ppm){
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y) + 2;
      ppm[r] = 0;
    }
  }
}

void invert(int width, int height, int* ppm){
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y);
      int g = pixelToIndex(width, x, y) + 1;
      int b = pixelToIndex(width, x, y) + 2;
      ppm[r] = abs(ppm[r] - 255);
      ppm[g] = abs(ppm[g] - 255);
      ppm[b] = abs(ppm[b] - 255);
    }
  }
}
void grayscale(int width, int height, int* ppm){
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y);
      int g = pixelToIndex(width, x, y) + 1;
      int b = pixelToIndex(width, x, y) + 2;
      int sum = (ppm[r] + ppm[g] + ppm[b]) / 3;
      ppm[r] = sum;
      ppm[g] = sum;
      ppm[b] = sum;
    }
  }
}
void swap(int i, int j, int* ppm) {
  int temp = ppm[i];
  ppm[i]= ppm[j];
  ppm[j] = temp;
}
void flipHorizontally(int width, int height, int* ppm){
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width/2; x++) {
      int r = pixelToIndex(width, x, y);
      int fr = pixelToIndex(width, width-x-1, y);
      swap(r, fr, ppm);
      swap(r+1, fr+1, ppm);
      swap(r+2, fr+2, ppm);
    }
  }
}
void flipVertically(int width, int height, int* ppm){
  for (int y = 0; y < height/2; y++) {
    for (int x = 0; x < width; x++) {
      int r = pixelToIndex(width, x, y);
      int fr = pixelToIndex(width, x, height-1-y);
      swap(r, fr, ppm);
      swap(r+1, fr+1, ppm);
      swap(r+2, fr+2, ppm);
    }
  }
}
// TODO: write your other image transformation functions here

/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/
