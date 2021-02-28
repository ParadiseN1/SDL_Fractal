//
// Created by Admin on 17.02.2021.
//
#ifndef SDL2_BASIC_SETUP_FRACTAL_H
#define SDL2_BASIC_SETUP_FRACTAL_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include <thread>
#include "graphics.h"
#include <ctime>
#include <vector>

class Fractal{
private:
    size_t threads;
    std::string type;
    size_t max_iterations;
    double min_real;
    double max_real;
    double min_im;
    double max_im;

protected:
    inline std::chrono::steady_clock::time_point get_current_time_fenced() {
        assert(std::chrono::steady_clock::is_steady &&
                       "Timer should be steady (monotonic).");
        std::atomic_thread_fence(std::memory_order_seq_cst);
        auto res_time = std::chrono::steady_clock::now();
        std::atomic_thread_fence(std::memory_order_seq_cst);
        return res_time;
    }
    template<class D>
    double to_s(const D& d)
    {
        double secs = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(d).count()) / 1000000;
        return secs;
    }

public:


    Fractal(){ threads = 1; };
    Fractal(size_t n) {threads = n;}; //delegating constructor for children
    virtual double getMinReal() const{return min_real;} //override
    virtual double getMaxReal() const{return max_real;}
    virtual double getMinIm() const{return min_im;}
    virtual double getMaxIm() const{return max_im;}
    virtual std::string getType() const{return type;};
    virtual size_t  getIterations(){return max_iterations;};
    virtual void setIterations(size_t its){ max_iterations = its;};
    virtual void Draw(Graphics *gtx, double scale_real, double scale_img){};
    virtual void updateVals(double m_re, double max_re, double m_im, double mx_im){};
    virtual ~Fractal() = default;
}; //initialization list

#endif //SDL2_BASIC_SETUP_FRACTAL_H
