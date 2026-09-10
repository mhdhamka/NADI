#include "services/CategoryService.h"

#include <iostream>
#include <algorithm>



using namespace std;





CategoryService::CategoryService()

{

}







bool CategoryService::addCategory(
    const Category& category
)

{


    for(auto& existing : categories)

    {

        if(existing.getCategoryID()
            == category.getCategoryID())

        {

            return false;

        }

    }



    categories.push_back(category);



    return true;

}









Category* CategoryService::getCategoryByID(
    const string& id
)

{


    for(auto& category : categories)

    {

        if(category.getCategoryID()
            == id)

        {

            return &category;

        }

    }



    return nullptr;

}










vector<Category>
CategoryService::getAllCategories() const

{

    return categories;

}









vector<Category>
CategoryService::searchCategory(
    const string& keyword
)

{


    vector<Category> result;



    for(auto& category : categories)

    {

        if(

            category.getName()
            .find(keyword)

            != string::npos

        )

        {

            result.push_back(category);

        }

    }



    return result;

}









bool CategoryService::updateCategory(

    const string& id,

    const Category& updatedCategory

)

{


    Category* category =
        getCategoryByID(id);



    if(category == nullptr)

        return false;



    *category =
        updatedCategory;



    return true;

}










bool CategoryService::deleteCategory(
    const string& id
)

{


    auto iterator =

    remove_if(

        categories.begin(),

        categories.end(),

        [&](Category& category)

        {

            return category.getCategoryID()
                == id;

        }

    );




    if(iterator == categories.end())

        return false;




    categories.erase(

        iterator,

        categories.end()

    );



    return true;

}










void CategoryService::displayCategories() const

{


    cout
    << "\n========== CATEGORIES ==========\n";



    for(auto& category : categories)

    {

        category.displayCategory();

    }



    cout
    << "\n================================\n";

}