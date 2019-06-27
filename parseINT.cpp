#include <string>
#include <vector>
#include <utility>
#include <algorithm>

long parse_int(std::string number) {

  long result = 0;

  std::vector<std::pair<std::string, int>> converter;

  converter.push_back(std::make_pair ("and", 0));
  converter.push_back(std::make_pair ("zero", 0));
  converter.push_back(std::make_pair ("one", 1));
  converter.push_back(std::make_pair ("two", 2));
  converter.push_back(std::make_pair ("three", 3));
  converter.push_back(std::make_pair ("four", 4));
  converter.push_back(std::make_pair ("five", 5));
  converter.push_back(std::make_pair ("six", 6));
  converter.push_back(std::make_pair ("seven", 7));
  converter.push_back(std::make_pair ("eight", 8));
  converter.push_back(std::make_pair ("nine", 9));
  converter.push_back(std::make_pair ("ten", 10));
  converter.push_back(std::make_pair ("eleven", 11));
  converter.push_back(std::make_pair ("twelve", 12));
  converter.push_back(std::make_pair ("thirteen", 13));
  converter.push_back(std::make_pair ("fourteen", 14));
  converter.push_back(std::make_pair ("fifteen", 15));
  converter.push_back(std::make_pair ("sixteen", 16));
  converter.push_back(std::make_pair ("seventeen", 17));
  converter.push_back(std::make_pair ("eighteen", 18));
  converter.push_back(std::make_pair ("nineteen", 19));

  converter.push_back(std::make_pair ("twenty", 20));
  converter.push_back(std::make_pair ("thirty", 30));
  converter.push_back(std::make_pair ("forty", 40));
  converter.push_back(std::make_pair ("fifty", 50));
  converter.push_back(std::make_pair ("sixty", 60));
  converter.push_back(std::make_pair ("seventy", 70));
  converter.push_back(std::make_pair ("eighty", 80));
  converter.push_back(std::make_pair ("ninety", 90));

  auto ri = number.rbegin();
  auto ro = ri;

  int multiply = 1;

  for(;ri != number.rend();ri++)
  {
    if ((*ri == ' ') || (*ri == '-') || (ri == number.rend() - 1))
      {
        std::string s;
        if (ri == number.rend() - 1)
        {
            std::string a(ro, ri + 1);
            s = a;
        }
        else
        {
            std::string a(ro, ri);
            s = a;
        }
        std::reverse(s.begin(), s.end());
        ro = ri + 1;

        auto iter = std::find_if(converter.begin(), converter.end(), [&](auto a){
        return (a.first == s) ? true : false;});

        if (iter != converter.end())
        {
          result += iter->second * multiply;
        }
        else if (s == "hundred") multiply *= 100;
        else if (s == "thousand") multiply = 1000;
        else return 1000000;
      }
  }
  return result;
}
