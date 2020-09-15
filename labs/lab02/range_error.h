/*
  Filename: range_error.h
  Purpose: a RangeError exception class 
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const unsigned FileNameSize = 40;

//out of range subscript exception class
class RangeError {

  friend ostream & operator <<( ostream & os, const RangeError & err )
  { 
    os << "RangeError exception thrown, file: "
       << err.fileName
       << ", lineno: " << err.lineNumber
       << ", index: " << err.value
       << ", function name: " << err.funcName
       << endl;
       return os;
  }

  public:

    RangeError( const char *fn, int line, int subscr, string __func__ )
    {
      strcpy(fileName, fn);
      lineNumber = line;
      value = subscr;
      funcName = __func__;
    }
   
    // a standard method for all range error classes  -- returns error type
    const char * what () const
    {  
       return "RangeError Exception";
    }
    
  private:
    char fileName [FileNameSize + 1];   // __FILE__
    int lineNumber;                     // __LINE__
    int value;                          // the out-of-range index
    string funcName;
};

#endif
