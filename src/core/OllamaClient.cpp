#include "OllamaClient.h"

#include <iostream>

#include <curl/curl.h>

#include <nlohmann/json.hpp>


using json = nlohmann::json;



size_t WriteCallback(
    void* contents,
    size_t size,
    size_t nmemb,
    std::string* output
)
{
    size_t total = size * nmemb;


    output->append(
        reinterpret_cast<char*>(contents),
        total
    );


    return total;
}



OllamaClient::OllamaClient(
    const std::string& model
)
:
model(model)
{

}



std::string OllamaClient::chat(
    const std::vector<Message>& history
)
{

    CURL* curl = curl_easy_init();


    if(!curl)
    {
        return "Curl initialization error";
    }



    std::string response;



    json request;


    request["model"] = model;

    request["stream"] = false;


    request["think"] = false;



    request["options"] =
    {
        {
            "num_ctx",
            2048
        },

        {
            "num_predict",
            100
        },

        {
            "temperature",
            0.7
        }
    };



    request["messages"] = json::array();



    int start = 0;


    if(history.size() > 10)
    {
        start = history.size() - 10;
    }



    for(int i = start; i < history.size(); i++)
    {

        request["messages"].push_back(
        {
            {
                "role",
                history[i].role
            },

            {
                "content",
                history[i].content
            }
        });

    }



    std::string body =
        request.dump();



    curl_easy_setopt(
        curl,
        CURLOPT_URL,
        "http://localhost:11434/api/chat"
    );


    curl_easy_setopt(
        curl,
        CURLOPT_POST,
        1L
    );


    curl_easy_setopt(
        curl,
        CURLOPT_POSTFIELDS,
        body.c_str()
    );


    curl_easy_setopt(
        curl,
        CURLOPT_POSTFIELDSIZE,
        body.size()
    );



    curl_slist* headers = nullptr;


    headers =
        curl_slist_append(
            headers,
            "Content-Type: application/json"
        );


    curl_easy_setopt(
        curl,
        CURLOPT_HTTPHEADER,
        headers
    );



    curl_easy_setopt(
        curl,
        CURLOPT_WRITEFUNCTION,
        WriteCallback
    );


    curl_easy_setopt(
        curl,
        CURLOPT_WRITEDATA,
        &response
    );



    CURLcode result =
        curl_easy_perform(curl);



    if(result != CURLE_OK)
    {

        std::cerr
            << "Curl error: "
            << curl_easy_strerror(result)
            << "\n";

    }



    curl_slist_free_all(headers);

    curl_easy_cleanup(curl);



    return response;

}