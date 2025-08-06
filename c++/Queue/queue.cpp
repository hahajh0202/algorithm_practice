#include <iostream>
#include <string>
#include <sstream>
#include <queue>

std::queue<int> q;

int main(){
    int cmd_number;

    std::cin >> cmd_number;
    std::cin.ignore();

    for (int i = 0; i < cmd_number; i++)
    {
        std::string line;
        getline(std::cin, line);
        std::istringstream iss(line);

        std::string cmd;
        int value;
        iss >> cmd >> value;

        if (cmd == "push")
        {
            q.push(value);
        }
        else if (cmd == "pop")
        {
            if (!q.empty()){
                std::cout << q.front() << std::endl;
                q.pop();
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
        else if (cmd == "size")
        {
            std::cout << q.size() << std::endl;
        }
        else if (cmd == "empty")
        {
            if (!q.empty()) {
                std::cout << 0 << std::endl;
            }
            else {
                std::cout << 1 << std::endl;
            }
        }
        else if (cmd == "front")
        {
            if (!q.empty()) {
                std::cout << q.front() << std::endl;
            }
            else {
                std::cout << -1 << std::endl;
            }            
        }
        else if (cmd == "back")
        {
            if (!q.empty()) {
                std::cout << q.back() << std::endl;
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
        else 
        {
            /* Do Nothing */
        }

    }
    
    return 0;
}