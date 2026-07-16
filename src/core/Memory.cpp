#include "Memory.h"

#include <fstream>
#include <iostream>
#include <filesystem>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Memory::Memory(const std::string &filename) : filename(filename) {}

void Memory::save(
  const std::vector<Message> &history
) 
{
  
  
    std::filesystem::path path(filename);


    std::filesystem::create_directories(
        path.parent_path()
    );


  json data;

  data["messages"] = json::array();

  for (const auto &msg : history) {

    data["messages"].push_back({{"role", msg.role},

                                {"content", msg.content}});
  }
  

  //std::ofstream file(filename); !!!!
  
  std::ofstream file(
    filename,
    std::ios::out | std::ios::trunc
);


if(!file.is_open())
{
    std::cout
        << "Cannot open: "
        << filename
        << "\n";
}


  file << data.dump(4);
}

std::vector<Message> Memory::load() {

  std::vector<Message> history;

  std::ifstream file(filename);

  if (!file) {
    return history;
  }

  json data;

  file >> data;

  for (auto &msg : data["messages"]) {

    history.push_back({msg["role"], msg["content"]});
  }

  return history;
}
