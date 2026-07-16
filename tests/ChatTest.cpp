#include <gtest/gtest.h>

#include "core/Chat.h"
#include "core/Character.h"


TEST(ChatTest, CreateChat)
{

    Character alice(
        "char_test",
        "Alice",
        Gender::Female,
        22
    );


    Chat chat(alice);



    EXPECT_EQ(
        chat.getCharacter().getName(),
        "Alice"
    );

}
