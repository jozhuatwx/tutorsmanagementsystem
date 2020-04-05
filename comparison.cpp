#include <chrono>
#include <iostream>
#include "tutor.h"
using namespace std;

// function headers
Tutor *copyArray(Tutor arr[], int n);
void testSort(int e);

void insertionSort(Tutor arr[], int n, Tutor in);

int stableBinarySearch(Tutor arr[], int low, int up, Tutor key);
void binaryInsertionSort(Tutor arr[], int n, Tutor in);

void swap(Tutor *a, Tutor *b);
int dualPivotPartition(Tutor arr[], int low, int up, int *lp);
void dualPivotQuicksort(Tutor arr[], int low, int up, Tutor in);

int main() {
  int r, e, t;
  cout << "repeat: ";
  cin >> r;
  while (r--) {
    cout << "elements: ";
    cin >> t;
    testSort(e);
  }
  return 0;
}

Tutor *copyArray(Tutor arr[], int n) {
  Tutor *a = new Tutor[n];
  for (int i = 0; i < n; i++)
    a[i] = arr[i];
  return a;
}

void testSort(int e) {
  chrono::duration<float> isTime, bisTime, dpqsTime;
  int n = 1000;

  // dummy data
  srand(time(0));
  string names[] {"Aaron", "Ava", "Ben", "Brooklyn", "Charlotte", "Connor", "Daniel", "Delilah", "Ethan", "Emily", "Francisco", "Freya", "Gabriel", "Gracie", "Harry", "Hunter", "Isaac", "Isabelle", "Jack", "Julia", "Katie", "Kevin", "Leo", "Lillian", "Max", "Mia", "Natalie", "Noah", "Ollie", "Owen", "Parker", "Phoebe", "Qasim", "Quinn", "Rebecca", "Riley", "Samuel", "Sophia", "Thomas", "Tyler", "Una", "Uriel", "Vincent", "Victoria", "Willow", "Xander", "Ximena", "Yahir", "Yakub", "Zachary", "Zoe"};
  Tutor *tutors = new Tutor[n];
  for (int i = 0; i < n/20; i+=20)
    for (int x = 0; x < 20; x++)
      tutors[i+x] = Tutor(i+x, names[i], 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);

  Tutor *a = copyArray(tutors, n);
  auto isStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < e; i++) {
    Tutor in(i, names[rand() % 52 + 1], 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
    insertionSort(a, n, in);
  }
  auto isEnd = chrono::high_resolution_clock::now();
  isTime += isEnd - isStart;

  Tutor *b = copyArray(tutors, n);
  auto bisStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < e; i++) {
    Tutor in(i, names[rand() % 52 + 1], 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
    binaryInsertionSort(b, n, in);
  }
  auto bisEnd = chrono::high_resolution_clock::now();
  bisTime += bisEnd - bisStart;

  Tutor *c = copyArray(tutors, n);
  auto dpqsStart = chrono::high_resolution_clock::now();
  for (int i = 0; i < e; i++) {
    Tutor in(i, names[rand() % 52 + 1], 2, 3, 2000, 3, 3, 2000, 50, "0123456789", "Somewhere", "C0004", "Bukit Petaling", "S0001", "Science", 1);
    dualPivotQuicksort(c, 0, n, in);
  }
  auto dpqsEnd = chrono::high_resolution_clock::now();
  dpqsTime += dpqsEnd - dpqsStart;

  printf("\nTime Taken:\n"
          "%-35s %f\n"
          "%-35s %f\n"
          "%-35s %f\n",
          "(1) Insertion Sort: ",
          isTime.count() * 1000,
          "(2) Binary Insertion Sort: ",
          bisTime.count() * 1000,
          "(3) Dual Pivot Quicksort: ",
          dpqsTime.count() * 1000);
};

// algorithms
void insertionSort(Tutor arr[], int n, Tutor in) {
  bool b;
  Tutor *temp = new Tutor[n + 1];
  for (int i = 0; i < n; i++) {
    if (b) {
      int c = compareInsensitive(arr[i].name, in.name);
      if (c <= 0)
        temp[i] = arr[i];
      else {
        temp[i] = in;
        temp[i + 1] = arr[i];
        b = false;
      }
      if (b && i == n - 1)
        temp[i + 1] = in;
    } else {
      temp[i + 1] = arr[i];
    }
  }
};

int stableBinarySearch(Tutor arr[], int low, int up, Tutor key) {
  int mid, size = up + 1;

  while (low <= up) {
    mid = (up - low) / 2 + low;
    int c = compareInsensitive(arr[mid].name, key.name);
    if (c == 0) {
      while (compareInsensitive(arr[mid + 1].name, key.name) == 0)
        mid++;
      break;
    }
    if (c < 0)
      low = mid + 1;
    else
      up = mid - 1;
  };

  int c = compareInsensitive(arr[mid].name, key.name);
  if (c > 0)
    return mid;
  else
    return mid + 1;
};
void binaryInsertionSort(Tutor arr[], int n, Tutor in) {
  Tutor *temp = new Tutor[n + 1];
  int index = stableBinarySearch(arr, 0, n - 1, in);
  int i = 0;
  for (; i < index; i++)
    temp[i] = arr[i];
  temp[index] = in;
  for (; i < n; i++)
    temp[i + 1] = arr[i];
};

void swap(Tutor *a, Tutor *b) {
  Tutor t = *a;
  *a = *b;
  *b = t;
}
int dualPivotPartition(Tutor arr[], int low, int up, int *lp) {
  if (compareInsensitive(arr[low].name, arr[up].name) > 0)
    swap(&arr[low], &arr[up]);
    int j = low + 1;
    int g = up - 1, k = low + 1;
    string p = arr[low].name, q = arr[up].name;
    while (k <= g)
    {
      if (compareInsensitive(arr[k].name, p) < 0)
      {
        swap(&arr[k], &arr[j]);
        j++;
      }
      else if (compareInsensitive(arr[k].name, q) >= 0)  
      {
        while (compareInsensitive(arr[g].name, q) > 0 && k < g)
          g--;
          swap(&arr[k], &arr[g]);
          g--;
          if (compareInsensitive(arr[k].name, p) < 0)
          {
            swap(&arr[k], &arr[j]);
            j++;
          }
      }
      k++;
    }
    j--;
    g++;
    swap(&arr[low], &arr[j]);
    swap(&arr[up], &arr[g]);
    *lp = j;
    return g;
};
void dpqs(Tutor arr[], int low, int up) {
  if (low < up) {
    int lp, rp;
    rp = dualPivotPartition(arr, low, up, &lp);
    dpqs(arr, low, lp - 1);
    dpqs(arr, lp + 1, rp - 1);
    dpqs(arr, rp + 1, up);
  }
}
void dualPivotQuicksort(Tutor arr[], int low, int up, Tutor in) {
  Tutor *newarr = new Tutor[up];
  newarr = copyArray(arr, up);
  dpqs(newarr, low, up);
};