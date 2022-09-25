#include<iostream>
#include<chrono>                   
using namespace std;
using namespace chrono;
const long  Size_Of_Array = 100000;    

// Swap two elements
void swap(long* a, long* b){  
    long t = *a;              
    *a = *b;
    *b = t;
}
int Partition(long Array[], int low ,int high) {   
	int pivot = Array[high];                      
	int NewIndex = low;                          
	for (int i = low; i < Size_Of_Array-1; i++) {  
		if (pivot > Array[i]) {                    
			swap(&Array[i], &Array[NewIndex]);    
			NewIndex++;                           
		}                                        
	}
	swap(&Array[high], &Array[NewIndex]);         
	return NewIndex;                                
}
void QuickSorting(long Array[], int low, int high) {    
	if (low < high) {                                   
		int PivotLocation = Partition(Array, low, high);
		QuickSorting(Array, low, PivotLocation - 1);     
		QuickSorting(Array, PivotLocation + 1, high);
	}
}

void RandomArray(int RangOfRandValues, long randArray[Size_Of_Array]) {
	int i = 0;
	srand(time(0));  // Use _srand(time(0))_ to Shuffle and give different random values in each round 
	for (i = 0; i < Size_Of_Array; i++) {
		randArray[i] = rand() % RangOfRandValues;  //Generate number between 0 to 999
	}
}

int main() {
	long randArray[Size_Of_Array];
    RandomArray(1000, randArray);                            
	/* Quick Sorting */                                                                           
	clock_t start = clock();                                 
	QuickSorting(randArray,0, Size_Of_Array-1);              
	clock_t end = clock();                                   
	double duration = double(end - start)/ CLOCKS_PER_SEC;   
	cout << duration <<" Sec" << endl; 

	/* Bubble Sorting */    //12.056 sec  For Size Of 100,000
	/*clock_t start = clock();
	int pass = 0;
	for (int i = 0; i < Size_Of_Array; i++) {
		for (int j = i + 1; j < Size_Of_Array; j++)
		{
			if (randArray[j] < randArray[i]) {
				swap(&randArray[i], &randArray[j]);
			}
		}
		pass++;
	}

	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	cout << duration << " Sec" << endl;*/

	return 0;
}


