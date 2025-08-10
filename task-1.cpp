#include <iostream>
#include <string>
#include <cpr/cpr.h>
void perform_request(const std::string& command) 
{
    if (command == "get") 
    {
        auto response = cpr::Get(cpr::Url{ "https://httpbin.org/get" });
        std::cout << "Response:\n" << response.text << std::endl;
    }
    else if (command == "post") 
    {
        auto response = cpr::Post(cpr::Url{ "https://httpbin.org/post" }, cpr::Body{ "{\"key\":\"value\"}" }, cpr::Header{ {"Content-Type", "application/json"} });
        std::cout << "Response:\n" << response.text << std::endl;
    }
    else if (command == "put") 
    {
        auto response = cpr::Put(cpr::Url{ "https://httpbin.org/put" }, cpr::Body{ "{\"key\":\"value\"}" }, cpr::Header{ {"Content-Type", "application/json"} });
        std::cout << "Response:\n" << response.text << std::endl;
    }
    else if (command == "delete") 
    {
        auto response = cpr::Delete(cpr::Url{ "https://httpbin.org/delete" });
        std::cout << "Response:\n" << response.text << std::endl;
    }
    else if (command == "patch") 
    {
        auto response = cpr::Patch(cpr::Url{ "https://httpbin.org/patch" }, cpr::Body{ "{\"key\":\"value\"}" }, cpr::Header{ {"Content-Type", "application/json"} });
        std::cout << "Response:\n" << response.text << std::endl;
    }
    else 
    {
        std::cout << "Unknown command." << std::endl;
    }
}
int main() 
{
    std::string command;
    std::cout << "Enter HTTP command (get, post, put, delete, patch) or 'exit' to quit:" << std::endl;
    while (true) 
    {
        std::getline(std::cin, command);
        if (command == "exit") 
        {
            break;
        }
        perform_request(command);
    }
    return 0;
}

