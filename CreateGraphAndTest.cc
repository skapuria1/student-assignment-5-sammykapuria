#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {

    // TODO: Begin your code here. Feel free to add any helper functions or classes you need,
    // as long as we only have to call this function to run the specified assignment.
    string FILENAME = argv[1];
    ifstream FILE(FILENAME);
    if(!FILE) {
        cout<<"BAD FILE!";
        return 0;
    }
    
    int num_vertices;
    FILE>>num_vertices;
    
    Graph G(num_vertices);


  
         FILE.ignore(1000,'\n');   

    while(!FILE.eof()) {
          string help;    
     getline(FILE,help);
     
     vector<string> V;
     for(int i=0;i<help.length();i++) {
         
         string s;
         while(help[i] != ' ' && i < help.length()) {
             
             s.push_back(help[i]);
             
             
             i++;
         }
         
         V.push_back(s);

     }

         int num = stoi(V[0]);
       
         for(int i=1;i<V.size();i++) {
             
             int vert1 = stoi(V[i]);
             i++;
             double weight1 = stod(V[i]);
             Edge E(vert1,weight1);
           G.insert(num,E);
             
                 // insert it together with the vertex
             
         }
        
    }
    
    
    FILE.close();
    string FILENAME2 = argv[2];
    ifstream FILE2(FILENAME2);

    if(!FILE2) {
        cout<<"COULD NOT OPEN FILE2";
        return 0;
    }
    
    while(!FILE2.eof()) {
        
        int num1;
        int num2;
        FILE2>>num1;
        FILE2>>num2;
        
        if(G.connected(num1,num2) == -1) {
            
            cout<<num1<<" "<<num2<<": "<<"not_connected"<<endl;
            
        }
        else {
            
            cout<<num1<<" "<<num2<<": "<<"connected "<<G.connected(num1,num2)<<endl;
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