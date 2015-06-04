// permutation_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <array>
#include <algorithm>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
   std::array<long, 3> a;   
   
   std::generate_n(a.begin(), a.size(), [](void)->long{ static long i = 1;  return i++; });
   std::for_each(a.begin(), a.end(), [](const long&x) { static bool c = false; if(c) std::cout << ','; std::cout << x; c = true; });
   while (std::next_permutation(a.begin(), a.end()))
   {
      bool lock = false;
      std::for_each(a.begin(), a.end(), [&lock](const long&x){ std::cout << char(lock ? ',' : '\n') << x; lock = true; });
   }
	return 0;
}

