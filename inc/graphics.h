//
// Created by Admin on 17.02.2021.
//

#ifndef SDL2_BASIC_SETUP_GRAPHICS_H
#define SDL2_BASIC_SETUP_GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

constexpr size_t win_width = 1080;
constexpr size_t win_height = 720;

class Graphics {
private:

    SDL_Window *win;
    SDL_Surface *image;
    TTF_Font *font;
public:
    struct RGB{
        size_t red;
        size_t green;
        size_t blue;
    };
    RGB     rgb_color;
    int		clearImg();
    int		imgPutPixel(size_t x, size_t y, size_t color);
    void	render_text(std::string str);
    void    update();
    size_t	map_rgb(size_t red, size_t green, size_t blue);

    Graphics(size_t width, size_t height);
    ~Graphics();
};


#endif //SDL2_BASIC_SETUP_GRAPHICS_H
