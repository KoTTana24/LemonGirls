#pragma once

#include <string>
#include <vector>

#include "Character.h"

class CharacterManager {

private:
  std::vector<Character> characters;

  std::string charactersPath;

  std::string generateId();

public:
  CharacterManager(const std::string &path = "data/characters/");

  void loadCharacters();

  Character createCharacter(const std::string &name, Gender gender, int age);

  const std::vector<Character> &getCharacters() const;

  Character *getCharacter(const std::string &id);
};
