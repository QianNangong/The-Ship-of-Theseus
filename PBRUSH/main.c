#include <windows.h>

void __cdecl Entry()
{
    LPSTR lpCmdLine = GetCommandLineA();
    if (*lpCmdLine == '\"')
    {
        do
        {
            lpCmdLine++;
            if (*lpCmdLine == '\0')
            {
                break;
            }
        } while (*lpCmdLine != '\"');
        if (*lpCmdLine == '\"')
        {
            lpCmdLine++;
        }
    }
    else
    {
        while (*lpCmdLine > ' ')
        {
            lpCmdLine++;
        }
    }
    while ((*lpCmdLine != '\0') && (*lpCmdLine < '!'))
    {
        lpCmdLine++;
    }
    STARTUPINFOA info;
    info.dwFlags = 0;
    GetStartupInfoA(&info);
    if (!(info.dwFlags & STARTF_USESHOWWINDOW))
    {
        info.wShowWindow = SW_SHOWNORMAL;
    }
    ShellExecuteA(NULL, NULL, "mspaint.exe", lpCmdLine, NULL, info.wShowWindow);
    ExitProcess(0);
}
