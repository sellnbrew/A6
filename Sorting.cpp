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
          for(int i=0;i<size;i++){
            getline(file,line);
            double number = stod(line);//checked working
            bubbleArr[i]=number;//Segmentation fault here ??? why idk
            insertArr[i]=number;
            selectArr[i]=number;
            mergeArr[i]=number;
          }
          file.close();
      }
      catch(std::ifstream::failure e){
        std::cerr << "Exception opening/reading/closing file\n";
      }
}

void Sorting::printArray(){
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

}
void Sorting::mergeSort(){

}
void Sorting::merge(){

}
void Sorting::writeFiles(){
  ofstream bubbleOut;
  ofstream insertOut;
  ofstream selectOut;
  ofstream mergeOut;
  bubbleOut.open("BubbleSort.txt");
  insertOut.open("InsertSort.txt");
  selectOut.open("SelectSort.txt");
  mergeOut.open("MergeSort.txt");
  bubbleOut<<"Time in seconds: "<<bubbleTime<<endl;
  insertOut<<"Time in seconds: "<<insertTime<<endl;
  selectOut<<"Time in seconds: "<<selectTime<<endl;
  mergeOut<<"Time in seconds: "<<mergeTime<<endl;
  for(int i=0;i<size;i++){
    bubbleOut<<bubbleArr[i]<<endl;
    insertOut<<insertArr[i]<<endl;
    selectOut<<selectArr[i]<<endl;
    mergeOut<<mergeArr[i]<<endl;
  }
  bubbleOut.close();
  insertOut.close();
  selectOut.close();
  mergeOut.close();

}
