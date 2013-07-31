// Trying using bundled properties

#include<iostream>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/properties.hpp>
#include<string>
#include<fstream>
#include<utility>

using namespace std;
using namespace boost;

// Information we want to attach to Vertices

struct Vertex{

   string name;
};

// Information we want to attach to Edges

struct Edge{

   string name;
};

// Declare set of vertices, name of vertices and edges

   enum set_vertices {ProNachiket,Nick,Lam,numof_vertices};

   const char* nameof_vert[]  = {"Prof Nachiket","Lam","Son"};

   const char* nameof_edge[]  = {"Supervisor","Supervisor","Friend"};

int main(int,char*[]){

// Declare set of edges

   typedef pair<int,int> set_edges;
   
   set_edges edex_edges[] = {set_edges(0,1),set_edges(0,2),
                        set_edges(1,2)};
   

   const int numof_edges  = sizeof(edex_edges)/sizeof(set_edges);

// Configure graph

  typedef adjacency_list<vecS,vecS,undirectedS,Vertex,Edge> Graph;

  Graph Edexteam(edex_edges,edex_edges + numof_edges,numof_vertices);
  

// Print graph into dot file
  
  ofstream MyGraph;
  MyGraph.open("bundledproperties.dot");

  /* Make your own properties writer(Here I am using built-in function "make_label_writer"). 
     
     For more information, please visit: 
    
               http://nachiket@yarvard.sce.ntu.edu.sg:7990/scm/es7501/labs.git */

  // Access all vertices of our graph

  typedef graph_traits<Graph>::vertex_iterator vertex_iter;
  std::pair<vertex_iter, vertex_iter> vp;
  int index_vert = -1;
  for (vp = vertices(Edexteam); vp.first != vp.second; ++vp.first){
      ++index_vert; 
      
      // Add information to each vertex we pass through

      Edexteam[*vp.first].name = nameof_vert[index_vert];
  }
  graph_traits<Graph>::edge_iterator ei, ei_end;
  long int index_for_name_of_edge = -1;  /* Used to subscript name array of edges declared 
                                            at the beginning fo program */
  
  // Access all edges of our graph

  for (tie(ei, ei_end) = edges(Edexteam); ei != ei_end; ++ei){
      ++index_for_name_of_edge;

      // Add information to each edge we pass through

      Edexteam[*ei].name = nameof_edge[index_for_name_of_edge];
  } 
  // Print out Graph into dot file
  write_graphviz(MyGraph,Edexteam, 
                 make_label_writer(get(&Vertex::name,Edexteam)),  // Write information added to vertices
                 make_label_writer(get(&Edge::name,Edexteam)));   // Write information added to edges
  MyGraph.close();
  return 0;
}        
