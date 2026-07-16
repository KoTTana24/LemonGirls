#include <iostream>

#include "core/CharacterManager.h"
#include "core/ChatManager.h"

int main() {

  CharacterManager characterManager;

  characterManager.loadCharacters();

  if (characterManager.getCharacters().empty()) {

    characterManager.createCharacter("Alice", Gender::Female, 18);

    characterManager.createCharacter("Bob", Gender::Male, 25);
  }

  ChatManager chatManager;

  chatManager.loadFromCharacters(characterManager);

  while (true) {

    chatManager.showChats();

    std::cout << "\nChoose chat: ";

    int choice;

    std::cin >> choice;

    std::cin.ignore();

    if (choice == 0) {
      break;
    }

    if (!chatManager.selectChat(choice)) {
      std::cout << "Wrong choice\n";

      continue;
    }

    Chat *chat = chatManager.getCurrentChat();

    while (true) {

      std::string text;

      std::cout << "\n" << "You" << ": ";

      getline(std::cin, text);

      if (text == "exit") {
        break;
      }

      std::cout << "\n"
                << chat->getCharacter().getName() << ": " << chat->send(text)
                << "\n";
    }
  }

  return 0;
}
