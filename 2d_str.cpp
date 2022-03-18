// swap strings
#include <iostream>
#include <string>

void func1()
{
  std::string buyer ("money");
  std::string seller ("goods");

  std::cout << "Before the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';

  swap (buyer,seller);

  std::cout << " After the swap, buyer has " << buyer;
  std::cout << " and seller has " << seller << '\n';
}

void func2()
{
    const std::string buyer1 = "buyer1";
    const char* buyer2 = "buyer2";
    const char buyer3[] = "buyer3";
    const char buyer4[100] = "buyer4";
    // const char buyer5[2] = "buyer5"; (initializer-string for char array is too long)

    std::cout <<  buyer1 << ","
        <<  buyer2 << ","
        <<  buyer3 << ","  
        <<  buyer4 << "," 
        << std::endl;
}

void func3()
{
    // const char *buyers[] = {"b1", "b2", "b3", "b4", "b5"}; - works, best solution in my opinion
    // const char *buyers[5] = {"b1", "b2", "b3", "b4", "b5"}; - works, need to add counts when change code
    // const char *buyers[100] = {"b1", "b2", "b3", "b4", "b5"}; - segfault after 5 iteration
    // const char *buyers[2] = {"b1", "b2", "b3", "b4", "b5"}; - excess elements in array initializer
    const char* buyers[] = {"b1", "b2", "b3", "b4", "b5"};
    for(size_t i = 0; i < sizeof(buyers)/sizeof(buyers[0]); ++i)
    {
        std::cout << buyers[i] << std::endl;
    }
}

void func4()
{
    //const char* buyers[][]= {{"b1","g1"}, {"b2","g2"}, {"b3","g3"}, {"b4","g4"}, {"b5","g5"}};//array has incomplete element type 'const char *[]'
    //const char* buyers[10][2] = {{"b1","g1"}, {"b2","g2"}, {"b3","g3"}, {"b4","g4"}, {"b5","g5"}}; //segfault after 5 iteration
    const char* buyers[][2] = {{"b1","g1"}, {"b2","g2"}, {"b3","g3"}, {"b4","g4"}, {"b5","g5"}};
    for(size_t i = 0; i < sizeof(buyers)/sizeof(buyers[0]); ++i)
    {
        std::cout << buyers[i][0] << " got " <<  buyers[i][1]  << std::endl;
    }

}


int main ()
{
  func4();


  return 0;
}
