#include<iostream>
#include<boost/graph/graphviz.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/properties.hpp>
#include<utility>
#include<fstream>
using namespace std;
using namespace boost;

// Construct vertices

enum Vert{ProfNachiket,Son,Lam,num_vert};

const char* label_vert[] = {"Prof Nachiket","Son","Lam"};

const char* label_edge[] = {"Supervisor","Supervisor","Friend"};

int main(int,char*[]){
// Construct edges

	typedef pair<int,int> Edges;

	Edges edges_edex[] = {Edges(0,1),Edges(0,2),Edges(1,2)};   

	const int numof_edges = sizeof(edges_edex)/sizeof(Edges);

// Construct our graph

	typedef adjacency_list<vecS,vecS,undirectedS> Graph;

// Instantiate graph

	Graph edexteam(edges_edex,edges_edex + numof_edges,num_vert);

// Now we draw Edex graph into dot file by a tricky way
	ofstream Mygraph;
        Mygraph.open("Edex.dot");
        Mygraph << "graph edex { " << "\n";

        // We print out all vertices into dot file

	typedef property_map<Graph, vertex_index_t>::type Vert_indexMap;
	Vert_indexMap index = get(vertex_index, edexteam);

    	typedef graph_traits<Graph>::vertex_iterator vertex_iter;
    	std::pair<vertex_iter, vertex_iter> vp;
    	for (vp = vertices(edexteam); vp.first != vp.second; ++vp.first){
      		long int a = index[*vp.first]; /* Variable a is for 2 purposes:
						  1. Storing index of vertices
                                                  2. Storing index to subscript name array of vertice */
		Mygraph << a <<  "[label = \" " << label_vert[a] 
                        << "\"];" << "\n";
                }    

        // Now all edges
 

        graph_traits<Graph>::edge_iterator ei, ei_end;
        long int index_for_name_of_edge = -1; /* Used to subscript name array of edges declared 
                                                             at the beginning fo program */
    	for (tie(ei, ei_end) = edges(edexteam); ei != ei_end; ++ei){
                ++index_for_name_of_edge;               
        	Mygraph << index[source(*ei,edexteam)] << " -- " << index[target(*ei,edexteam)]
                        << "[label = \" " << label_edge[index_for_name_of_edge] 
                        << " \" ];"        << "\n";
	}
        Mygraph << "}" ;
        Mygraph << endl;
        
	
	return 0;
} 




