#include <iostream>
#include <array>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
class Sorting{
public:
  int size;
  double *bubbleArr;
  double *insertArr;
  double *selectArr;
  double *mergeArr;

  double bubbleTime;
  double insertTime;
  double selectTime;
  double mergeTime;

  void bubbleSort(double arr[]);
  void insertionSort(double arr[]);
  void selectionSort(double arr[]);
  void mergeSort();
  void merge();

  void makeArrays();
  void printArray();
  void writeFiles();
};
