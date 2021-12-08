#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

LPWSTR ClipboardO();
LPWSTR ItsNumber(LPWSTR);
int AddInStr(LPWSTR, int, LPWSTR);

int WINAPI wWinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LPWSTR str = L"";
	LPWSTR StrWarning = L"Привет Андрей, та тара та...";
	TCHAR MainArr[512];	
	while (1)
	{
		str = ClipboardO();
        str = ItsNumber(str);
		swprintf(MainArr, sizeof(MainArr), L"%s\n%s", StrWarning, str);//123  Корень 1 уравнения 9 равен 1234567890
		if (*str != 0)
		{
			MessageBox(0, MainArr, L"", MB_OK);
			ClipboardI("");
		}
		Sleep(1000);
	}			
	return 0;
}

int ClipboardI(LPWSTR str)
{
	HANDLE hMem = GlobalAlloc(GMEM_MOVEABLE, (wcslen(str) + 1) * sizeof(WCHAR));//Привет
	memcpy(GlobalLock(hMem),str, (wcslen(str) + 1) * sizeof(WCHAR));
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
	return 0;
}

LPWSTR ClipboardO()
{
	OpenClipboard(0);
	HANDLE hMem = GetClipboardData(CF_UNICODETEXT);
	LPWSTR str = (LPWSTR)GlobalLock(hMem);
	GlobalUnlock(hMem);
	CloseClipboard();	
	EmptyClipboard();
	return str;
}

LPWSTR ItsNumber(LPWSTR str)
{
    int i = 0, y = 0;
    LPWSTR NewStr = calloc(512, 2);
    LPWSTR Str0 = L"Ноль";
    LPWSTR Str1 = L"Один";
    LPWSTR Str2 = L"Два";
    LPWSTR Str3 = L"Три";
    LPWSTR Str4 = L"Четыре";
    LPWSTR Str5 = L"Пять";
    LPWSTR Str6 = L"Шесть";
    LPWSTR Str7 = L"Семь";
    LPWSTR Str8 = L"Восемь";
    LPWSTR Str9 = L"Девять";
    while (1)
    {
        if (str[i] == '\0')
        {
            break;
        }
        switch (str[i])
        {
        case L'0':
            y = AddInStr(NewStr, y, Str0);
            break;
        case L'1':
            y = AddInStr(NewStr, y, Str1);
            break;
        case L'2':
            y = AddInStr(NewStr, y, Str2);
            break;
        case L'3':
            y = AddInStr(NewStr, y, Str3);
            break;
        case L'4':
            y = AddInStr(NewStr, y, Str4);
            break;
        case L'5':
            y = AddInStr(NewStr, y, Str5);
            break;
        case L'6':
            y = AddInStr(NewStr, y, Str6);
            break;
        case L'7':
            y = AddInStr(NewStr, y, Str7);
            break;
        case L'8':
            y = AddInStr(NewStr, y, Str8);
            break;
        case L'9':
            y = AddInStr(NewStr, y, Str9);
            break;  
        default:
            NewStr[y] = str[i];
            break;
        }
        i++; 
        y++;
    }
    return NewStr;
}

int AddInStr(LPWSTR str, int i, LPWSTR AddStr)
{
    for (int z = 0; z < wcslen(AddStr); z++)
    {
        str[i] = AddStr[z];
        i++;
    }
    i--;
    return i;
}