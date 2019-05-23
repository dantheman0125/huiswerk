// array.h

#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int size;
    int *arr;
    int itemsInArray;
public:
    Array(int size);
    ~Array();
    
    void initRandom();
    void initIncrement();

    void addItem(int item); // O(1)
	void quickSort(int low, int high);
    int countOccurences(int value); // O(n)
    void bubbleSort(); // O(n^2)
    int binarySearch(int value); // O(log n)
    void mergesort(); // O(n log n)
};
#endif // ARRAY_H

