#include <iostream>
#include "filesystem.hpp"
//g++ -o main main.cpp -lstdc++fs
int main(int argc, char *argv[]) {
  std::experimental::filesystem::path cwd = 
  std::experimental::filesystem::current_path();

  std::cout << "Files in " << cwd << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  for(auto const& dir_entry: std::experimental::filesystem::directory_iterator{cwd} ){
  	std::cout << dir_entry.path().filename() << std::endl;
	std::string filename = dir_entry.path().filename() << std::endl;
	std::cout << filename << std::endl;
  }


} 
