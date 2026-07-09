#pragma once

#include <string>
#include <vector>

#include "Message.h"



class Memory
{

private:

    std::string filename;


public:

    Memory(
        const std::string& filename
    );


    void save(
        const std::vector<Message>& history
    );


    std::vector<Message> load();

};