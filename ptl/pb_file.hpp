#pragma once
#include "pb_types.hpp"

namespace PB {

    //Read / Write Mode of File
    enum fsm
    {
        read,
        write,
        read_bin,
        write_bin
    };

    fs file_open(str name, fsm open);

    //Basic File Functions
    void basic_file_write(fs file, str txt);
    str basic_file_read(fs file);
}
