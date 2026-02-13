#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    srand(time(0));

    int speed;
    cout << "=== AutoClicker ===\n";
	cout << "Shose the speed of the clicker:\n";
    cin >> speed;

    if(speed <= 0) {
        cout << "Speed must be a positive" << endl;
        return 1;
	}

    if (speed > 1000)
    {
        cout << "Speed cannot be more then 1000" << endl;
        return 1;
    }

    cout << "Press 'F8' to START/STOP\n";
    cout << "Press 'ESC' to EXIT";

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

            int finalDelay = speed + (rand() % 31);
            Sleep(finalDelay);
        }
    }

    return 0;
}