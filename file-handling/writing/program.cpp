#include<iostream>
#include<fstream>

int main(){
    std::string content("this is a demo content\nto be written into file");
    std::ofstream output_file_stream("info.txt");
    if(output_file_stream.is_open()){
        output_file_stream << content; // method 1
        output_file_stream.write(content.c_str(), content.length()); // method 2
        output_file_stream.close();
    }else{
        std::cout << "File cannot open for writing contents " << std::endl;
        return -1;
    }
    return 0;
}