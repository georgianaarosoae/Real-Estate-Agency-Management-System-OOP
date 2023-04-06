#include "Utils.h"

Utils::Utils()
{
}

std::pair<std::string, std::string> Utils::citireLinie(std::string str)
{
    char aux[1000000];
    strcpy(aux, str.c_str());
    char* ptr = strtok(aux, ":");
    bool fieldOcupat = false;

    // suprafata: 100
    std::pair<std::string, std::string> rezultat;
    rezultat = std::make_pair("", "");
    while (ptr != NULL)
    {
        if (fieldOcupat)
        {
            rezultat.second = ptr;
        }
        else
        {
            rezultat.first = ptr;
        }
        ptr = strtok(NULL, ":");
        fieldOcupat = true;
    }
    if (rezultat.second[0] == ' ')
        rezultat.second = rezultat.second.substr(1, rezultat.second.length() - 1);
    return rezultat;
}

std::string Utils::tipFisier(std::string str)
{
    std::string rezultat = "";
    for (size_t i = str.length() - 1; i >= 0; --i)
    {
        if (str[i] == '.')
            break;
        rezultat += str[i];
    }
    std::reverse(rezultat.begin(), rezultat.end());
    return rezultat;
}

std::map<std::string, int> Utils::citireCamere(std::string str)
{
    std::map<std::string, int> rezultat;
    char aux[1000000];
    strcpy(aux, str.c_str());
    char* ptr = strtok(aux, ",");
    while (ptr != NULL)
    {
        std::pair<std::string, int> camera;
        char aux2[1000000];
        strcpy(aux2, ptr);
        char* ptr2 = strtok(aux2, ":");
        bool fieldOcupat = false;
        while (ptr2 != NULL)
        {
            if (fieldOcupat)
            {
                camera.second = std::stoi(ptr2);
            }
            else
            {
                camera.first = ptr2;
            }
            ptr2 = strtok(NULL, ":");
            fieldOcupat = true;
        }
        rezultat.insert(camera);
        ptr = strtok(NULL, ",");
    }
    return rezultat;
}

std::vector<std::string> Utils::citireDotari(std::string str)
{
    std::vector<std::string> rezultat;
    char aux[1000000];
    strcpy(aux, str.c_str());
    char* ptr = strtok(aux, ",");
    while (ptr != NULL)
    {
        rezultat.push_back(ptr);
        ptr = strtok(NULL, ",");
    }
    return rezultat;
}