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

std::string perm2string(fs::perms p){
    using std::filesystem::perms;
    std::string ret = "";
    auto show = [=](char op, perms perm)
    {
        char x = (perms::none == (perm & p) ? '-' : op);
    };
    ret+= (perms::none == (perms::owner_read & p)) ? "-":"r";
    ret+= (perms::none == (perms::owner_write & p)) ? "-":"w";
    ret+= (perms::none == (perms::owner_exec & p)) ? "-":"x";
    ret+= (perms::none == (perms::group_read & p)) ? "-":"r";
    ret+= (perms::none == (perms::group_write & p)) ? "-":"w";
    ret+= (perms::none == (perms::group_exec & p)) ? "-":"x";
    ret+= (perms::none == (perms::others_read & p)) ? "-":"r";
    ret+= (perms::none == (perms::others_write & p)) ? "-":"w";
    ret+= (perms::none == (perms::others_exec & p)) ? "-":"x";
    return ret;
}

//Implement a function to read inside a folder, so that we can call it recursively
void readFolder(const fs::path& path){
    //Read all item
    std::vector<item> items;
    for(const auto& entry: fs::directory_iterator(path)){
        // items.push_back(item{path,entry.status().type(),"",""});
        //Get item's name
        std::string name = address2name(entry.path());
        //Get item's permission
        std::string permission = perm2string(entry.status().permissions());
        //Get item bool directory?
        bool isDirectory = entry.is_directory();
        //Get item last change time
        std::cout<<entry.last_write_time()
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