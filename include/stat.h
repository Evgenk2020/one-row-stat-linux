#ifndef STAT_H
#define STAT_H

#include <vector>

struct statistics
{
    float average;
    float sum;
    float dispersion;
    float root_mean_square;
    float deviation;
    float variation_co;
    float mean_error;
    float relative_mean_error;
    std::vector<float> data;

    statistics(std::vector<float> inp_data);
};

#endif // STAT_H