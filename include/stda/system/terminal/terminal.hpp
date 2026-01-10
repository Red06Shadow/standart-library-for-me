#include <system/files/url/url.hpp>
#include <string>
#include <type_traits>
#include <conio.h>
#include <windows.h>

namespace System
{

    class Terminal
    {
    public:
        class Text
        {
        public:
            enum class Color : short
            {
                BLACK = 30,
                RED,
                GREEN,
                YELLOW,
                BLUE,
                MAGENTA,
                CYAN,
                WHITE,
                BRIGHT_BLACK = 90,
                BRIGHT_RED,
                BRIGHT_GREEN,
                BRIGHT_YELLOW,
                BRIGHT_BLUE,
                BRIGHT_MAGENTA,
                BRIGHT_CYAN,
                BRIGHT_WHITE
            };
            enum class Style : short
            {
                RESET,
                NORMAL,
                NEGRITA,
                TENUE,
                CURSIVA,
                SUBRAYADO,
                PARPADEO,
                INVERTIDO,
                OCULTO
            };
        };
        class Background
        {
            enum class Color : short
            {
                RESET = 0,
                BLACK = 40,
                RED,
                GREEN,
                YELLOW,
                BLUE,
                MAGENTA,
                CYAN,
                WHITE,
                BRIGHT_BLACK = 100,
                BRIGHT_RED,
                BRIGHT_GREEN,
                BRIGHT_YELLOW,
                BRIGHT_BLUE,
                BRIGHT_MAGENTA,
                BRIGHT_CYAN,
                BRIGHT_WHITE,
            };
        };
        enum class Keywords : int
        {
            NONE,
            KEY_UP,
            KEY_DOWN,
            KEY_LEFT,
            KEY_RIGTH
        };

    private:
        static constexpr const char *color_call = "\033[";
        static constexpr const char *end_color_call = "m";
        /////////////////////////////////////////////////////
        inline static std::string user = "user";
        inline static std::string current_directory = "C:/";
        /////////////////////////////////////////////////////
        static inline int columnas = 0;
        static inline int filas = 0;
        /////////////////////////////////////////////////////
        static std::string anidation() { return ""; }
        template <typename T, typename... Args>
        static std::string anidation(const T &arg, const Args &...args) { return ""; }
        template <typename... Args>
        static std::string anidation(const char *arg, const Args &...args)
        {
            std::string str = anidation(args...);
            return std::string(arg) + (str.empty() ? str : (" && " + str));
        }
        template <typename... Args>
        static std::string anidation(const std::string &arg, const Args &...args)
        {
            std::string str = anidation(args...);
            return std::string(arg) + (str.empty() ? str : (" && " + str));
        }
        static void get_caracters_of_terminal();

    public:
        static void clearScreen();
        static void clearLine();

        static void moveCursorTo(int row, int col);
        static void saveCursorPosition();
        static void restoreCursorPosition();

        static void hideCursor();
        static void showCursor();

        static void setTextColor(Text::Color color, Text::Style style = Text::Style::NORMAL);
        static std::string getTextColor(Text::Color color, Text::Style style = Text::Style::NORMAL);
        static void resetColors();

        static void set_user(const std::string &name) { user = name; }
        static void set_current_directory(const std::string &url) { current_directory = url; }
        static int exc();
        template <typename... Args>
        static int exc(const Args &...args) { return system(anidation(args...).c_str()); }

        // static void update()
        // {
        //     Terminal::showCursor();
        //     int col = 1;
        //     int row = 1;
        //     while (__continue)
        //     {
        //         // Terminal::clearScreen();
        //         if (__press_key == Keywords::KEY_UP)
        //             row--;
        //         else if (__press_key == Keywords::KEY_DOWN)
        //             row++;
        //         Terminal::moveCursorTo(pfilas, pcolumnas);
        //         Terminal::setTextColor(Terminal::Color::GREEN);
        //         std::cout << "H";
        //         Terminal::resetTextColor();
        //     }
        //     // if (recibe.joinable())
        //     //     recibe.join();
        // }
        // static void exit() { __continue = false; }
    };
};
