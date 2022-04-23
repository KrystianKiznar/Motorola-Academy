#include <iostream>
#include <list>


std::string command;
int minimal_fence_length = 4;

int take_fence_length()
// takes fence lenght value from a user
{   
    float fence_length;
    while (true)
    {
        std::cout << "Please, type the fence length: " << std::endl;
        

        if (!(std::cin >> fence_length))
        {
            std::cout << "Insert a number" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        
        else if (fence_length < minimal_fence_length)
        {
            std::cout << "Please, insert a positive number, more than 3 " << std::endl;
            continue;
        }
        else if(fence_length-int(fence_length) != 0)
        {
            std::cout << "Insert an integer!" << std::endl;
            continue;
        }
        
        return fence_length;
        
    }

}


int run_alghorithm()
// calculates the best possible option 
{   
    int a;
    int b;
    int area;
    int fence_length = take_fence_length();
    std::cout << fence_length <<" meters is available."<< std::endl;

    std::list<int> field_values; 
     for (a = 1; 2*a < fence_length; a++) //creates a list of every possible farm area
     {
         b = fence_length - 2*a;
         
         area = a*b;
         field_values.push_back(area);
         
     }
     
    int max_value = 0, counter=0;
    for (std::list<int>::iterator i= field_values.begin(); i!= field_values.end(); i++) //looks for the maximal farm area, counts its index
    {
        if (max_value < *i)
        {
            max_value = *i;
            counter ++;
        }
    }
    
    a = counter; //calculates 'a' and 'b' value
    b = fence_length - 2*a;
        
    std::cout<<"The value of 'a' variable is "<< a <<std::endl;
    std::cout<<"The value of 'b' variable is "<< b <<std::endl;
    std::cout << "The optimal area of the farm equals " << max_value <<" square meters."<< std::endl;
                
    return 0;
}


int main()
{   
    while (true)
    {
        std::cout<<"Type 'RUN' to start the program, or 'q' to quit: ";
        std::cin>> command;
        
        if ((command == "run") || (command == "RUN") || (command == "Run"))
        {
            run_alghorithm();
            std::cout << "Do you want to run the program again?" << std::endl;
        }
        else if ((command == "q") || (command == "Q"))
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Repeat, please." << std::endl;
        }
    }
    return 0;
}
