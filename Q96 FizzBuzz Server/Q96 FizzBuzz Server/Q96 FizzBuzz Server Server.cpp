// Q96 FizzBuzz Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <thread>
#include <chrono>


boost::asio::io_service io_service;
boost::asio::ip::tcp::resolver resolver ( io_service );
boost::asio::ip::tcp::socket sock ( io_service );
boost::array<char, 4096> buffer;
std::mutex mutex;

void read_handler( const boost::system::error_code &ec,
                   std::size_t bytes_transferred )
{
  if( !ec )
  {
    std::cout << std::string ( buffer.data(), bytes_transferred ) << std:: endl;
    sock.async_read_some( boost::asio::buffer( buffer ), read_handler );
    std::thread::id thread_id = std::this_thread::get_id ();
    std::lock_guard<std::mutex> guard ( mutex );
    std::cout << "read " << thread_id << std::endl;
  }
}

void connect_handler( const boost::system::error_code &ec )
{
  if( !ec )
  {
    boost::asio::write( sock, boost::asio::buffer (
      R"(GET / HTTP 1.1\r\nHost: www.highscore.de\r\n\r\n)" ) );
    sock.async_read_some( boost::asio::buffer ( buffer ), read_handler );
    std::thread::id thread_id = std::this_thread::get_id ();
    std::lock_guard<std::mutex> guard ( mutex );
    std::cout << "connect " <<thread_id << std::endl;
  }
}

void resolve_handler( const boost::system::error_code &ec,
                      boost::asio::ip::tcp::resolver::iterator it )
{
  if( !ec )
  {
    sock.async_connect( *it, connect_handler );
    std::thread::id thread_id = std::this_thread::get_id ();
    std::lock_guard<std::mutex> guard ( mutex );
    std::cout << "resolve " << thread_id << std::endl;
    //std::this_thread::sleep_for( std::chrono::milliseconds ( 200 ) );
  }
}

void run()
{
  io_service.run();
}

int main()
{
  boost::asio::ip::tcp::resolver::query query( "www.highscore.de", "80" );
  resolver.async_resolve( query, resolve_handler );
  std::thread thread1 ( run );
  std::thread thread2 ( run );
  thread1.join();
  thread2.join();
  //io_service.run();
}