#include <iostream>
#include <map>
#include <string>

struct dirty {
    bool operator()(const int & a, const int & b) const {
        return a > b;
    }
};

int main(int argc, char *argv[])
{
    std::map<int, std::string, dirty> map1;
    map1[2] = "value2";
    map1[1] = "value1";
    map1[11] = "value11";
    map1[5] = "value5";

    for (std::map<int, std::string>::const_iterator it = map1.cbegin(); it != map1.cend(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}
