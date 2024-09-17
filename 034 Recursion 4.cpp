#include <iostream>
using namespace std;

// 1st approach of reversing the strings with recursion
void revRec(string &s, int i, int j) {

  // base case :
  if (i > j) {
    return;
  }

  // swapping first two characters
  swap(s[i], s[j]);

  // recursive call
  i++;
  j--;
  revRec(s, i, j);
}

// 2nd approach of reversing the strings with recursion
void revRec2(string &s, int i) {

  if (s[i] != '\0') {
    i++;
    revRec2(s, i);
    i--;
    cout << s[i];
  } else {
    return;
  }
}

// Palindrome checker with recursion
bool checkPalindrome(string &s, int i, int j) {

  // base case :
  if (i > j) {
    return true;
  }

  // checking first two characters
  if (s[i] != s[j]) {
    return false;
  }

  // recursive call
  return checkPalindrome(s, i + 1, j - 1);
}

// a to the power of b i.e, a^b using recursion
int power(int a, int b) {

  // base cases :
  if (b == 0) {
    return 1;
  }

  if (b == 1) {
    return a;
  }

  // recursive call
  if (b % 2 == 0) {
    return (power(a, b / 2) * power(a, b / 2));
  }

  else {
    return (a * power(a, b / 2) * power(a, b / 2));
  }
}

// Bubble sort using recursi0n
void bubbleSort(int *arr, int n) {

  // base case :
  if (n == 0 || n == 1)
    return;

  // solve the first pair of elements
  for (int i = 0; i < n-1; i++) {
    if (arr[i] > arr[i + 1]) {
      swap(arr[i], arr[i + 1]);
    }
  }

  //recursive call
  bubbleSort(arr , n-1 );
}



int main() {

  // reversing the strings with recursi0n
  string a = "abcde";
  revRec(a, 0, a.length() - 1);
  cout << "reversed string is : " << a << endl;
  // again reversing it with the 2nd approach of recursi0n
  cout << "again reversed it with 2nd approach is : ";
  revRec2(a, 0);
  cout << endl;
  cout<< endl;

  // Palindrome checker with recursion
  a = "malayalam";
  string b = "mallu";
  cout << " string a is palindrome : " << checkPalindrome(a, 0, a.length() - 1)
       << endl;
  cout << " string b is palindrome : " << checkPalindrome(b, 0, b.length())
       << endl;
cout<< endl;

  // a to the power of b i.e, a^b using recursion
  int c = 2, d = 10, e = 11;
  cout << c << " to the power " << d << " is : " << power(c, d) << endl;
  cout << c << " to the power " << e << " is : " << power(c, e) << endl;
cout<< endl;

  // Bubble sort using recursi0n
  int arr[10] = {0, 1, 8, 5, 4, 6, 7, 9, 2, 3};
   cout<< "original array is : ";
  for (int i=0; i<10; i++) {
  cout<< arr[i];
  }
  cout<<endl;
  bubbleSort(arr, 10);
  cout<< "sorted array is : ";
  for (int i=0; i<10; i++) {
  cout<< arr[i];
  }
  cout<< endl;


  return 0;
}