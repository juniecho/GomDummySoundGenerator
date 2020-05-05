#include <windows.h>
#include <iostream>

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cmdShow)
{
    WinExec("PowerShell.exe -windowstyle hidden $PowerEventInfo=EventLog -LogName System -Source Microsoft-Windows-Power-Troubleshooter -Newest 1 | Out-String; $PowerEventInfoCurrent=$PowerEventInfo; $Player=New-Object Media.SoundPlayer \"silence.wav\"; while ($true) { $Player.PlayLooping(); while ($PowerEventInfo -like $PowerEventInfoCurrent) { $PowerEventInfoCurrent=EventLog -LogName System -Source Microsoft-Windows-Power-Troubleshooter -Newest 1 | Out-String; Start-Sleep -s 15 }; $PowerEventInfo=$PowerEventInfoCurrent; $Player.Stop() }", 1);
    while (true) {
        Sleep(99000);
        std::cout << "Main-Loop\n";
    }
}
