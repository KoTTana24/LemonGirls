#include <gtest/gtest.h>

#include "core/CharacterManager.h"

TEST(CharacterManagerTest, CreateCharacter)
{
    CharacterManager manager;

    auto alice =
        manager.createCharacter(
            "Alice",
            Gender::Female,
            20
        );

    EXPECT_EQ(
        alice.getName(),
        "Alice"
    );
}
