#include "../include/proc.h"
#include <regex>

processing::~processing() {}

void processing::going()
{
    if (_inp_var.size() == 1)
    {
        this->helping();
    }

    if (_inp_var.size() > 1)
    {
        this->converting();
        this->counting();
    }
}

decree::~decree() {}
decree::decree(inp_var _inp) { _inp_var = _inp; }

void decree::helping()
{
    if (_inp_var.at(1) == _keys.k_help_one || _inp_var.at(1) == _keys.k_help_two)
    {
        print_info inf(new help_info);
        inf._print();
    }

    else if (_inp_var.at(1) == _keys.k_info)
    {
        print_info inf(new inf_info);
        inf._print();
    }

    else
    {
        std::cout << "error... use -h or --help for details" << std::endl;
    }
}

void decree::converting()
{
    if (_inp_var.size() > 2)
    {
        for (auto it = _inp_var.find(2); it != _inp_var.end(); it++)
        {
            try
            {
                data.push_back(stof(it->second));
            }

            catch (const std::exception &e)
            {
                std::cout << "error.. use correct data values" << std::endl;
                exit(1);
            }
        }
    }

    else
    {
        std::cout << "error.. the number of data can not be less than two " << std::endl;
    }
}

void decree::counting()
{
    if (_inp_var.at(1) == _keys.k_data)
    {
        print_info inf(new screen_info);
        inf._print(data);
    }

    else if (_inp_var.at(1) == _keys.k_file)
    {
        print_info inf(new file_info);
        inf._print(data);
    }

    else
    {
        std::cout << "incorrect key.. use [-d | -df] keys for results" << std::endl;
    }
}