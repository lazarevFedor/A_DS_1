#include "application.h"
#include "Windows.h"
#undef max

int main() {
    SetConsoleOutputCP(CP_UTF8);
    application app;
    app.interactionMenu();
    return 0;
}