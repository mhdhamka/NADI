#include "models/Category.h"

#include <iostream>


using namespace std;



Category::Category()
{

    categoryID = "";

    name = "";

    description = "";

    parentCategoryID = "";

    active = true;

}



Category::Category(
    const string& categoryID,
    const string& name,
    const string& description,
    const string& parentCategoryID
)

{

    this->categoryID = categoryID;

    this->name = name;

    this->description = description;

    this->parentCategoryID = parentCategoryID;


    active = true;

}




string Category::getCategoryID() const
{
    return categoryID;
}



string Category::getName() const
{
    return name;
}



string Category::getDescription() const
{
    return description;
}



string Category::getParentCategoryID() const
{
    return parentCategoryID;
}



bool Category::isActive() const
{
    return active;
}




void Category::setName(
    const string& name
)

{
    this->name = name;
}




void Category::setDescription(
    const string& description
)

{
    this->description = description;
}




void Category::activate()
{
    active = true;
}




void Category::deactivate()
{
    active = false;
}




bool Category::isSubCategory() const
{
    return !parentCategoryID.empty();
}




void Category::displayCategory() const

{

    cout
    << "\n========== CATEGORY ==========\n"

    << "ID: "
    << categoryID

    << "\nName: "
    << name

    << "\nDescription: "
    << description;


    if(isSubCategory())
    {
        cout
        << "\nParent Category: "
        << parentCategoryID;
    }


    cout
    << "\nStatus: "
    << (active ? "Active" : "Inactive")


    << "\n==============================\n";

}