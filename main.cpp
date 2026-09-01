#include "AnaForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();

    Application::SetCompatibleTextRenderingDefault(
        false
    );

    Application::Run(
        gcnew medtrack::AnaForm1()
    );

    return 0;
}