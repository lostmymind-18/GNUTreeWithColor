//Get nessessary libraries
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<filesystem>
namespace fs = std::filesystem;

struct item{
    std::string address;
    bool isDirectory;
    std::string lastChangeTime;
    std::string accessControl;
};

//SHALLOW FUNCTION
std::string type(std::string address){

}

//SHALLOW FUNCTION
std::string address2name(std::string address){
    //Get last position of '/'
    int pos = address.find_last_of('/');
    //return substring
    return address.substr(pos+1);
}
//Implement a function to read inside a folder, so that we can call it recursively
void readFolder(const fs::path& path){
    //Read all item
    std::vector<item> items;
    for(const auto& entry: fs::directory_iterator(path)){
        // items.push_back(item{path,entry.status().type(),"",""});
        entry.status().permissions();
    }
    //All item that is not a folder get to the front
    //Print all item that is not a folder
    //If the items is a folder
        //Print it's name
        //then read inside it recursively
        // readFolder(/*that folder*/);
    return;
}

int main(){
    readFolder(fs::current_path());
}