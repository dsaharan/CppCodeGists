#include <iostream>
#include <string>

#include <vector>
#include <sstream>

template<typename T>
std::ostream& print(std::ostream &out, T const &val) {
  return (out << val );
}

template<typename T1, typename T2>
std::ostream& print(std::ostream &out, std::pair<T1, T2> const &val) { return (out << "{" << val.first << " " << val.second << "} "); }

template<template<typename, typename...> class TT, typename... Args>
std::string joinElementsByLiteral(TT<Args...> const &cont ,const std::string & literal)
{
    std::stringstream str;
     for(auto elem : cont)
     {
        print(str, elem);
        str<<literal;
     }
    std::string stringToReturn   = str.str();
    return stringToReturn.substr(0,stringToReturn.size()-1) ;
}
int main()
{

    std::vector<float> variantCollection;
    variantCollection.push_back(1.0);
    variantCollection.push_back(2.2);
    std::cout<<joinElementsByLiteral(variantCollection,",");

}
