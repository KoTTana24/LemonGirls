#pragma once

#include <string>

#include "Gender.h"


class Character
{

private:

    std::string name;

    Gender gender;

    int age;


public:

    Character(
        const std::string& name,
        Gender gender,
        int age
    );


    std::string getName() const;


    Gender getGender() const;


    int getAge() const;


    std::string getSystemPrompt() const;


private:

    std::string genderToString() const;

};