#include <iostream>
#include <string>
#include <windows.h>
#include <filesystem>
#include <ctime>
using namespace std;
#pragma comment(lib,"urlmon.lib")
static const char AlphaNumeric[] = "0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";
int MyLen = sizeof(AlphaNumeric) - 1;
char RandomStr() {
    return AlphaNumeric[rand() % MyLen];
}
string Generate() {
    string result;
    int m;
    m = 0;
    int l;
    l = 5;
    while (m < l) {
        result = result + RandomStr();
        m = m + 1;
    }
    return result;
}
void Download(string format) {
    while (!false) {
        unsigned int start_time = clock();
        string resultGen;
        resultGen = Generate();
        string link;
        link = "https://i.imgur.com/" + resultGen + format;
        string path;
        path = "out\\" + resultGen + format + " ";
        string command;
        wstring stemp = wstring(link.begin(), link.end());
        LPCWSTR sw = stemp.c_str();
        wstring stemp1 = wstring(path.begin(), path.end());
        LPCWSTR sw1 = stemp1.c_str();
        HRESULT hr = URLDownloadToFile(0, sw, sw1, 0, NULL);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;
        if (hr == S_OK)
        {
            cout << "  Downloaded: " << path << "| Time: " << search_time << "ms" << endl;
        }
    }
}
void menu() {
    string y;
    cout << "\n  Format(example: .png): ";
    cin >> y;
    cout << "  -------------------------------\n";
    Download(y);
}
void mainMenu() {
    cout << "\n  ImgurKillerC++";
    cout << " -> by lomaster" << endl;
    cout << "  -------------------------------";
    menu();
}
int main() {
    CreateDirectory(L"out", NULL);
    mainMenu();
    return 0;
}