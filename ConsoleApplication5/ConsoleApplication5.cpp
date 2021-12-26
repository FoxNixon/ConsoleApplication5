// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printArray1(double* arr, int size);
void printArray1(int* arr, int size);
void invertArray2(unsigned int* array, unsigned int arraySize);
void fillArray3(int* array, unsigned int arraySize);
void shiftArray(int* array, unsigned int arraySize, int shift);
bool checkBalance(int* array, int arraySize, bool & returnValue);

const unsigned int ARR_SIZE = 10;

int main()
{
    //task1
    const unsigned int ARR_SIZE = 10;
    int someSimpleNumber = 17;
    double array1[ARR_SIZE] = { 0 };
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        array1[i] = (double)(rand() % 100) / someSimpleNumber;
    }
    printArray1(array1, ARR_SIZE);
    cout << endl;

    //Task2
    unsigned int array2[ARR_SIZE] = { 0 };
    cout << "Array2 before changes: ";
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
        array2[i] = rand() % 2;
        cout << array2[i] << " ";
    }
    cout << endl;

    invertArray2(array2, ARR_SIZE);

    cout << "Array2 after changes: ";
    for (size_t i = 0; i < ARR_SIZE; i++)
    {
       cout << array2[i] << " ";
    }
    
    cout << endl << endl;

    //Task3
    const int ARR3_SIZE = 8;
    int array3[ARR3_SIZE] = { 0 };
    fillArray3(array3, ARR3_SIZE);
    printArray1(array3, ARR3_SIZE);
    cout << endl;

    //Task4
    int array4[ARR_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int shift = 12;
    printArray1(array4, ARR_SIZE);

    shiftArray(array4, ARR_SIZE, shift);
    cout << endl;

    //Task5
    bool returnVal = 0;
    const int ARR5_SIZE = 5;
    int array5[ARR5_SIZE] = { 1, 2, 3, 5, 11 };
    bool hr = checkBalance(array5, ARR5_SIZE, returnVal);
    cout << "Ballance value : " << returnVal << endl;


    return 0;
}






void printArray1(double* arr, int size) {

    cout << "Array1: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray1(int* arr, int size) {

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void invertArray2(unsigned int* array, unsigned int arraySize) {
    for (size_t i = 0; i < arraySize; i++)
    {
        array[i] > 0 ? array[i] = 0 : array[i] = 1;
    }
}

void fillArray3(int* array, unsigned int arraySize) {
    
    for (size_t i = 0; i < arraySize; i++)
    {
        if (i == 0) {
            array[i] = 1;
        }
        else {
            array[i] = array[i - 1] + 3;
        }
    }
}

void shiftArray(int * array, unsigned int arraySize, int shift) {
        
    if (shift > (int)arraySize) {
        shift = shift % arraySize;
    }
    else if (shift < 0 && shift < -((int)arraySize)) {
        shift = shift % -((int)arraySize);
    }

    int tempArray[ARR_SIZE] = {};

           
        if (shift >= 0) {
            for (size_t i = 0; i < arraySize; i++) { 
                tempArray[i] = array[(i + shift) % arraySize];
                    
            }
        }
        else {
            for (size_t i = 0; i < arraySize; i++) {           
                tempArray[i] = array[(arraySize + i + shift) % arraySize];
                    
            }
        }

    printArray1(tempArray, arraySize);  // не до конца разобрался как правильно переписать исходный массив через поинтер, поэтому принт из функции... 
  
}

bool checkBalance(int * array, int arraySize,bool & returnValue){
    int summLeft{0}, summRight{0};

    for (size_t i = 0; i < arraySize-1; i++)
    {
        summLeft += array[i];
        summRight = 0;
        for (size_t j = i+1; j < arraySize; j++)
        {
            summRight += array[j];
        }
        if (summLeft == summRight) {
            returnValue = true;
            break;
        }

    }
    return returnValue;
}