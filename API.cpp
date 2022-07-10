#include "API.hpp"
#include "CallbackHandler.hpp"

LPCSTR API::StrToLPCSTR(std::string str)
{
    const int str_size = str.size();
    char* str_arr = new char[str_size];

    for (int i = 0; i < str_size + 1; i++)
    {
        str_arr[i] = str[i];
    }

    const char* strc = str_arr;

	return strc;
}

API::API() {

}

API::API(std::string url, std::string dest) {
	this->url  = url;
	this->dest = dest;
}

void API::DownloadSrcFromInternet(std::string url, std::string dest) {
	this->url  = url;
	this->dest = url;
	LPCSTR lurl = StrToLPCSTR(url);
	LPCSTR ldest = StrToLPCSTR(dest);

	std::wcout << _T("Downloading   : ") << lurl << std::endl;

	CallbackHandler callbackHandler;
	IBindStatusCallback* pBindStatusCallback = NULL;
	callbackHandler.QueryInterface(IID_IBindStatusCallback,
		reinterpret_cast<void**>(&pBindStatusCallback));


	HRESULT hr = URLDownloadToFileA(NULL, lurl, ldest, 0, pBindStatusCallback);
	
	if (hr == S_OK)
	{
		printf("Saved to %s\n", ldest);
	}

}
void API::DownloadMultipleSrc(std::string urls[], std::string dests[],const int size)
{
	for (int i = 0; i < size; i++)
	{
		this->DownloadSrcFromInternet(urls[i], dests[i]);
	}
	
}
