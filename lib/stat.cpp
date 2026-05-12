#include "../include/stat.h"
#include <cmath>

statistics::statistics(std::vector<float> inp_data) : data(inp_data)
{
    // сума
    auto sum_ = [this]() -> void
    {
        float sum_ = 0;
        for (auto temp : data)
        {
            sum_ += temp;
        }

        sum = sum_;
    };

    // середнє квадратичне
    auto root_mean_square_ = [this]() -> void
    {
        float sum_sq = 0;
        for (auto temp : data)
        {
            sum_sq += pow(temp, 2);
        }

        root_mean_square = (float)(sqrt(sum_sq / data.size()));
    };

    // дисперсія
    auto disp_ = [this]() -> void
    {
        float ds_ = 0;
        for (auto temp : data)
        {
            ds_ += (pow(temp, 2) - pow(average, 2));
        }

        dispersion = (float)(ds_ / (data.size() - 1));
    };

    sum_();
    // середнє арифметичне
    average = sum / data.size();
    root_mean_square_();
    disp_();
    // стандартне відхилення
    deviation = sqrt(dispersion);
    // коефіцієнт варіації
    variation_co = deviation / average;
    // похибка середньої величини
    mean_error = (float)(deviation / sqrt(data.size()));
    // відносна похибка середньої величини
    relative_mean_error = mean_error / average;
}