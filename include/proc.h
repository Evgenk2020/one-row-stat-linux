#ifndef PROC_H
#define PROC_H

#include "../include/output.h"
#include <map>
#include <string>
#include <string_view>
#include <vector>

using inp_var = std::map<int, std::string>;

struct keys
{
    static constexpr std::string_view k_help_one{"-h"};
    static constexpr std::string_view k_help_two{"--help"};
    static constexpr std::string_view k_info{"-i"};
    static constexpr std::string_view k_data{"-d"};
    static constexpr std::string_view k_file{"-df"};
};

class processing
{
protected:
    inp_var _inp_var;

    virtual void helping() = 0;
    virtual void converting() = 0;
    virtual void counting() = 0;

public:
    virtual ~processing() = default;
    void going();
};

class decree final : public processing
{
private:
    std::vector<float> data;

public:
    explicit decree(inp_var inp);
    ~decree() override = default;

    void helping() override;
    void converting() override;
    void counting() override;
};

#endif // PROC_H
