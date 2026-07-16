#include "CharacterManager.h"

#include <filesystem>

#include <iostream>

namespace fs = std::filesystem;

CharacterManager::CharacterManager(const std::string &path)
    : charactersPath(path) {}

std::string CharacterManager::generateId()
{

    int number = 1;


    while(true)
    {

        std::string id =
            "char_"
            + std::to_string(number);



        bool exists = false;


        for(const auto& character : characters)
        {

            if(character.getId() == id)
            {
                exists = true;
                break;
            }

        }



        if(!exists)
        {
            return id;
        }


        number++;

    }

}


void CharacterManager::loadCharacters() {

  characters.clear();

  if (!fs::exists(charactersPath)) {
    fs::create_directories(charactersPath);

    return;
  }

  for (const auto &entry : fs::directory_iterator(charactersPath)) {

    if (entry.path().extension() == ".json") {

      try {

        characters.push_back(Character::load(entry.path()));

      }

      catch (...) {

        std::cout << "Failed loading: " << entry.path() << "\n";
      }
    }
  }
}

Character CharacterManager::createCharacter(const std::string &name,
                                            Gender gender, int age) {

  std::string id =
    generateId();

  Character character(id, name, gender, age);

  character.save();

  characters.push_back(character);

  return character;
}

const std::vector<Character> &CharacterManager::getCharacters() const {
  return characters;
}

Character *CharacterManager::getCharacter(const std::string &id) {

  for (auto &character : characters) {

    if (character.getId() == id) {
      return &character;
    }
  }

  return nullptr;
}
