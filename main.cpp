#include <iostream>
#include <experimental/filesystem>
//g++ -o main main.cpp -lstdc++fs
int main(int argc, char *argv[]) {
  std::experimental::filesystem::path cwd = 
  std::experimental::filesystem::current_path();
  

  std::cout << "Name: \t\t\tCreated:" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  for(auto const& dir_entry: std::experimental::filesystem::directory_iterator{cwd} ){
    std::cout << dir_entry.path().filename() << "\t\t\t" << dir_entry.path() << std::endl;
  }


} 
