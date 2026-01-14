#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class CSVLoader
{
public:
    CSVLoader(){}
    ~CSVLoader() = default;

    void load();

private:
   std::string buffer;
   std::string conmaBuffer;
   std::string inputFile = "./Dijkstra_Map.csv";

};