#include "services/ConfigService.h"


#include <fstream>
#include <iostream>
#include <sstream>



using namespace std;




ConfigService::ConfigService()

{

    configFile="config/config.ini";

}



ConfigService::ConfigService(

    const string& filename

)

{

    configFile=filename;

}







bool ConfigService::load()

{

    ifstream file(configFile);



    if(!file)

        return false;



    string line;



    while(getline(file,line))

    {


        if(line.empty())

            continue;



        if(line[0]=='[')

            continue;



        size_t position =

        line.find('=');



        if(position != string::npos)

        {


            string key =

            line.substr(0,position);



            string value =

            line.substr(position+1);



            settings[key]=value;

        }

    }



    file.close();



    return true;

}







string ConfigService::get(

    const string& key

)

{

    if(settings.find(key)

        != settings.end())

    {

        return settings[key];

    }



    return "";

}







int ConfigService::getInt(

    const string& key

)

{

    return stoi(get(key));

}







double ConfigService::getDouble(

    const string& key

)

{

    return stod(get(key));

}







bool ConfigService::set(

    const string& key,

    const string& value

)

{

    settings[key]=value;


    return save();

}







bool ConfigService::save()

{

    ofstream file(configFile);



    if(!file)

        return false;



    for(auto& item : settings)

    {

        file

        << item.first

        << "="

        << item.second

        << endl;

    }



    file.close();



    return true;

}







void ConfigService::displayConfig()

{

    cout

    << "\n====== SYSTEM CONFIG ======\n";



    for(auto& item:settings)

    {

        cout

        << item.first

        << " = "

        << item.second

        << endl;

    }

}