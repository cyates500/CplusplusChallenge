// Q96 FizzBuzz Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <thread>

#include <mutex>


std::mutex mutex;
//using 
void handler1 ( const boost::system::error_code &ec )
{
  
  std::thread::id thread_id = std::this_thread::get_id();
  std::lock_guard<std::mutex> guard ( mutex );
  std::cout << thread_id << std::endl;
  std::cout << "5 s." << std::endl;
}

void handler2 ( const boost::system::error_code &ec )
{
  std::thread::id thread_id = std::this_thread::get_id ();
  std::lock_guard<std::mutex> guard ( mutex );
  std::cout << thread_id << std::endl;
  std::cout << "10 s." << std::endl;
}

boost::asio::io_service io_service1;
//boost::asio::io_service io_service2;

void run1()
{
  io_service1.run();
}

//void run2 ()
//{
//  io_service2.run();
//}

int main()
{
  boost::asio ::deadline_timer timer1 ( io_service1,
                                        boost::posix_time::seconds ( 5 ) );
  timer1.async_wait ( handler1 );
  boost::asio::deadline_timer timer2 ( io_service1,
                                       boost::posix_time::seconds ( 10 ) );
  timer2.async_wait ( handler2 );

  boost::asio::deadline_timer timer3 ( io_service1,
                                       boost::posix_time::seconds ( 5 ) );
  timer3.async_wait ( handler1 );

  boost::asio::deadline_timer timer4 ( io_service1,
                                       boost::posix_time::seconds ( 5 ) );
  timer4.async_wait ( handler1 );

  std::thread thread1( run1 );
  std::thread thread2( run1 );
  //boost::thread thread1 ( run1 );
  //boost::thread thread2 ( run2 );
  thread1.join();
  thread2.join();
}

