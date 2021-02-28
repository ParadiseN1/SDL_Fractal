//
// Created by Admin on 19.02.2021.
//
// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#ifndef SDL2_BASIC_SETUP_MANDELBROT_H
#define SDL2_BASIC_SETUP_MANDELBROT_H
#include "fractal.h"
#include <math.h>

class Mandelbrot : public Fractal{
    size_t n_thread;
    int max_iterations = 50;
    std::string type = "Mandelbrot";
    double min_real = -2.0;
    double max_real = 1.5;
    double min_im = -1.5;
    double max_im = min_im + (max_real - min_real) * win_height / win_width;
public:

    Mandelbrot(){
        n_thread = 1;
    }
    Mandelbrot(size_t threads){
        n_thread = threads;
    }

    std::string getType() const{
        return type;
    }

    double getMinReal() const{
        return min_real;
    }
    double getMaxReal() const{
        return max_real;
    }
    double getMinIm() const{
            return min_im;
    }
    double getMaxIm() const{
        return max_im;
    }
    void updateVals(double m_re, double max_re, double m_im, double mx_im){
        min_real = m_re;
        max_real = max_re;
        min_im = m_im;
        max_im = mx_im;
    }


    size_t getIterations(){return max_iterations;}
    void setIterations(size_t its){ max_iterations = its;}
    void    Draw(Graphics *gtx, double scale_real, double scale_img){
        auto before = get_current_time_fenced();
        std::vector<std::thread> threads;
        int y = 0;

        for (int i = 0; i < n_thread; ++i){
            threads.emplace_back(std::thread(&Mandelbrot::draw_slice, this, y, gtx, scale_img, scale_real));
            y += win_height / n_thread;
        }
        for (auto& th: threads) {
            th.join();
        }
        gtx->update();
        auto time_to_calculate = get_current_time_fenced() - before;
        std::cout << "Type:" << getType() << "\nThreads:" << n_thread << "\nTime:" << to_s(time_to_calculate) << std::endl;
    }

private:
    void	draw_slice(int start_y, Graphics *gtx, double scale_img, double scale_real){
        int x = 0;
        int n = 0;
        int y = start_y;
        double real;
        double img;

        while (y < (start_y + win_height / n_thread))
        {
            img = max_im - y * ((max_im - min_im) / (win_height - 1));
            while (x < win_width)
            {
                real = min_real + x * ((max_real - min_real) / (win_width - 1));
                double c_real = real;
                double c_img = img;
                while (n < max_iterations)
                {
                    double real2 = c_real * c_real;
                    double img2 = c_img * c_img;
                    if (real2 + img2 > 4)
                        break ;
                    c_img = 2.0 * c_real * c_img + img;
                    c_real = real2 - img2 + real;
                    ++n;
                }
                if (n < max_iterations)
                    gtx->imgPutPixel(x, y, gtx->map_rgb(gtx->rgb_color.red * ((double)n / max_iterations),
                                                        gtx->rgb_color.green * ((double)n / max_iterations),
                                                        gtx->rgb_color.blue * ((double)n / max_iterations)));
                else
                    gtx->imgPutPixel(x, y, gtx->map_rgb(0, 0, 0));
                ++x;
                n = 0;
            }
            x = 0;
            ++y;
        }
    }
};
#endif //SDL2_BASIC_SETUP_MANDELBROT_H
