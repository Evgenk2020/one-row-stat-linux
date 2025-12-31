#include "../include/proc.h"
#include <charconv>
#include <iostream>

void processing::going()
{
    if (_inp_var.size() == 1)
    {
        helping();
        return;
    }
    if (_inp_var.size() > 1)
    {
        converting();
        counting();
    }
}

decree::decree(inp_var inp)
{
    _inp_var = std::move(inp);
}

void decree::helping()
{
    const auto &key = _inp_var.at(1);

    if (key == keys::k_help_one || key == keys::k_help_two)
    {
        print_info{new help_info}._print();
    }
    else if (key == keys::k_info)
    {
        print_info{new inf_info}._print();
    }
    else
    {
        std::cout << "error... use -h or --help for details\n";
    }
}

void decree::converting()
{
    if (_inp_var.size() < 3)
    {
        std::cout << "error.. the number of data can not be less than two\n";
        return;
    }

    for (auto it = std::next(_inp_var.begin()); it != _inp_var.end(); ++it)
    {
        if (it->first < 2)
        {
            continue;
        }

        float value{};
        const auto &str = it->second;

        const auto [ptr, ec] =
            std::from_chars(str.data(), str.data() + str.size(), value);

        if (ec != std::errc{})
        {
            std::cout << "error.. use correct data values\n";
            data.clear();
            return;
        }

        data.push_back(value);
    }
}

void decree::counting()
{
    const auto &key = _inp_var.at(1);

    if (key == keys::k_data)
    {
        print_info{new screen_info}._print(data);
    }
    else if (key == keys::k_file)
    {
        print_info{new file_info}._print(data);
    }
    else
    {
        std::cout << "incorrect key.. use [-d | -df] keys for results\n";
    }
}
