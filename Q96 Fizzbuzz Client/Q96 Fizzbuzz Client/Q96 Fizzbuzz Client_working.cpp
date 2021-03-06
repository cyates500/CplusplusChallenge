// Q96 Fizzbuzz Client.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <chrono>
#include <thread>

boost::asio::io_service io_service;
boost::asio::ip::tcp::resolver resolver( io_service );
boost::asio::ip::tcp::socket sock( io_service );
boost::array<char, 4096> buffer;

void read_handler ( const boost::system::error_code &ec,
                    std::size_t bytes_transferred )
{
  if (!ec)
  {
    std::cout << std::string ( buffer.data (), bytes_transferred ) << std::endl;
    // don't you need to cin here, then write, then read repeatedly
    std::string input;
    std::cout << "Please enter an integer value to be FizzBuzzed: ";
    std::cin >> input;
    std::cout << std::endl << "The FizzBuzzed value is: " << std::endl;
    boost::asio::write ( sock, boost::asio::buffer ( input ) );
    sock.async_read_some ( boost::asio::buffer ( buffer ), read_handler );
  }
}

//not used atm
void write_handler ( const boost::system::error_code &ec,
                     std::size_t bytes_transferred )
{
  std::cout << "writing " << bytes_transferred << std::endl;
  std::this_thread::sleep_for ( std::chrono::milliseconds(5000) );
}


void connect_handler ( const boost::system::error_code &ec )
{
  if (!ec)
  {
    //boost::asio::async_write ( sock, boost::asio::buffer (
    //  "1" ), write_handler );
    
    //auto sz = boost::asio::write( sock, boost::asio::buffer( "1" ) );
    
    sock.async_read_some( boost::asio::buffer ( buffer ), read_handler );
  }
}

void resolve_handler ( const boost::system::error_code &ec,
                       boost::asio::ip::tcp::resolver::iterator it )
{
  if (!ec)
  {
    sock.async_connect ( *it, connect_handler );
  }
}

int main ()
{
  boost::asio::ip::tcp::resolver::query query ( "127.0.0.1", "50000" );
  resolver.async_resolve ( query, resolve_handler );
  io_service.run ();
}


