#include<iostream>
#include<fstream>

int main(){
    std::ofstream output_file_stream("info.txt", std::ios::app);
    if(output_file_stream.is_open()){
        output_file_stream << "\nAppended content !!!";
        output_file_stream.close();
    }
    return 0;
}