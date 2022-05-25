#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH


// TODO: This file is for your graph implementation.
// Add everything you need in between the "ifndef and "endif" statements.
// Do not put anything outside those statements

#include <iostream>
#include <list>

using namespace std;

class Edge {
  private:
    int e; // two private attributes 
    double weight;
    
    
  public:
  
    Edge(int e1, double w1) { // regular constructor 
        this->e = e1;
        this->weight = w1;
    }
    Edge() {
        this->e = 0; // default constructor setting up values to 0 
        this->weight = 0.0;
    }
    
    
    Edge(const Edge& Edg) { // copy constructor 
        
        this->e = Edg.e;
        this->weight = Edg.weight;
        
    }
    
        Edge& operator=(const Edge& Edg) { // assignment operator 
            
         if(this!= &Edg) {
              this->e = Edg.e;
        this->weight = Edg.weight;
         }
         
         return *this;
            
        }

    
    int get_e() { // getter function to get int 
        return e;
    }
    
    double get_w() { //getter function to get double 
        return weight;
    }

};

class Graph {
  
  private:
  
  int number_of_vertices;
  // private attributes number_of_vertices and vector of vectors that contain edges 
  vector<vector<Edge>> vertex;
  
  
    public:
    Graph(int n_vertices) {
      
      this->number_of_vertices = n_vertices;
      this->vertex.resize(n_vertices+1); // regular constructor that sets up private attributes  
    }
  
    void insert(int V, Edge E) {
       vertex[V].push_back(E); // we push back edge to a vector with a given VERTEXF 
    }
    
    double connected(int vertex1, int vertex2) {
        // we check here whether two of the vertex are connected 
        for(int i=0;i<vertex[vertex1].size();i++) {

            if(vertex[vertex1][i].get_e() == vertex2) { // if we found it is equal to vertex2 then it is connected 
                return vertex[vertex1][i].get_w(); // return weight  
            }
          
        }
      
        return -1; // otherwise return -1 
      
    } 
    
};

#endif