#include "ChatManager.h"

#include <iostream>

ChatManager::ChatManager() : currentChat(-1) {}

void ChatManager::loadFromCharacters(CharacterManager &manager) {

  chats.clear();

  for (const auto &character : manager.getCharacters()) {

    chats.push_back(std::make_unique<Chat>(character));
  }
}

void ChatManager::showChats() {

  std::cout << "\n====== AI Companion ======\n";

  for (size_t i = 0; i < chats.size(); i++) {

    std::cout << i + 1 << ". " << chats[i]->getCharacter().getName() << "\n";
  }

  std::cout << "0. Exit\n";
}

bool ChatManager::selectChat(int index) {

  if (index < 1 || index > chats.size()) {
    return false;
  }

  currentChat = index - 1;

  return true;
}

Chat *ChatManager::getCurrentChat() {

  if (currentChat < 0) {
    return nullptr;
  }

  return chats[currentChat].get();
}
