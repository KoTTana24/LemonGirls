#include <gtest/gtest.h>

#include "core/Character.h"


TEST(CharacterTest, CreateCharacter)
{

    Character alice(
        "char_1",
        "Alice",
        Gender::Female,
        20
    );


    Character alex(
        "char_2",
        "Alex",
        Gender::Male,
        35
    );



    EXPECT_EQ(
        alice.getId(),
        "char_1"
    );


    EXPECT_EQ(
        alice.getName(),
        "Alice"
    );


    EXPECT_EQ(
        alice.getAge(),
        20
    );



    EXPECT_EQ(
        alex.getId(),
        "char_2"
    );


    EXPECT_EQ(
        alex.getName(),
        "Alex"
    );


    EXPECT_EQ(
        alex.getAge(),
        35
    );

}
