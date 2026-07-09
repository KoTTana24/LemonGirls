#include <iostream>

#include "core/ChatManager.h"



int main()
{

    ChatManager manager;


    Character alice(
        "Alice",
        Gender::Female,
        18
    );


    Character bob(
        "Bob",
        Gender::Male,
        30
    );


    manager.addChat(alice);
    manager.addChat(bob);



    while(true)
    {

        manager.showChats();


        std::cout
            << "\nChoose chat: ";


        int choice;

        std::cin >> choice;


        std::cin.ignore();



        if(choice == 0)
        {
            break;
        }



        if(!manager.selectChat(choice))
        {
            std::cout
                << "Wrong choice\n";

            continue;
        }



        Chat* chat =
            manager.getCurrentChat();



        std::string text;


        while(true)
        {

            std::cout
                << "\n"
                << "You"
                << ": ";


            getline(
                std::cin,
                text
            );


            if(text == "exit")
            {
                break;
            }


            std::cout
                << chat->getCharacter().getName()
                << ": "
                << chat->send(text)
                << "\n";

        }

    }



    return 0;
}