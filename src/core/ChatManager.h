#pragma once

#include <memory>
#include <vector>

#include "CharacterManager.h"
#include "Chat.h"

class ChatManager {

private:
  std::vector<std::unique_ptr<Chat>> chats;

  int currentChat;

public:
  ChatManager();

  void loadFromCharacters(CharacterManager &manager);

  void showChats();

  bool selectChat(int index);

  Chat *getCurrentChat();
};
