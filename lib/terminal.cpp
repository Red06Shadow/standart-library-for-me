#include <stda/system/terminal/terminal.hpp>

void System::Terminal::get_caracters_of_terminal()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        columnas = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        filas = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
}

void System::Terminal::clearScreen()
{
    // Secuencia ANSI: ESC[2J (limpiar pantalla)
    std::cout << "\033[2J";
    // std::cout << "\033[1;1H";
}
void System::Terminal::clearLine()
{
    // Secuencia ANSI: ESC[2K (limpiar línea actual)
    std::cout << "\033[2K\r";
}
void System::Terminal::moveCursorTo(int row, int col)
{
    // Secuencia ANSI: ESC[row;colH
    if (col > columnas)
        row = col - columnas;
    if (row > filas)
        row = row - filas;
    std::cout << "\033[" << row << ";" << col << "H";
}

void System::Terminal::saveCursorPosition()
{
    // Secuencia ANSI: ESC[s (guardar posición cursor)
    std::cout << "\033[s";
}

void System::Terminal::restoreCursorPosition()
{
    // Secuencia ANSI: ESC[u (restaurar posición cursor)
    std::cout << "\033[u";
}
void System::Terminal::hideCursor()
{
    std::cout << "\033[?25l";
}
void System::Terminal::showCursor()
{
    std::cout << "\033[?25h";
}
void System::Terminal::setTextColor(Color color)
{
    std::cout << "\033[" << static_cast<int>(color) << "m";
}
std::string System::Terminal::getTextColor(Color color)
{
    return "\033[" + std::to_string(static_cast<int>(color)) + "m";
}
void System::Terminal::resetTextColor()
{
    std::cout << "\033[0m";
}
int System::Terminal::exc()
{
    std::string str;
    std::getline(std::cin, str);
    if (str == "exit")
        return -1;
    return system(("powershell -Command \"" + str + "\"").c_str());
}
void System::Terminal::set_terminal()
{
    std::cout << "\033[1;32m" << System::Terminal::user << " @ pc\033[0m : \033[1;34m" << System::Terminal::current_directory << "\033[0m $ ";
}
std::string System::Terminal::get_terminal()
{
    return "\033[1;32m" + System::Terminal::user + " @ pc\033[0m : \033[1;34m" + System::Terminal::current_directory + "\033[0m $ ";
}