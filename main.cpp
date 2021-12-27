#include <iostream>
#include "filesystem.hpp"
namespace fs = ghc::filesystem;

//g++ -o main main.cpp -lstdc++fs
int main(int argc, char *argv[]) {
  fs::path cwd = 
  fs::current_path();

  std::cout << "Files in " << cwd << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  for(auto const& dir_entry: fs::directory_iterator{cwd} ){
	std::string filename = dir_entry.path().filename();
	std::cout << filename << std::endl;
  }


} 
