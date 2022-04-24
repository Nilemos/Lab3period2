#pragma once
#include <iostream>
#include "String.h"
int main()
{
  TString augh;
  TString augh1(4, 'b');
  TString augh2("bibr");
  TString aughcopia(augh1);


  char bruh[100] = "hi";

  int z = 0;

  std::cout << bruh << std::endl;

  std::cout << "String augh1 " << augh1 << std::endl;

  std::cin >> augh2;
   
  std::cout << "String augh2 " << augh2 << std::endl;

  augh = augh1 + bruh;

  std::cout << "String augh = augh1 + bruh " << augh << std::endl;
   
  std::cout << "String augh2 += bruh " << augh2 << std::endl;

  augh2 += bruh;

  std::cout << "String augh2 += bruh " << augh2 << std::endl;


  if (augh > augh1)  std::cout << "augh > augh1" << std::endl;

  std::cout << "'b' in augh1 have position " << augh1.Find('b') << "\n";

  std::cout << "augh1 in copia augh1 have position " << aughcopia.Find(augh1) << "\n";

  TString* mas = augh2.split('b', z); 
  
  for (int i = 0; i < z; i++) {
    std::cout << "mas" << i << mas[i] << std::endl;
  }

  std::cout << "augh [1] =" << augh1[1];

  return 0; 
}