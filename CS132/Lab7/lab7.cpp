// InsertionSort.cpp
// https://www.youtube.com/watch?v=8oJS1BMKE64

#include <iostream>

void insertionSort(int arr[], int size) {
    int i, j, key;
    // iterate through the array, starting at position 1
    for (i = 1; i < size; i++) {
        // key is the current item, we need to determine if it should move
        key = arr[i];

        // j is the previous index and will allow us to shift items forward
        j = i - 1;

        // Shift everything from arr[0..i-1] that is greater than the key
        // No if's req'd as this guarantees everything ahead is already sorted

        //### UPDATE FOR REVERSE ###//
        // Check if the previous element is less than the current one, instead
        // of greater than. This means that if element j is less than i (which
        // is what we don't want), it will swap the elements.
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    int numbers[] = { 9, 0, 5, 3, 8, 1, 4, 6, 7, 10, 2 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    insertionSort(numbers, size);
    print(numbers, size);

    return 0;
}