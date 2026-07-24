#ifndef CATEGORY_SERVICE_H
#define CATEGORY_SERVICE_H


#include <vector>
#include <string>

#include "../models/Category.h"



class CategoryService
{


private:


    std::vector<Category> categories;



public:


    CategoryService();



    // CREATE

    bool addCategory(
        const Category& category
    );



    // READ

    Category* getCategoryByID(
        const std::string& id
    );



    std::vector<Category>
    getAllCategories() const;



    std::vector<Category>
    searchCategory(
        const std::string& keyword
    );



    // UPDATE

    bool updateCategory(
        const std::string& id,
        const Category& updatedCategory
    );



    // DELETE

    bool deleteCategory(
        const std::string& id
    );



    // DISPLAY

    void displayCategories() const;



};



#endif