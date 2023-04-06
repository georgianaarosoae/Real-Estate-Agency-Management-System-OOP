#pragma once

#include <string>
#include <map>
#include <vector>

class Utils
{
public:
    Utils();
    std::string tipFisier(std::string str);
    std::pair<std::string, std::string> citireLinie(std::string str);
    std::map<std::string, int> citireCamere(std::string str);
    std::vector<std::string> citireDotari(std::string str);
};