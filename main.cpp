#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    cout << "=== AutoClicker ===\n";
    cout << "Press 'F8' to START/STOP\n";
    cout << "Press 'END' to EXIT\n\n";

    bool active = false;

    while (true) {
        if (GetAsyncKeyState(VK_F8) & 0x8000) {
            active = !active;
            cout << (active ? "[RUNNING]" : "[PAUSED ]") << endl;
            Sleep(200);
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        if (active) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

            Sleep(100);
        }
    }

    return 0;
}