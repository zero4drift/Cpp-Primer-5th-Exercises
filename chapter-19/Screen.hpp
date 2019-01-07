#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

class Screen;

class Window_mgr
{
 public:
  using ScreenIndex = vector<Screen>::size_type;
  void clear(ScreenIndex);
 private:
  vector<Screen> screens;
};

class Screen
{
  friend void Window_mgr::clear(ScreenIndex);
 public:
  using pos = string::size_type;
  pos cursor = 0;
  Screen() = default;
 Screen(pos ht, pos wd): height(ht), width(wd),
    contents(ht * wd, ' ') {}
 Screen(pos ht, pos wd, char c): height(ht), width(wd),
    contents(ht * wd, c) {}
  char get_cursor() const {return contents[cursor];}
  char get() const {return contents[cursor];}
  char get(pos, pos) const;
  pos size() const;		/* Exercise 7.33 */
  Screen &move(pos, pos);
  Screen &set(char);
  Screen &set(pos, pos, char);
  Screen &display(ostream &os)
    {do_display(os); return *this;}
  const Screen &display(ostream &os) const
  {do_display(os); return *this;}
 private:
  pos height = 0, width = 0;
  string contents;
  void do_display(ostream &os) const {os << contents;}
};

inline Screen &Screen::move(pos r, pos c)
{
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline char Screen::get(pos r, pos c) const
{
  pos row = r * width;
  return contents[row + c];
}

inline Screen::pos Screen::size() const
{
  return height * width;
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
  contents[r * width + col] = ch;
  return *this;
}

inline void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = string(s.height * s.width, ' ');
}

#endif
