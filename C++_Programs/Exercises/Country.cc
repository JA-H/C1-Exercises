#include<iostream>
#include<string>


class Country
{
  private:
    std::string name_; 		// Name of country
    unsigned int population_;	// Population of country
    double GDP_;		// GDP of country
    unsigned int area_;		// Area of country

  public:
    Country (); 		// Constructor
    Country( const Country &source); 	//Copy Constructor
    
};


int main()
{
  return 0;
}