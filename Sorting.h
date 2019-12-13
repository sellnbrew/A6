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
  double *quickArr;

  double bubbleTime;
  double insertTime;
  double selectTime;
  double mergeTime;
  double quickTime;

  void bubbleSort(double arr[]);
  void insertionSort(double arr[]);
  void selectionSort(double arr[]);
  void mergeSort(double arr[], int left, int right);
  void merge(double arr[],int left,int middle,int r);
  void quickSort(double arr[], int start, int end);
  int partition (double arr[], int start, int end);

  void makeArrays();
  void printArray();//unused
  void writeFiles();
  void sort();
};
