#pragma once
#include <memory>
#include <unordered_map>
#include <../include/Credentials.hpp>
class FileManager
{
private:
    std::unique_ptr<std::FILE> file;
public:
    std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> readFromFile();
    void writeToFile(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services);
    FileManager(std::unique_ptr<FILE> file, std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services);
    ~FileManager();
};
