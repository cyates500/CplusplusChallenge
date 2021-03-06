// Q58_Shortest_Distance_Nodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Node.h"
#include <vector>
#include <map>

std::vector<Nodes::Node> 
create_node_structure ()
{
  Nodes::Node A('A');
  Nodes::Node B('B');
  Nodes::Node C('C');
  Nodes::Node D('D');
  Nodes::Node E('E');
  Nodes::Node F('F');
  A.connect_node( 7,  'B' );
  A.connect_node( 9,  'C' );
  A.connect_node( 14, 'F' );
  B.connect_node( 7,  'A' );
  B.connect_node( 10, 'C' );
  B.connect_node( 15, 'D' );
  C.connect_node( 9,  'A' );
  C.connect_node( 2,  'F' );
  C.connect_node( 11, 'D' );
  C.connect_node( 10, 'B' );
  D.connect_node( 6,  'E' );
  D.connect_node( 11, 'C' );
  D.connect_node( 15, 'B' );
  E.connect_node( 6,  'D' );
  E.connect_node( 9,  'F' );
  F.connect_node( 9,  'E' );
  F.connect_node( 2,  'C' );
  F.connect_node( 14, 'A' );
  std::vector<Nodes::Node> node_structure;
  node_structure.push_back ( A );
  node_structure.push_back ( B );
  node_structure.push_back ( C );
  node_structure.push_back ( D );
  node_structure.push_back ( E );
  node_structure.push_back ( F );
  return node_structure;
}

std::map<char, Nodes::Node> 
create_node_map_structure ()
{
  Nodes::Node A('A');
  Nodes::Node B('B');
  Nodes::Node C('C');
  Nodes::Node D('D');
  Nodes::Node E('E');
  Nodes::Node F('F');
  A.connect_node( 7,  'B' );
  A.connect_node( 9,  'C' );
  A.connect_node( 14, 'F' );
  B.connect_node( 7,  'A' );
  B.connect_node( 10, 'C' );
  B.connect_node( 15, 'D' );
  C.connect_node( 9,  'A' );
  C.connect_node( 2,  'F' );
  C.connect_node( 11, 'D' );
  C.connect_node( 10, 'B' );
  D.connect_node( 6,  'E' );
  D.connect_node( 11, 'C' );
  D.connect_node( 15, 'B' );
  E.connect_node( 6,  'D' );
  E.connect_node( 9,  'F' );
  F.connect_node( 9,  'E' );
  F.connect_node( 2,  'C' );
  F.connect_node( 14, 'A' );
  std::map<char,Nodes::Node> node_structure;
  node_structure.insert( std::make_pair( A.get_id(), A ) );
  node_structure.insert( std::make_pair( B.get_id(), B ) );
  node_structure.insert( std::make_pair( C.get_id(), C ) );
  node_structure.insert( std::make_pair( D.get_id(), D ) );
  node_structure.insert( std::make_pair( E.get_id(), E ) );
  node_structure.insert( std::make_pair( F.get_id(), F ) );
  return node_structure;
}

using Path = std::vector<char>;

Path find_path ( char start_node_id, char end_node_id, std::map<char, Nodes::Node>& map )
{
  Path path;
  auto starting_node = map.find( start_node_id )->second;
  path.push_back( start_node_id );
  std::vector<char> connecting_ids = starting_node.get_connection_ids();
  //auto end_node = map.find( end_node_id );
}

int main()
{
  std::map<char, Nodes::Node> node_map_structure = create_node_map_structure();
  node_map_structure.find('A')->second.output_connections();
  return 0;
}

