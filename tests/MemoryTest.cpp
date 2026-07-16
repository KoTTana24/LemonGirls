#include <gtest/gtest.h>

#include "core/Memory.h"
#include "core/Message.h"



TEST(MemoryTest, SaveAndLoad)
{

    Memory memory(
        "test_data/chat.json"
    );


    std::vector<Message> history =
    {
        {
            "user",
            "Hello"
        },

        {
            "assistant",
            "Hi!"
        }
    };


    memory.save(history);



    auto loaded =
        memory.load();



    ASSERT_EQ(
        loaded.size(),
        2
    );


    EXPECT_EQ(
        loaded[0].role,
        "user"
    );


    EXPECT_EQ(
        loaded[0].content,
        "Hello"
    );


    EXPECT_EQ(
        loaded[1].content,
        "Hi!"
    );

}
