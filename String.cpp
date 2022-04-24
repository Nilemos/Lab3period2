#include "String.h"

TString::TString()
{
  str = new char[1];
  lenght = 0;
  str[lenght] = 0;
}

TString::~TString()
{
  if (str != 0) delete[]str;
  str = 0; 
}

int TString::GetLenght()
{
  return lenght;
}

int TString::strlenght(const char* s)
{
  int count = 0;
  while (s[count] != 0) ++count;
  return count; 
}

TString::TString(const char* s)
{
  if (s == 0) throw "solomka"; 
  lenght = strlenght(s);
  str = new char[lenght + 1];
  for (int i = 0; i < lenght + 1; i++)
    str[i] = s[i];
}

TString::TString(int n, char c)
{
  if (n <= 0) throw "!!";
  lenght = n;
  str = new char[lenght + 1];
  for (int i = 0; i < lenght; i++) str[i] = c; 
  str[lenght] = 0;
}

TString::TString(const TString& p)
{
  lenght = p.lenght;
  str = new char[lenght + 1];
  for (int i = 0; i < lenght + 1; i++)
    str[i] = p.str[i]; 
}

TString TString::operator+(TString p)
{
  TString res(lenght + p.lenght + 1);
  for (int i = 0; i < lenght; i++)
  {
    res.str[i] = str[i];
  }
  for (int i = lenght; i < lenght + p.lenght + 1; i++)
  {
    res.str[i] = p.str[i - lenght];
  }
  return res;
}

TString& TString::operator=(const TString& p)
{
  if (this == &p)
  {
    return *this;
  }
  delete[] str;
  lenght =p.lenght;
  str = new char[lenght + 1];
  for (int i = 0; i < lenght + 1; i++)
  {
    str[i] = p.str[i];
  }
  return *this;
}

TString& TString::operator+=(const TString& p)
{
  int l = lenght + p.lenght;
  char* res = new char[l + 1];
  for (int i = 0; i < lenght; i++)
  {
    res[i] = str[i];
  }
  for (int i = lenght; i < l + 1; i++)
  {
    res[i] = p.str[i - lenght];
  }
  delete[] str;
  lenght = l;
  str = res;
  return *this;
}

TString TString::operator+(char* s)
{
  if (s == 0) throw "eror";
  int Strlen = strlen(s); 
  TString tmp(lenght + Strlen);
  for (int i = 0; i < lenght; i++)
    tmp[i] = str[i]; 
  for (int i = lenght - 1; i < lenght + Strlen; i++)
    tmp[i] = s[i - lenght + 1]; 
  tmp[lenght + Strlen] = 0; 
  return tmp; 
}

TString& TString::operator+=(char* s)
{
  if (s == 0) throw "wr^oo^ng !!";
  int Strlen = strlen(s) + lenght;
  char* res = new char[Strlen + 1];
  for (int i = 0; i < lenght; i++)
    res[i] = str[i];
  for (int i = lenght; i < Strlen + 1; i++)
  {
    res[i] = s[i - lenght];
  }
  delete[] str;
  lenght = Strlen;
  str = res;
  return *this;
}

TString& TString::operator=(char* s)
{
  if (s == 0) throw "erer";
  delete[]s;
  lenght = strlen(s) + 1;
  str = new char[lenght];
  for (int i = 0; i < lenght - 1; i++)
    str[i] = s[i];
  str[lenght - 1] = 0;
  return *this; 
}

bool TString::operator==(TString& p)
{
  if (lenght != p.lenght) return false; 
  for (int i = 0; i <= lenght; i++)
    if (str[i] != p.str[i])
      return false; 
  return true; 
}

bool TString::operator!=(TString& p)
{
  if (lenght != p.lenght) return true; 
  for (int i = 0; i < lenght; i++)
    if (str[i] != p.str[i])
      return true; 
  return false; 
}

bool TString::operator<(TString& p)
{
  int l = lenght > p.lenght ? p.lenght : lenght; 
  for (int i = 0; i < l; i++) {
    if (str[i] < p.str[i])
      return true;
    else if (str[i] > p.str[i])
      return false; 
  }
  if (lenght >= p.lenght) return false;
  else return true;
}

bool TString::operator>(TString& p)
{
  int l = lenght > p.lenght ? p.lenght : lenght;
  for (int i = 0; i < l; i++) {
    if (str[i] < p.str[i])
      return false;
    else if (str[i] > p.str[i])
      return false;
  }
  if (lenght > p.lenght) return true;
  else return false;
}

char& TString::operator[](int i)
{
  if (str == 0) throw "vrong ansver";
  if (i < 0 && lenght < i) throw "vrong ansver";
  return str[i]; 
}

int TString::Find(char c)
{
  for (int i = 0; i < lenght; i++)
    if (str[i] == c) return i;
  return -1;
}

int TString::Find(TString& p)
{
  for (int i = 0; i < lenght - (p.lenght - 1); i++)
  {
    bool fl = true; 
    for (int z = 0; z < (p.lenght - 1); z++)
    {
      if (str[i + z] != p.str[z])
      {
        fl = false; 
        break; 
      }
    }
    if (fl == true)
      return i; 
  }
  return -1;
}

TString* TString::split(char c, int & z)
{
  int k = 0;
  for (int i = 0; i < lenght; i++)
  {
    if (str[i] == c)
      k++;
  }
  if (k == 0)
    return 0;
  k++;
  z = k; 
  TString* mas = new TString[k];
  int j = 0;
  int start = 0;
  for (int i = 0; i < lenght; i++)
  {
    if (str[i] == c)
    {
      mas[j].lenght = i - start;
      delete[] mas[j].str;
      mas[j].str = new char[mas[j].lenght + 1];
      for (int p = 0; p < mas[j].lenght; p++)
        mas[j].str[p] = str[p + start];
      mas[j].str[mas[j].lenght] = 0;
      j = j + 1;
      start = i + 1;
    }
  }
  mas[j].lenght = lenght - start;
  delete[] mas[j].str;
  mas[j].str = new char[mas[j].lenght + 1];
  for (int i = 0; i < mas[j].lenght + 1; i++)
  {
    mas[j].str[i] = str[i + start];
  }
  return mas;
}

std::ostream& operator<<(std::ostream& p, TString& a)
{
  p << a.str; 
  return p; 
}

std::istream& operator>>(std::istream& p, TString& a)
{
  char s[100];
  int i = 0;
  p >> s;
  while (s[i] != 0)
  {
    i = i + 1;
  }
  a.lenght = i;
  delete[] a.str;
  a.str = new char[a.lenght + 1];
  for (i = 0; i < a.lenght; i++)
  {
    a.str[i] = s[i];
  }
  a.str[a.lenght] = 0;
  return p;
}
