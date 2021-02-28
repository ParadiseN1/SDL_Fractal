//
// Created by Admin on 17.02.2021.
//
#ifndef SDL2_BASIC_SETUP_JULIA_SET_H
#define SDL2_BASIC_SETUP_JULIA_SET_H
#include "fractal.h"
#include <math.h>

class Julia : public Fractal{
    size_t n_thread;
    int max_iterations = 50;
    std::string type = "Julia";

public:
    double min_real = -2.0;
    double max_real = 1.5;
    double min_im = -1.5;
    double max_im = min_im + (max_real - min_real) * win_height / win_width;

    Julia(){
        n_thread = 1;
    }

    Julia(size_t threads){
        n_thread = threads;
    }

    std::string getType() const{
        return type;
    }
    // 1. parallel effect (performance)
    // 2. vtune, det race
    // 3. PVS Studio

    size_t getIterations() const {return max_iterations;} //
    void setIterations(size_t its){ max_iterations = its;}
    void    Draw(Graphics *gtx, double scale_real, double scale_img){
        auto before = get_current_time_fenced();
        std::vector<std::thread> threads;
        int y = 0;

        for (int i = 0; i < n_thread; ++i){
            threads.emplace_back(std::thread(&Julia::draw_slice, this, y, gtx, scale_img, scale_real));
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
        double real2;
        double img2;

        while (y < (start_y + win_height / n_thread))
        {
            while (x < win_width)
            {
                real = min_real + x * ((max_real - min_real) / win_width);
                img = max_im - y * ((max_im - min_im) / (win_height));
                while (n < max_iterations)
                {
                    real2 = real * real;
                    img2 = img * img;
                    if (real2 + img2 > 4)
                        break ;
                    img = (2 * real) * (img + scale_img);
                    real = real2 - img2 + scale_real;
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

#endif //SDL2_BASIC_SETUP_JULIA_SET_H