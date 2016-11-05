#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "pb_types.hpp"
#include "pb_opengl.hpp"

namespace PB {

    struct window_discriptor
    {
        str title;
        i64 size_x;
        i64 size_y;
    };

    class window
    {
    public:
        window();
        window(int size_y,int size_x,str title);
        window(int& size_y, int& size_x, str& title);
        window(str title);
        window(str &title);
        window(window_discriptor wnd);
        window(window_discriptor &wnd);
        void clear();
        void swap();
        ~window();

    private:
        color<float> clear_color;
        GLFWwindow *win;
    };
}
