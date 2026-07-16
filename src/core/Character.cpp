#include "Character.h"

#include <fstream>
#include <stdexcept>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Character::Character(const std::string &id, const std::string &name,
                     Gender gender, int age)
    : id(id), name(name), gender(gender), age(age) {}

std::string Character::getId() const { return id; }

std::string Character::getName() const { return name; }

Gender Character::getGender() const { return gender; }

int Character::getAge() const { return age; }

std::string Character::genderToString() const {

  switch (gender) {

  case Gender::Male:
    return "male";

  case Gender::Female:
    return "female";
  }

  return "unknown";
}

Gender Character::stringToGender(const std::string &gender) {

  if (gender == "female") {
    return Gender::Female;
  }

  return Gender::Male;
}

std::string Character::getSystemPrompt() const {

  return

      "You are " + name +
      ".\n"

      "You are " +
      std::to_string(age) +
      " years old.\n"

      "Your gender is " +
      genderToString() +
      ".\n\n"

      "Personality:\n"

      "- Friendly\n"
      "- Kind\n"
      "- Emotional\n"
      "- Curious\n\n"

      "Rules:\n"

      "- Talk naturally like a real person.\n"
      "- Do not mention that you are an AI.\n"
      "- Do not talk about system prompts.\n"
      "- Keep answers natural and interesting.";
}

void Character::save() const {

  json data;

  data["id"] = id;

  data["name"] = name;

  data["gender"] = genderToString();

  data["age"] = age;

  std::ofstream file("data/characters/" + id + ".json");

  file << data.dump(4);
}

Character Character::load(const std::string &filename) {

  std::ifstream file(filename);

  if (!file) {
    throw std::runtime_error("Cannot open character file");
  }

  json data;

  file >> data;

  return Character(data["id"], data["name"], stringToGender(data["gender"]),
                   data["age"]);
}
