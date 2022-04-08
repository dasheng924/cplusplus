#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>

void print(int var)
{
    std::cout<<var<<std::endl;
}
int main()
{   
    std::vector<int> numbers(1000);
    std::for_each(numbers.begin(),numbers.end(),print);

    std::generate(numbers.begin(),numbers.end(),std::rand);
    std::for_each(numbers.begin(),numbers.end(),print);


    int count3 = 0;
    int count13 = 0;
    std::for_each(numbers.begin(),numbers.end(),[&](int x){
        count3 += x%3==0;
        count13 += x%13==0;
    });

    std::cout<<count3<<"\t"<<count13<<std::endl;








    exit(0);
}


