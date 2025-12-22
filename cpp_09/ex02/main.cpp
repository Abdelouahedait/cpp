#include "PmergeMe.hpp"

int main(int ac, char **av)
{
   try
   {
        check_args(ac, av);
        double vector_time = print_sort_vector(ac, av);
     //    double deque_time = print_sort<std::deque<int> >(ac, av, 0);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << vector_time << " us" << std::endl;
     //    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << deque_time << " us" << std::endl;
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
   }
   


    return 0;
}