
#include <vector>
#include <iostream>
int main ()
{

    std::vector<int> lol;

    lol.push_back(42);
    lol.push_back(42);

    lol.push_back(42);

    lol.push_back(42);

    lol.push_back(42);


    std::vector<int>::iterator start = lol.begin();
    std::vector<int>::iterator end = lol.end();

    for (;  start != end ; ++start )
    {
        std::cout << " -->  num : " << *start << std::endl;
    }

    std::cout << "size " << lol.size() << std::endl;




     return (0);

}