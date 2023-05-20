#include <iostream>
#include <fstream>
#include <string>

int main() {
  int choice = 0;
  std::string username;
  std::string password;
  std::string matchUser;
  std::string matchPass;
  std::ifstream inFile;

  std::cout << "1: Login\n2: Register\nYour Choice: ";
  std::cin >> choice;

  switch (choice) {
  default:
    std::cout << "Invalid choice\n";
    break;

  case 1:
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    inFile.open("filename.txt");
    if (!inFile.is_open()) {
      std::cout << "Cannot open file\n";
      break;
    }

    while (std::getline(inFile, matchUser) && std::getline(inFile, matchPass)) {
      if (matchUser == "Username: " + username && matchPass == "Password: " + password) {
        std::cout << "Authenticated. Welcome " << username << "!\n";
        break;
      }
    }

    //if (inFile.eof()) {
      //std::cout << "Invalid username or password\n";
   //}
    inFile.close();
    break;

  case 2:
    std::cout << "New Username: ";
    std::cin >> username;
    std::cout << "New Password: ";
    std::cin >> password;

    std::cout << "Your new username is: " << username << std::endl <<
      "Your new password is: " << password << std::endl;
    break;
  }

  return 0;
}