#ifndef CONFIG_SERVICE_H
#define CONFIG_SERVICE_H


#include <string>
#include <map>



class ConfigService
{


private:


    std::map<std::string,std::string> settings;


    std::string configFile;




public:


    ConfigService();



    ConfigService(

        const std::string& filename

    );



    bool load();



    std::string get(

        const std::string& key

    );



    int getInt(

        const std::string& key

    );



    double getDouble(

        const std::string& key

    );



    bool set(

        const std::string& key,

        const std::string& value

    );



    bool save();



    void displayConfig();



};


#endif