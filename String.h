#pragma once
#include <iostream>
#include <string>

using namespace std; 

class TString
{
public:
  TString();
  ~TString();
  int GetLenght(); 
  int strlenght(const char* s);
  TString(const char* s);  
  TString(int n, char c = 0); 
  TString(const TString& p); 
  TString operator + (TString p); 
  TString& operator = (const TString& p); 
  TString& operator += (const TString& p); 
  TString operator + (char* s); 
  TString& operator +=(char* s); 
  TString& operator = (char* s); 
  bool operator == (TString& p); 
  bool operator != (TString& p); 
  bool operator < (TString& p); 
  bool operator > (TString& p); 
  char& operator[] (int i); 
  int Find(char c);
  int Find(TString& p); 
  TString* split(char c, int & z); 
  friend std::ostream& operator << (std::ostream& p, TString & a); 
  friend std::istream& operator >> (std::istream& p, TString& a);

private:
  int lenght;
  char* str;
}; 



