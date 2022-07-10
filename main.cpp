#include "API.hpp"
#include <string>


#ifdef _MSC_VER
    #pragma comment(lib, "Winmm.lib")
    #pragma comment(lib, "Urlmon.lib")
#endif

using namespace std;

int main()
{
    // Make a directory to put quraans into it.
    _wmkdir(L"quraan");

    // Make an API Object.
    API api;
    api.DownloadSrcFromInternet("https://server7.mp3quran.net/download/basit/Almusshaf-Al-Mojawwad/001.mp3", "quraan/001.mp3");

    // Collect entire quraan surats.
    std::string urls[114] = {};
    std::string destFiles[114] = {};
    for (int i = 0; i < 114; i++)
    {
        std::string url = "https://server7.mp3quran.net/download/basit/Almusshaf-Al-Mojawwad/";
        const std::string dest = "quraan";
        std::string filename = "";

        if (i + 1 < 10)
            filename += "00" + std::to_string(i + 1);
        else if (i + 1 < 100)
            filename += "0" + std::to_string(i + 1);
        else
            filename += std::to_string(i + 1);

        filename += ".mp3";
        url += filename;

        urls[i] = url;
        destFiles[i] = dest + "/" + filename;

    }

    // Download Entire surats of abdulbasit (R.Z).
    api.DownloadMultipleSrc(urls, destFiles,  sizeof(urls) / sizeof(urls[0]));


#if _MSC_VER && !__INTEL_COMPILER
    mciSendString(L"open \"quraan/001.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString(L"play mp3", NULL, 0, NULL);
#else
    mciSendString("open \"001.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    mciSendString("play mp3", NULL, 0, NULL);
#endif
    while (1)
    {
    }

}
