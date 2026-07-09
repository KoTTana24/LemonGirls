#pragma once

#include <vector>
#include <string>

#include "Character.h"
#include "Message.h"
#include "OllamaClient.h"
#include "Memory.h"



class Chat
{

private:

    Character character;

    OllamaClient client;

    Memory memory;

    std::vector<Message> history;


public:

    Chat(
        const Character& character
    );


    std::string send(
        const std::string& message
    );


    const Character& getCharacter() const;


};