#include <iostream>
#include "filesystem.hpp"
#include <iomanip>
#include "flag_functions.h"
#include <chrono>
namespace fs = ghc::filesystem;

//g++ -o main main.cpp -lstdc++fs
int main() {
  fs::path cwd = 
  fs::current_path();

  std::cout << "Files in " << cwd << std::endl;
  std::cout << ":---------------------------------------------------------------:" <<
	  std::endl;
  std::cout << std::left << std::setw(20) << ":Name"  <<
	 std::setw(20) << "Size" << std::setw(24) << "Last Modified" <<
	 ":" << std::endl;
  std::cout << ":---------------------------------------------------------------:" << std::endl;
  
  //main output loop, iterates over each file
  for(auto const& dir_entry: fs::directory_iterator{cwd} ){
	//get file name and add / if file is directory
	std::string filename = dir_entry.path().filename();
	if(fs::status(dir_entry.path()).type() == fs::file_type::directory){
		filename += '/';
	}
	//store last modified time into string
	struct stat attr;
	stat(dir_entry.path().c_str(), &attr);
	std::string time_last_modified = ctime(&attr.st_mtime);

	//print stats to the screen
	std::cout << std::setw(20) << filename <<
		std::setw(20) <<  fs::file_size(dir_entry.path()) <<
		time_last_modified;
  }

} 
