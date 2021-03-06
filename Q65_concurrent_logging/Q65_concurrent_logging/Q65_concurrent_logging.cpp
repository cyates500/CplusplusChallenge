// Q65_concurrent_logging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Print_Mgr
{
public:
  static Print_Mgr& get_singleton()
  {
    // Why is this thread safe?
    // pre c++11 it is not.  Now language ensure static initialisation is thread safe.
    static Print_Mgr singleton;
    // Print_Mgr singleton; // BOOM
    return singleton;
  }
  ~Print_Mgr()
  {
    std::cout << "~Print_Mgr()" << std::endl;

  }
  template< typename T >
  void print( T t )
  {
    std::thread::id thread_id = std::this_thread::get_id();
    std::lock_guard<std::mutex> guard ( mutex );
    std::cout << "printed value: " << t << ",    in thread: " << thread_id << std::endl;
  }

  void int_print()
  {
  }

private:
  Print_Mgr(){};
  std::mutex mutex;
};

//int&
//func_ret_rref() { static int val = 3; return val; }

int main()
{
  /*int val = 3;
  int& rval = val;

  int val2 = 4;
  rval = func_ret_rref();*/
  Print_Mgr& printer = Print_Mgr::get_singleton();
  
  //Print_Mgr printer();
  // reason why thread takes method first for a member function
  // Member functions all take a 'this' pointer as their first parameter
  // It is implicit and hidden usually.  In this case for thread we 
  // need to be explicit.  We need address to object hence &printer.
  // In this case it is clearer with a lambda
  std::thread thread1( &Print_Mgr::int_print, &printer );
  std::thread thread2( [&printer](){ printer.print( "hello world" ); } );
  std::thread thread3( [&printer](){ printer.print ( 4 ); } );
  thread1.join();
  thread2.join();
  thread3.join();
  return 0;
}

