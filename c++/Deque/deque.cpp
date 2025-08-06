#include <iostream>
#include <string>
#include <sstream>
#include <deque>

std::deque<int> dq;

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

        if (cmd == "push_front")
        {
            dq.push_front(value);
        }
        else if (cmd == "push_back")
        {
            dq.push_back(value);
        }
        else if (cmd == "pop_front")
        {
            if (!dq.empty()) {
                std::cout << dq.front() << std::endl;
                dq.pop_front();
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
        else if (cmd == "pop_back")
        {
            if (!dq.empty()) {
                std::cout << dq.back() << std::endl;
                dq.pop_back();
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
        else if (cmd == "size")
        {
            std::cout << dq.size() << std::endl;
        }
        else if (cmd == "empty")
        {
            if (!dq.empty()) {
                std::cout << 0 << std::endl;
            }
            else {
                std::cout << 1 << std::endl;
            }
        }
        else if (cmd == "front")
        {
            if (!dq.empty()) {
                std::cout << dq.front() << std::endl;
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
        else if (cmd == "back")
        {
            if (!dq.empty()) {
                std::cout << dq.back() << std::endl;
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