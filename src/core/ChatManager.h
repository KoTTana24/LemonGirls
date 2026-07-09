#pragma once

#include <vector>
#include <memory>

#include "Chat.h"



class ChatManager
{

private:

    std::vector<std::unique_ptr<Chat>> chats;

    int currentChat;


public:

    ChatManager();


    void addChat(
        const Character& character
    );


    void showChats();


    bool selectChat(
        int index
    );


    Chat* getCurrentChat();


};