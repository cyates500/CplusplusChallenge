#pragma once

#include <string>
#include <iostream>
#include <vector>


namespace Nodes
{
  class Connection
  {
  public:
    Connection ( int distance, char node_id );
    void output_connection ();
    char get_node_id();
    int operator+( const Connection& connection );
  private:
    int m_distance;
    char m_node_id;
  };

  class Node
  {
  public:
    Node( char id );

    void output_id ();

    char get_id ();
    
    //void connect_nodes_together ( int distance, Node* node );

    void connect_node ( int distance, char node_id );

    void output_connections ();
    
    std::vector<char> get_connection_ids();

  private:
    char m_id;
    std::vector<Connection> m_connections;
  };
}