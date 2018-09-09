#include "Node.h"
#include <iostream>

using namespace Nodes;

Node::Node( char id ): m_id( id ){}

void 
Node::output_id ()
{
  std::cout << m_id << std::endl;
}

char
Node::get_id ()
{
  return m_id;
}

//void 
//Node::connect_nodes_together ( int distance, char node_id )
//{
//  Connection connection( distance, node_id );
//  m_connections.push_back ( connection );
//  node_ptr->connect_node( distance, m_id );
//}

void 
Node::connect_node ( int distance, char node_id )
{
  Connection connection ( distance, node_id );
  m_connections.push_back ( connection );
}

void
Node::output_connections()
{
  for ( auto& connection : m_connections )
  {
    std::cout << m_id << " -> ";
    connection.output_connection();
  }
}

std::vector< char >
Node::get_connection_ids()
{
  std::vector< char > connections;
  for ( auto& connection : m_connections )
  {
    connections.push_back( connection.get_node_id() );
  }
}



Connection::Connection( int distance, char node_id ) 
  : m_distance( distance ), m_node_id( node_id ){}

void 
Connection::output_connection ()
{
  std::cout << m_node_id << std::endl;
}

char
Connection::get_node_id()
{
  return m_node_id;
}

int
Connection::operator+ ( const Connection& connection)
{
  return m_distance + connection.m_distance;
}