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
    std::println(
        "*** Статистична обробка послідовного ряду ***\n"
        "\n"
        "Для виводу в термінал:\n"
        "-d [перше число] [друге число] ... [наступне число]\n"
        "\n"
        "Для виводу в файл:\n"
        "-df [перше число] [друге число] ... [наступне число]\n"
        "\n"
        "Для довідки:\n"
        "-h | --help\n"
        "\n"
        "Для додаткової інформації:\n"
        "-i");
}

void inf_info::see_info()
{
    std::println(
        "Утиліта визначає показники первинних статистичних даних:\n"
        "\n"
        "- Середнє арифметичне - число, що дорівнює сумі всіх чисел послідовності, поділеної на їх кількість\n"
        "  Є однією з мір центральної тенденції\n"
        "\n"
        "- Середнє квадратичне - число, що дорівнює квадратному кореню з середнього арифметичного\n"
        "  квадратів чисел послідовності\n"
        "\n"
        "- Дисперсія випадкової величини - міра розподілу значень випадкової величини\n"
        "  відносно її математичного очікування\n"
        "\n"
        "- Середнє квадратичне відхилення - найбільш поширений показник розсіювання,\n"
        "  дорівнює квадратному кореню з дисперсії. Середнє квадратичне відхилення можна вважати мірою невизначеності\n"
        "\n"
        "- Коефіцієнт варіації - це міра відносного розподілу випадкової величиин\n"
        "\n"
        "- Стандартна похибка середнього - величина, яка характеризує стандартне відхилення\n"
        "  вибіркового середнього, розрахована по виборці n із генеральної сукупності (+-)\n"
        "\n"
        "- Відносна похибка середньої величини - стандартна похибка середньої");
}

//--------------------------------------------------

data_info::~data_info() {}

void screen_info::see_info(const statistics &stat)
{
    std::print("Послідовність: ");

    bool first = true;
    for (const auto &v : stat.data)
    {
        std::print("{}{}", first ? "" : " ", v);
        first = false;
    }
    std::print("\n");

    auto line = [](std::string_view label, const auto &value) -> void
    {
        std::print("{} {}\n", label, value);
    };

    line("Число елементів:", stat.data.size());
    line("Сума чисел:", stat.sum);
    line("Середнє арифметичне:", stat.average);
    line("Середнє квадратичне:", stat.root_mean_square);
    line("Дисперсія:", stat.dispersion);
    line("Стандартне відхилення:", stat.deviation);
    line("Коефіцієнт варіації:", stat.variation_co);
    line("Похибка середньої величини:", stat.mean_error);
    line("Відносна похибка середньої величини:", stat.relative_mean_error);
}

void file_info::see_info(const statistics &stat)
{
    namespace file_system = std::filesystem;
    namespace range_views = std::ranges::views;

    const file_system::path file{"one-rstat.csv"};
    std::ofstream out(file, std::ios::app);

    out.imbue(std::locale{"uk_UA.utf8"});

    auto csv = [&out](std::string_view key, auto &&value) -> void
    {
        out << std::format("\"{}\",\"{}\"\n", key, value);
    };

    // Послідовність
    out << "\"Послідовність:\",";
    auto quoted = stat.data | range_views::transform([](const auto &v) { return std::format("\"{}\"", v); });
    out << std::format("{}\n", std::ranges::to<std::string>(quoted | range_views::join_with(',')));

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
