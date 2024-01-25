#include "../include/stat.h"
#include <cmath>

statistics::statistics(std::vector<float> inp_data) : data(inp_data)
{
    // сумма
    auto sum_ = [this]()
    {
        float sum_ = 0;
        for (auto temp : data)
        {
            sum_ += temp;
        }

        return sum_;
    };

    sum = sum_();

    // среднее арифметическое
    average = sum / data.size();

    // среднее квадратическое
    auto root_mean_square_ = [this]()
    {
        float sum_sq = 0;
        for (auto temp : data)
        {
            sum_sq += pow(temp, 2);
        }

        return (float)(sqrt(sum_sq / data.size()));
    };

    root_mean_square = root_mean_square_();

    // дисперсия
    auto disp_ = [this]()
    {
        float ds_ = 0;
        for (auto temp : data)
        {
            ds_ += (pow(temp, 2) - pow(average, 2));
        }

        return (float)(ds_ / (data.size() - 1));
    };
    
    dispersion = disp_();

    // стандартное отклонение
    deviation = sqrt(dispersion);

    // коэффициент вариации
    variation_co = deviation / average;

    // ошибка средней величины
    mean_error = (float)(deviation / sqrt(data.size()));

    // относительная ошибка средней величины
    relative_mean_error = mean_error / average;
}