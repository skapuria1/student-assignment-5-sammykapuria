#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {

  // TODO: Begin your code here. Feel free to add any helper functions or classes you need,
  // as long as we only have to call this function to run the specified assignment.
  string FILENAME = argv[1]; // filename is argv[1] string 
  ifstream FILE(FILENAME);
  if(!FILE) { // if file is bad abort 
    cout<<"BAD FILE!";
    return 0;
  }
    
  int num_vertices;
  FILE>>num_vertices; // read num of vertices 
    
  Graph G(num_vertices); // create a graph with a constructor of num_vertices

  FILE.ignore(1000,'\n');    // ignore \n because we will be reading strings 

  while(!FILE.eof()) { // loop as long as file is not at the end 
    string help;    // new string 
    getline(FILE,help); // read a line 
     
    vector<string> V; // create a vector of strings 
    for(int i=0;i<help.length();i++) { // go through a vector 
         
        string s;
        while(help[i] != ' ' && i < help.length()) { // as long as it is not whitespace or end 
             
            s.push_back(help[i]); // add it to a string 
             
             
            i++;
        }
         
        V.push_back(s); // string in the end is a number as a string so we push it back to V 

    }

        int num = stoi(V[0]); // convert first number from a string to int 
       
        for(int i=1;i<V.size();i++) { // go from 1 to the end of vector of strings 
             
            int vert1 = stoi(V[i]); // convert incoming number from a string to number 
            i++;
            double weight1 = stod(V[i]); //convert weight to a double 
            Edge E(vert1,weight1); // create edge 
             
          G.insert(num,E); // insert to a graph 
             
                 // insert it together with the vertex
             
        }
        
  }
    
    
  FILE.close();
  string FILENAME2 = argv[2]; // a new file 
  ifstream FILE2(FILENAME2); // read a file2 

  if(!FILE2) {
      cout<<"COULD NOT OPEN FILE2";
      return 0;
  }
    
  while(!FILE2.eof()) {
        
        int num1;
        int num2;
        FILE2>>num1;// read two numbers from adjacency queries 
        FILE2>>num2;
        
        if(G.connected(num1,num2) == -1) { // if we get -1 result it is not connected 
            
            cout<<num1<<" "<<num2<<": "<<"not_connected"<<endl;
            
        }
        else {
            
            cout<<num1<<" "<<num2<<": "<<"connected "<<G.connected(num1,num2)<<endl; // otherwise we print it 
        }
        
        
    }
        
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}