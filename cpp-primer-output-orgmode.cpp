#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::set;
using std::map;
using std::string;
using std::to_string;
using std::getline;
using std::ispunct;

bool is_include_using_line(const string &line);

void handle_reference_files(const string &chapter_path, const map<string, bool> &m, ofstream &ofs)
{
  string file_path;
  for(const auto &p : m)
    {
      if(!p.second) continue;
      file_path = chapter_path + "/" + p.first;
      string line;
      ifstream ifs(file_path);
      ofs << "* " + p.first + "\n\n";
      ofs << "#+begin_src c++\n";
      while(ifs)
	{
	  getline(ifs, line);
	  if(!line.size() || is_include_using_line(line)) continue;
	  ofs << "  " << line << "\n";
	}
      ofs << "#+end_src\n\n";
    }
}

map<string, bool> get_reference_names(const string &line, set<string> &rset)
{
  map<string, bool> ms;
  istringstream iss(line);
  string name;
  while(iss >> name)
    {
      if((name.find(".cpp") != string::npos)
	 || (name.find(".h")) != string::npos)
	{
	  if(ispunct(name[name.size() - 1]))
	    name.erase(name.size() - 1);
	  if(rset.find(name) == rset.end())
	    {
	      ms[name] = true;
	      rset.insert(name);
	    }
	  else
	    ms[name] = false;
	}
    }
  return ms;
}

bool is_file_reference(const string &line)
{
  return (line.find("//") != string::npos)
    && ((line.find(".h") != string::npos)
	|| (line.find(".cpp") != string::npos))
    && ((line.find("see") != string::npos)
	|| (line.find("See") != string::npos));
}

bool is_include_using_line(const string &line)
{
  return (line.find("#include") != string::npos)
    || (line.find("using std") != string::npos);
}

map<string, bool> handle_cpp_file(const string &file_name, ifstream &ifs, ofstream &ofs, set<string> &rset)
{
  string line;
  ofs << "* Exercise " + file_name + "\n\n";
  ofs << "#+begin_src c++\n";
  map<string, bool> m;
  while(ifs)
    {
      getline(ifs, line);
      if(!line.size() || is_include_using_line(line)) continue;
      // There is one single line like "See xxx.h and xxx.cpp"
      if(is_file_reference(line)) m = get_reference_names(line, rset);
      ofs << "  " << line << "\n";
    }
  ofs << "#+end_src\n\n";
  return m;
}

void handle_cpp_files(const string &project_root, unsigned chapter_no, ofstream &ofs)
{
  set<string> reference_files;
  string chapter_path = project_root + "/chapter-" + to_string(chapter_no);
  unsigned file_no = 1;
  string file_name = to_string(chapter_no) + "." + to_string(file_no);
  string file_path = chapter_path + "/" + file_name + ".cpp";
  ifstream ifs(file_path);
  while(ifs)
    {
      auto m = handle_cpp_file(file_name, ifs, ofs, reference_files);
      for(const auto &p : m)
	if(!p.second) ofs << "[[" + p.first + "]]\n\n";
      handle_reference_files(chapter_path, m, ofs);
      ++file_no;
      file_name = to_string(chapter_no) + "." + to_string(file_no);
      file_path = chapter_path + "/" + file_name + ".cpp";
      ifs.close();
      ifs.open(file_path);
    }
}

int main()
{
  string project_root;
  cout << "Specify project root path: ";
  cin >> project_root;
  unsigned first, last;
  cout << "Specify first chpater and last chapter number: " << endl;
  cin >> first >> last;
  string chapter_path;
  string output_path;
  ofstream ofs;
  while(first <= last)
    {
      output_path = project_root
	+ "/Cpp-Primer-5th-Exercises-Chapter-" + to_string(first)
	+ ".org";
      ofs.open(output_path, ofstream::app);
      handle_cpp_files(project_root, first, ofs);
      ++first;
      ofs.close();
    }
}
