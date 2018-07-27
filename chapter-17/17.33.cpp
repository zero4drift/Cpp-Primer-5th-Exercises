// Random two-way conversion.
#include <ctime>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <random>
#include <vector>

using std::time;
using std::map;
using std::string;
using std::ifstream;
using std::istringstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::getline;
using std::runtime_error;
using std::default_random_engine;
using std::bernoulli_distribution;
using std::vector;

map<string, vector<string>> buildMap(ifstream &map_file)
{
  map<string, vector<string>> trans_map;
  string key, value;
  while(map_file >> key && getline(map_file, value))
    {
      if(value.size() > 1)
	{
	  istringstream is(value.substr(1));
	  string word;
	  while(is >> word)
	    trans_map[key].push_back(word);
	}
      else
	throw runtime_error("no rule for " + key);
    }
  return trans_map;
}

const string &transform(const string &s, const map<string, vector<string>> &m)
{
  static default_random_engine e(time(0));
  static bernoulli_distribution u;
  auto map_it = m.find(s);
  if(map_it != m.cend())
    return map_it->second[u(e)];
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
