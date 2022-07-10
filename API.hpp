#pragma once

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <iomanip>  // collide with GCC's standard library implmentation
#include <tchar.h>


class API {
private:
    std::string url;
    std::string dest;

    LPCSTR StrToLPCSTR(std::string str);

public:
    API();
    API(std::string url, std::string dest);

    void DownloadSrcFromInternet(std::string url, std::string dest);
    void DownloadMultipleSrc(std::string urls[], std::string dests[], const int size);
};