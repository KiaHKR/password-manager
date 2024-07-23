#include <../include/FileManager.hpp>

using namespace std;

FileManager::FileManager(unique_ptr<FILE> file, shared_ptr<unordered_map<string, vector<Credentials>>> services)
{
    file = make_unique<FILE>();
    services = make_shared<unordered_map<string, vector<Credentials>>>();
}

void writeToFile(shared_ptr<unordered_map<string, vector<Credentials>>> services) {

}

shared_ptr<unordered_map<string, vector<Credentials>>> readFromFile() {
    
}
