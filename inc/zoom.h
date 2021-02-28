//
// Created by Admin on 19.02.2021.
//

#ifndef SDL2_BASIC_SETUP_ZOOM_H
#define SDL2_BASIC_SETUP_ZOOM_H

#include "fractal.h"

double	interpolate(double start, double end, double interpolation)
{
    return (start + ((end - start) * interpolation));
}

void	apply_zoom(Fractal *m, double mouse_re, double mouse_im,
                    double min_real, double max_real, double min_im, double max_im, double zoom)
{
    double interpolation;

    interpolation = 1.0 / zoom;
    min_real = interpolate(mouse_re, min_real, interpolation);
    min_im = interpolate(mouse_im, min_im, interpolation);
    max_real = interpolate(mouse_re, max_real, interpolation);
    max_im = interpolate(mouse_im, max_im, interpolation);

    m->updateVals(min_real, max_real, min_im, max_im);
}

void	zoom(int up, int x, int y, Fractal *m)
{
    double m_re;
    double m_im;
    auto max_real = m->getMaxReal();
    auto min_real = m->getMinReal();
    auto max_im = m->getMaxIm();
    auto min_im = m->getMinIm();

    if (up)
    {
        m->setIterations(m->getIterations() * 1.1) ;
        m_re = static_cast<double>(x) / (win_width / (max_real - min_real)) + min_real;
        m_im = static_cast<double>(y) / (win_height / (max_im - min_im)) + min_im;
        apply_zoom(m, m_re, m_im, min_real, max_real, min_im, max_im, 1.3);
    }
    else if (m->getIterations() > 30)
    {
        m->setIterations(m->getIterations() / 1.1) ;
        m_re = static_cast<double>(x) / (win_width / (max_real - min_real)) + min_real;
        m_im = static_cast<double>(y) / (win_height / (max_im - min_im)) + min_im;
        apply_zoom(m, m_re, m_im, min_real, max_real, min_im, max_im, 1.3 / 2);
    }
}

#endif //SDL2_BASIC_SETUP_ZOOM_H
