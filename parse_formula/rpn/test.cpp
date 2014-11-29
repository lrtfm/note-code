/*
 * Mrpn.cpp
 *
 * YangZongze yangzongze@gmail.com
 */

#include "Mfunction.hpp"
#include "Mtoken.hpp"
#include "Msys.hpp"
#include <cstdlib>

int main()
{
    char name[256];
    char var[256];
    char p[256];
    std::vector<double> v;
    std::string token;
    while (1) {
        std::cout << std::endl;
        std::cout << "Please input var:" << std::endl;
        std::cin.getline(var, 256);
        std::cout << "Please input formual:" << std::endl;
        std::cin.getline(name, 256);
        if (std::cin.eof()) {
            break;
        }

        FunctionBase test(var, name);
        test.print();
        while(1) {
            v.resize(0);
            std::cout << "Please input p value:" << std::endl;
            std::cin.getline(var, 256);
            if (var[0] == '#') {
                break;
            }
            size_t index = 0;
            while(MC::numProcess.getToken(var, index, token)) {
                std::cout << "Token:" <<token;
                v.push_back(atof(token.c_str()));
            }
            std::cout <<std::endl;
            std::cout <<"result: " << test.compute(v) <<std::endl;
            if (std::cin.eof()) { break; }
        }

    }
    return 0;
}
