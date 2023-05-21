#include<iostream>
#include<fstream>

int main(){
    std::ifstream input_file_stream("info.txt");
    if(input_file_stream.is_open()){
        std::string line;
        while(std::getline(input_file_stream, line)){
            std::cout << line << std::endl;
        }
    }else{
        std::cout << "Cannot Open the file " << std::endl;
        return -1;
    }
    input_file_stream.close();
    return 0;
}