#include <Windows.h>
#include <iostream>

using namespace std;
int main()
{
    WIN32_FIND_DATA file;
    HANDLE search_handle=FindFirstFile("E:/C-programming/Contest/*.cpp",&file);
    if (search_handle)
    {
        do
        {
             cout << file.cFileName <<  endl;
        }while(FindNextFile(search_handle,&file));
        CloseHandle(search_handle);

    }

}
