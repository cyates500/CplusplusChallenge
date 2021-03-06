// Q96 FizzBuzz Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <boost/array.hpp>

boost::asio::io_service io_service;
boost::asio::ip::tcp::endpoint endpoint ( boost::asio::ip::tcp::v4(), 50000 );
boost::asio::ip::tcp::acceptor acceptor ( io_service, endpoint );
boost::asio::ip::tcp::socket sock ( io_service );
boost::array<char, 4096> buffer;

//std::string data = 
//   "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, world!";

std::string fizzbuzz_alg ( std::string in )
{
  int n = std::stoi( in );
  std::string out = "";

  if( n % 3 == 0 )
  {
    out += "Fizz";
  }

  if( n % 5 == 0 )
  {
    out += "Buzz";
  }
  else if( !( n % 3 == 0 ) )
  {
    out = std::to_string( n );
  }
  return out;
}

void write_handler ( const boost::system::error_code & ec,
                     std::size_t bytes_transferred )
{
}

void read_handler ( const boost::system::error_code & ec,
                    std::size_t bytes_transferred )
{
  if (!ec)
  {
    std::string input ( buffer.data (), bytes_transferred );
    std::cout << fizzbuzz_alg ( input ) << std::endl;
    sock.async_read_some ( boost::asio::buffer ( buffer ), read_handler );
  }
}

void accept_handler ( const boost::system::error_code &ec )
{
  if ( !ec )
  {
    sock.async_read_some( boost::asio::buffer ( buffer ), read_handler );
    //boost::asio::async_read ( sock, boost::asio::buffer ( buffer ), read_handler );
  }
  else
  {
    std::cout << "not connected" << std::endl;
  }
}

int main()
{
  acceptor.listen();
  acceptor.async_accept ( sock, accept_handler );
  io_service.run();
}