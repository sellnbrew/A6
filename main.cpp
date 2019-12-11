#include "Sorting.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  int arr[5]={1,2,3,4,5};
  int size = *(&arr + 1) - arr;
  cout<<size<<endl;
 return 0;
}
