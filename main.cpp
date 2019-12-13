#include "Sorting.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  Sorting *s=new Sorting();
  s->makeArrays();
  s->insertionSort(s->insertArr);
  s->bubbleSort(s->bubbleArr);
  s->writeFiles();
 return 0;
}
