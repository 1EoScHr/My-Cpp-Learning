#include <iostream>
#include <utility>  //pair make_pair
#include <string>   //string
#include <sstream>  //stringstream
#include <fstream>  //fstream
#include <map>      //map

std::map<std::string, std::pair<std::string, std::string>> creatMap(std::string filename);
void printMap(std::map<std::string, std::pair<std::string, std::string>> csMap);
void judgeAlum(std::pair<std::string, std::string> info);
void errorHandle(void);

int main()
{
    auto map = creatMap("teacher.csv");
    printMap(map);

    return 0;
}

std::map<std::string, std::pair<std::string, std::string>> creatMap(std::string filename)
{
    std::ifstream theCsv(filename);
    std::map<std::string, std::pair<std::string, std::string>> tch_map;
    std::string line, name, uni, year;
    
    if(!theCsv)
    {
        std::cout << "Cant open file" << std::endl;
        errorHandle();
    }

    while(std::getline(theCsv, line))
    {
        std::istringstream ss(line);

        std::getline(ss, name, ',');
        std::getline(ss, uni, ',');
        std::getline(ss, year);

        tch_map.insert({name, std::make_pair(uni, year)});
    }

    return tch_map;
}

void printMap(std::map<std::string, std::pair<std::string, std::string>> csMap)
{
    for(auto iter = csMap.begin(); iter != csMap.end(); iter ++)
    {
        const auto& [name, info] = *iter;
        std::cout << name << " " << std::endl;
        judgeAlum(info);
    }
}

void judgeAlum(std::pair<std::string, std::string> info)
{
    if(info.first == "Stanford")
    {
        std::cout << "Yes" << std::endl;
    }

    else
    {
        std::cout << "No" << std::endl;
    }
}

void errorHandle(void)
{
    

}

