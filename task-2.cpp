#include <iostream>
#include <string>
#include <cpr/cpr.h>
int main() 
{
    std::string url = "http://httpbin.org/html"; // URL для запроса
    auto response = cpr::Get(cpr::Url{ url }, // Выполняем GET-запрос с заголовком Accept: text/html
        cpr::Header{ {"Accept", "text/html"} });
    if (response.status_code == 200) // Проверяем, успешен ли запрос
    {
        std::string response_text = response.text; // Получаем текст ответа
        std::string::size_type start = response_text.find("<h1>"); // Находим заголовок статьи между тегами <h1> и </h1>
        std::string::size_type end = response_text.find("</h1>");
        if (start != std::string::npos && end != std::string::npos) 
        {
            start += 4; // Извлекаем заголовок длина <h1> = 4
            std::string title = response_text.substr(start, end - start);
            std::cout << "Header of the title: " << title << std::endl;
        }
        else 
        {
            std::cout << "The header was not found." << std::endl;
        }
    }
    else 
    {
        std::cout << "Request execution error. Status code: " << response.status_code << std::endl;
    }
    return 0;
}


