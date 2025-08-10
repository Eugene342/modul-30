#include <iostream>
#include <map>
#include <string>
#include <cpr/cpr.h>
int main() 
{
    std::map<std::string, std::string> arguments;
    std::string key, value;
    while (true) // Считываем аргументы от пользователя
    {
        std::cout << "Enter the name of the argument (or 'post'/'get' to complete): ";
        std::cin >> key;
        if (key == "post" || key == "get") // Проверяем, не является ли ключ 'post' или 'get'
        {
            break;
        }
        std::cout << "Enter the value of the argument: ";
        std::cin >> value;
        arguments[key] = value; // Сохраняем аргумент в словарь
    }
    if (key == "post") // Выполняем запрос в зависимости от типа
    {
        std::vector<cpr::Pair> payload; // Создаем массив пар для POST-запроса
        for (const auto& arg : arguments) 
        {
            payload.emplace_back(cpr::Pair(arg.first, arg.second));
        }
        cpr::Response r = cpr::Post(cpr::Url{ "https://httpbin.org/post" }, // Выполняем POST-запрос
            cpr::Payload{ payload.begin(), payload.end() });
        std::cout << "Server response (POST): " << r.text << std::endl; // Выводим ответ сервера
    }
    else if (key == "get")
    {
        std::string url = "https://httpbin.org/get?"; // Формируем URL с аргументами для GET-запроса
        for (const auto& arg : arguments) 
        {
            url += arg.first + "=" + arg.second + "&";
        }
        url.pop_back(); // Убираем последний '&'
        cpr::Response r = cpr::Get(cpr::Url{ url }); // Выполняем GET-запрос
        std::cout << "Server response (GET): " << r.text << std::endl; // Выводим ответ сервера
    }
    return 0;
}



