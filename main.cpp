#include <iostream>
#include "filesystem.hpp"
#include <iomanip>
#include "flag_functions.h"
namespace fs = ghc::filesystem;

//g++ -o main main.cpp -lstdc++fs
int main(int argc, char *argv[]) {
  fs::path cwd = 
  fs::current_path();

  bool parsing_flag;//so we can track when we're parsing
  bool reading_custom_path;//reading state of just reading path
  std::string custom_path= "";//to hold path from arg
  //parse arguments
  for(int i = 0; i < argc; i++){	
	std::cout << argv[i];
	if(*argv[i] == '-'){
		reading_custom_path = false;
		switch(*argv[i+1]){
			case 'h':
				//call help function, exit
				break;
			case 's':
				//size
				break;
			case 'o':
				//owner
				break;
			case 'm':
				//last modified
				break;
			case 'p':
				//custom path 
				reading_custom_path = true;
				break;
			default:
				//invalid argument, err
				break;
		}
		i++;//increment since we read next already
	}
	else if(reading_custom_path = true){
		custom_path += *argv[i];
	}
	else{
		//invalid argument, err
	}
	std::cout << custom_path << std::endl;

  }

  std::cout << "Files in " << cwd << std::endl;
  std::cout << std::left << std::setw(20) << "name"  << "size" << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  
  //main output loop
  for(auto const& dir_entry: fs::directory_iterator{cwd} ){
	std::string filename = dir_entry.path().filename();
	std::cout << filename;
	if(fs::status(dir_entry.path()).type() == fs::file_type::directory){
		std::cout << "/";
	}
	std::cout << std::endl;
  }


} 
