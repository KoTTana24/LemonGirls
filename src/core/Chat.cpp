#include "Chat.h"
#include <filesystem>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Chat::Chat(
    const Character& character
)
:
character(character),
memory(
    "data/chats/" +
    character.getId() +
    ".json"
)
{

    auto savedHistory = memory.load();


    if(!savedHistory.empty())
    {
        history = savedHistory;
    }
    else
    {
        history.push_back(
        {
            "system",
            character.getSystemPrompt()
        });
    }

}

std::string Chat::send(const std::string &message) {

  history.push_back({"user", message});

  std::string response = client.chat(history);

  try {

    json result = json::parse(response);

    std::string answer = result["message"]["content"];

    history.push_back({"assistant", answer});

    memory.save(history);
    
    //memory.save(history);

    return answer;

  }

  catch (const std::exception &e) {

    return "Error parsing AI response: " + std::string(e.what());
  }
}

const Character &Chat::getCharacter() const { return character; }
