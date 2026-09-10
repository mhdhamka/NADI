#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>


class Category
{

private:

    std::string categoryID;

    std::string name;

    std::string description;


    // Support parent-child category
    std::string parentCategoryID;


    bool active;


public:


    Category();


    Category(
        const std::string& categoryID,
        const std::string& name,
        const std::string& description,
        const std::string& parentCategoryID = ""
    );



    // Getters

    std::string getCategoryID() const;

    std::string getName() const;

    std::string getDescription() const;

    std::string getParentCategoryID() const;

    bool isActive() const;



    // Setters

    void setName(
        const std::string& name
    );


    void setDescription(
        const std::string& description
    );


    void activate();


    void deactivate();



    bool isSubCategory() const;



    void displayCategory() const;


};


#endif