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
    int e;
    double weight;
    
    
  public:
  
    Edge(int e1, double w1) {
        this->e = e1;
        this->weight = w1;
    }
    Edge() {
        this->e = 0;
        this->weight = 0.0;
    }
    
    
    Edge(const Edge& Edg) {
        
        this->e = Edg.e;
        this->weight = Edg.weight;
        
    }
    
        Edge& operator=(const Edge& Edg) {
            
         if(this!= &Edg) {
              this->e = Edg.e;
        this->weight = Edg.weight;
         }
         
         return *this;
            
        }

    
    int get_e() {
        return e;
    }
    
    double get_w() {
        return weight;
    }
    
   
};

class Graph {
  
  private:
  
  int number_of_vertices;
  
  vector<vector<Edge>> vertex;
  
  
  
  public:
    
  
  Graph(int n_vertices) {
      
      this->number_of_vertices = n_vertices;
      this->vertex.resize(n_vertices+1);
      
      
  }
  
  void insert(int V, Edge E) {
       vertex[V].push_back(E);
  }
    
  double connected(int vertex1, int vertex2) {
      
      for(int i=0;i<vertex[vertex1].size();i++) { 
          
          if(vertex[vertex1][i].get_e() == vertex2) { 
            return vertex[vertex1][i].get_w();
              
          }
      }
      
      return -1;  
  } 
};

#endif