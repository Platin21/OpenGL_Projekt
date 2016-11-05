#include "pb_file.hpp"

/*
classic File Reading Libaray Because the C++
fstream thing is kinda hard to use
*/

namespace PB{

    fs file_open(str name, fsm open)
    {
        fs file;
        if(open == fsm::read) fopen_s(&file,name.c_str(),"r");
        else if (open == fsm::write) fopen_s(&file,name.c_str(), "w");
        else if (open == fsm::read_bin) fopen_s(&file,name.c_str(), "rb");
        else if (open == fsm::write_bin) fopen_s(&file,name.c_str(), "wb");
        else file = NULL;
        ret file;
    }

    void basic_file_write(fs file, str txt)
    {
        if (file != NULL)
        {
            fprintf_s(file, "%s", txt.c_str());
        }
    }

    str basic_file_read(fs file)
    {
        if(!file)
        {
          PA::global::Error = PA::global::Reason::File_Does_Not_Exist;
          PA::global::error_exc();
        }

        i32 size;
        fseek(file, 0, SEEK_SET);
        fseek(file,0, SEEK_END);
        size = ftell(file) -1 ;
        str content;
        c8 bf = ' ';
        rewind(file);

        while ((bf = fgetc(file)) != EOF)
        {
            content.push_back(bf);
        }

        ret content;
    }
}
