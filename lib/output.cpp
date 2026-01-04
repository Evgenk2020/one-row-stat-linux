#include "../include/output.h"
#include <iostream>
#include <fstream>
#include <locale>

#include <format>
#include <print>
#include <ranges>
#include <filesystem>

general_info::~general_info() {}

void help_info::see_info()
{
    std::cout << "*** Статистична обробка послідовного ряду ***" << std::endl
              << std::endl
              << "Для виводу в термінал:" << std::endl
              << "-d [перше число] [друге число] ... [наступне число]" << std::endl
              << std::endl
              << "Для виводу в файл:" << std::endl
              << "-df [перше число] [друге число] ... [наступне число]" << std::endl
              << std::endl
              << "Для довідки:" << std::endl
              << "-h | --help" << std::endl
              << std::endl
              << "Для додаткової інформації:" << std::endl
              << "-i" << std::endl;
}

void inf_info::see_info()
{
    std::cout << "Утиліта визначає показники первинних статистичних даних:" << std::endl
              << std::endl
              << "- Середнє арифметичне - число, що дорівнює сумі всіх чисел послідовності, поділеної на їх кількість" << std::endl
              << "  Є однією з мір центральної тенденції" << std::endl
              << std::endl
              << "- Середнє квадратичне - число, що дорівнює квадратному кореню з середнього арифметичного" << std::endl
              << "  квадратів чисел послідовності" << std::endl
              << std::endl
              << "- Дисперсія випадкової величини - міра розподілу значень випадкової величини" << std::endl
              << "  відносно її математичного очікування" << std::endl
              << std::endl
              << "- Середнє квадратичне відхилення - найбільш поширений показник розсіювання," << std::endl
              << "  дорівнює квадратному кореню з дисперсії. Середнє квадратичне відхилення можна вважати мірою невизначеності" << std::endl
              << std::endl
              << "- Коефіцієнт варіації - це міра відносного розподілу випадкової величиин" << std::endl
              << std::endl
              << "- Стандартна похибка середнього - величина, яка характеризує стандартне відхилення" << std::endl
              << "  вибіркового середнього, розрахована по виборці n із генеральної сукупності (+-)" << std::endl
              << std::endl
              << "- Відносна похибка середньої величини - стандартна похибка середньої" << std::endl;
}

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(const statistics &stat)
{

    std::cout << "Послідовність: ";
    for (auto data : stat.data)
    {
        std::cout << data << ' ';
    }
    std::cout << std::endl;

    std::cout << "Число елементів: " << stat.data.size() << std::endl;
    std::cout << "Сума чисел: " << stat.sum << std::endl;
    std::cout << "Середнє арифметичне: " << stat.average << std::endl;
    std::cout << "Середнє квадратичне: " << stat.root_mean_square << std::endl;
    std::cout << "Дисперсія: " << stat.dispersion << std::endl;
    std::cout << "Стандартне відхилення: " << stat.deviation << std::endl;
    std::cout << "Коефіцієнт варіації: " << stat.variation_co << std::endl;
    std::cout << "Похибка середньої величини: " << stat.mean_error << std::endl;
    std::cout << "Відносна похибка середньої величини: " << stat.relative_mean_error << std::endl;
}

void file_info::see_info(const statistics &stat)
{
    namespace fs = std::filesystem;
    namespace rv = std::ranges::views;

    const fs::path file{"one-rstat.csv"};
    std::ofstream out(file, std::ios::app);

    out.imbue(std::locale{"uk_UA.utf8"});

    auto csv = [&out](std::string_view key, auto &&value)
    {
        out << std::format("\"{}\",\"{}\"\n", key, value);
    };

    // Послідовність
    out << "\"Послідовність:\",";

    auto quoted = stat.data | rv::transform([](const auto &v)
                                            { return std::format("\"{}\"", v); });

    out << std::format("{}\n", std::ranges::to<std::string>(quoted | rv::join_with(',')));

    // Статистика
    csv("Число елементів:", stat.data.size());
    csv("Сума чисел:", stat.sum);
    csv("Середнє арифметичне:", stat.average);
    csv("Середнє квадратичне:", stat.root_mean_square);
    csv("Дисперсія:", stat.dispersion);
    csv("Стандартне відхилення:", stat.deviation);
    csv("Коефіцієнт варіації:", stat.variation_co);
    csv("Похибка середньої величини:", stat.mean_error);
    csv("Відносна похибка середньої величини:", stat.relative_mean_error);

    out << '\n';

    std::print("Дані додані у файл {}\n", file.string());
}

//--------------------------------------------------

print_info::print_info(general_info *temp) : g_info(temp) {}
print_info::print_info(data_info *temp) : d_info(temp) {}

void print_info::_print() { g_info->see_info(); }
void print_info::_print(statistics stat) { d_info->see_info(stat); }

print_info::~print_info()
{
    delete g_info;
    g_info = nullptr;

    delete d_info;
    d_info = nullptr;
}
