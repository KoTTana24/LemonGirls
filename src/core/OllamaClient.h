#pragma once

#include <string>
#include <vector>

#include "Message.h"


class OllamaClient
{

private:

    std::string model;


public:

    OllamaClient(
        const std::string& model = "qwen3.5:4b"
    );


    std::string chat(
        const std::vector<Message>& history
    );

};