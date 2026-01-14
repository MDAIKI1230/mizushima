#include "CSVLoader.h"
#include <iostream>



void CSVLoader::load()
{
    std::ifstream file(inputFile);

    if(!file.is_open()){
        std::cerr << "ファイルを開けませんでした" << std::endl;
        // エラーをthrowしてmainでtry,catchする
        return;
    }

    std::string result;
    std::string buffer;
    while(std::getline(file, buffer)){
        result += buffer + "\n";
    }

    // ファイルを閉じる
    file.close();

    

    std::cout << result << std::endl;
}
