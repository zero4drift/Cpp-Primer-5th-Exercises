#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

using std::map;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::getline;
using std::runtime_error;

map<string, string> buildMap(ifstream &map_file)
{
  map<string, string> trans_map;
  string key, value;
  while(map_file >> key && getline(map_file, value))
    {
      if(value.size() > 1)
	trans_map[key] = value.substr(1);
      else
	throw runtime_error("no rule for " + key);
    }
  return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
  auto map_it = m.find(s);
  if(map_it != m.cend())
    return map_it->second;
  else
    return s;
}

void word_transfrom(ifstream &map_file, ifstream &input)
{
  auto trans_map = buildMap(map_file);
  string text;
  while(getline(input, text))
    {
      istringstream stream(text);
      string word;
      bool firstword = true;
      while(stream >> word)
	{
	  if(firstword) firstword = false;
	  else cout << " ";
	  cout << transform(word, trans_map);
	}
      cout << endl;
    }
}

int main(int argc, char *argv[])
{
  if(argc != 3) return -1;
  auto map_file = ifstream(argv[1]);
  auto input = ifstream(argv[2]);
  word_transfrom(map_file, input);
}
