#include "Sorting.h"
void Sorting::bubbleSort(double arr[]){
  auto start = high_resolution_clock::now();
  for(int i=0;i<size;i++)
  {
    int temp=0;
    for(int j =0;j<size-1;j++)
    {
      if(arr[j]>arr[j+1]){
        temp = arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  bubbleTime = duration.count()/0.000001;
}

void Sorting::insertionSort(double arr[]){
  auto start = high_resolution_clock::now();
  for(int j=1;j<size;j++){
    double temp=arr[j];
    int k=j;
    while(k>0&&arr[k-1]>=temp){
      arr[k]=arr[k-1];
      --k;
    }
    arr[k]=temp;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  insertTime = duration.count()/0.000001;
}

void Sorting::makeArrays(){
  string mainFile;
  cout<<"Enter the name of your file: "<<endl;
  cin>>mainFile;
  ifstream file;
  int num;
  file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try{
          string line;
          file.open(mainFile);
          getline(file,line);
          num=stoi(line);//Checked gets num as a num
          size=num;
          bubbleArr = new double[num];
          insertArr = new double[num];
          selectArr = new double[num];
          mergeArr = new double[num];
          quickArr= new double[num];
          for(int i=0;i<size;i++){
            getline(file,line);
            double number = stod(line);//checked working
            bubbleArr[i]=number;//Segmentation fault here ??? why idk
            insertArr[i]=number;
            selectArr[i]=number;
            mergeArr[i]=number;
            quickArr[i]=number;
          }
          file.close();
      }
      catch(std::ifstream::failure e){
        std::cerr << "Exception opening/reading/closing file\n";
      }
}

void Sorting::printArray(){//for testing
  for(int i=0; i<size; i++){
    double number = bubbleArr[i];
    cout<<number<<endl;
  }
}
void Sorting::selectionSort(double arr[]){
  int min;
  int i;
  int k;
  double temp;
  auto start = high_resolution_clock::now();
  for(i=0;i<size-1;i++){
    min=i;
    for(k=i+1;k<size;k++){
      if(arr[k]<arr[min]){
        min=k;
      }
    }
    if(min!=i){
      temp = arr[i];
      arr[i]=arr[min];
      arr[min]= temp;
    }
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  selectTime = duration.count()/0.000001;
}

void Sorting::mergeSort(double arr[], int left, int right){
  if(left<right){
    int middle = left + (right-left)/2;
    mergeSort(arr,left,middle);
    mergeSort(arr, middle+1,right);
    merge(arr,left,middle,right);
  }
}
void Sorting::quickSort(double arr[], int start, int end){
    if (start < end){
        int pi = partition(arr, start, end);
        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}
int Sorting::partition(double arr[], int start, int end){
    int pivot = arr[end];
    int i = (start - 1);
    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            double temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    double temp = arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;
    return (i + 1);
}

void Sorting::merge(double arr[],int left, int middle, int right){
  int i1 = middle - left + 1;
  int i2 = right-middle;
  int i, k, j;

  double leftT[i1];
  double rightT[i2];

  for(i=0;i<i1;i++){
    leftT[i]=arr[left+i];
  }
  for(k=0;k<i2;k++){
    rightT[k]= arr[middle+1+k];
  }
  i=0;
  k=0;
  j=left;

  while(i<i1 && k<i2){
    if(leftT[i]<=rightT[k]){
      arr[j]=leftT[i];
      i++;
    }
    else{
      arr[j]=rightT[k];
      k++;
    }
    j++;
  }
  while(i<i1){
    arr[j]=leftT[i];
    i++;
    j++;
  }
}
void Sorting::writeFiles(){
  ofstream bubbleOut;
  ofstream insertOut;
  ofstream selectOut;
  ofstream mergeOut;
  ofstream quickOut;
  bubbleOut.open("BubbleSort.txt");
  insertOut.open("InsertSort.txt");
  selectOut.open("SelectSort.txt");
  mergeOut.open("MergeSort.txt");
  quickOut.open("QuickSort.txt");
  bubbleOut<<"Time in seconds: "<<bubbleTime<<endl;
  insertOut<<"Time in seconds: "<<insertTime<<endl;
  selectOut<<"Time in seconds: "<<selectTime<<endl;
  mergeOut<<"Time in seconds: "<<mergeTime<<endl;
  quickOut<<"Time in seconds: "<<quickTime<<endl;
  for(int i=0;i<size;i++){
    bubbleOut<<bubbleArr[i]<<endl;
    insertOut<<insertArr[i]<<endl;
    selectOut<<selectArr[i]<<endl;
    mergeOut<<mergeArr[i]<<endl;
    quickOut<<quickArr[i]<<endl;
  }
  bubbleOut.close();
  insertOut.close();
  selectOut.close();
  mergeOut.close();
  quickOut.close();

}
void Sorting::sort(){
  makeArrays();
  insertionSort(insertArr);
  bubbleSort(bubbleArr);
  selectionSort(selectArr);
  auto start = high_resolution_clock::now();
  mergeSort(mergeArr,0,size-1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  mergeTime = duration.count()/0.000001;
  auto s = high_resolution_clock::now();
  quickSort(quickArr,0,size-1);
  auto st = high_resolution_clock::now();
  auto d = duration_cast<microseconds>(st - s);
  quickTime = d.count()/0.000001;
  writeFiles();
}
