/* lab02.cpp
 * modified by: Kanayo Emenike
 * programmer:  santa claus 
 * assignment:  lab02 cs 3500
 * description: instantiates a template class List object; tests all methods; 
 *              incorporates simple try and catch blocks for error handling
 * 
 * note:  rand and time are part of the runtime environment of gnu C++ v.3--
 * no need to include time.h and stdlib.h 
*/ 
#include <fstream>
#include <iostream>
#include "list.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(int argc, char *argv[], char *env[]) {

  if (argc < 2) {
     cout << "Usage: ./lab02 <list_size>\n";
     exit(-1);
  }

  /* if the number entered from cmdline is > 10 it will induce range errors since MAX =10 */
  int size = atoi(argv[1]);

  cout << "\nSanta Claus Lab02 Size: " << size << endl;
  cout << "=============================" << endl;
  int sz;
  /* seed the random number generator */
  srand(time(NULL));

  // create 3 lists
  List<int> iList;
  List<double> fList;

  // fill the lists with random numbers - size is read from cmdline  
  for (int i = 0; i < size; i++) {
    iList.add(rand() % 51 + 1); 
    fList.add((rand() % 51 + 7)/3.0); 
  }  

  /* sort and display lists */  
  sz = iList.getSize();
  iList.sort();
  cout << "Sorted integer List of size " << sz << endl;
  iList.print(sz); 
  cout << "Sorted float List of size " << sz << endl;
  fList.sort();
  fList.print(sz); 

  // this will trigger an exception from C++ stdexcept if size > 10
  cout << "Swap first and last elements in fList" << endl;
  fList.swap(0,(size-1)); /* swap element 0 with element size-1 */  
  cout << fList;

  // this will trigger a Range Error exception if size > 10
  cout << "The element at pos " << fList.max(0,(size-1)) << 
  " is larger than the element at pos " << (size-1) << " in fList "<< endl;

  cout << "Testing implicit copy constructor and assignment operator.\n";
  List<double> fList2(fList);
  cout << fList2;
  fList2 = fList;
  cout << fList2;

  //Kanayo's Modifications
  ofstream outf("log.txt");
  if (!outf.is_open()) {
    cout << "Log file was not opened.\n";
  } else {
  streambuf *buf = cerr.rdbuf();
  cerr.rdbuf(outf.rdbuf());
  }
 
  try {
    cout << endl << "Testing range error conditions: swap(-1,size-1)\n";
    fList.swap(-1,size-1);
  }  /* end try block */

  /* this catches the above RangeError object  */
  catch (const RangeError &err) {
    cerr << "RangeError caught in swap, file: " << __FILE__ << ", line: " 
    << __LINE__ << endl;
  } 

  /* this generic handler will catch anything */ 
  catch (...) {
     cerr << "Generic handler caught exception in file: " << __FILE__ << 
     " lineno: " << __LINE__ << endl;
  }

  cout << "Testing code after catch, file "<< __FILE__ <<  ", line "<< __LINE__ 
  << endl;
  
  return 0;
}
