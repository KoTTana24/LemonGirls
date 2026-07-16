#pragma once

#include <string>

#include "Gender.h"

class Character {

private:
  std::string id;

  std::string name;

  Gender gender;

  unsigned int age;

public:
  Character(const std::string &id, const std::string &name, Gender gender,
            int age);

  std::string getId() const;

  std::string getName() const;

  Gender getGender() const;

  int getAge() const;

  std::string getSystemPrompt() const;

  void save() const;

  static Character load(const std::string &filename);

private:
  std::string genderToString() const;

  static Gender stringToGender(const std::string &gender);
};
