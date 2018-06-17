#include <set>
#include <string>

using std::set;
using std::string;

class Message;

class Folder
{
  set<Message*> messages;
 public:
  Folder() = default;
  Folder(const Folder &);
  ~Folder();
  void addMsg(Message *m) {messages.insert(m);}
  void remMsg(Message *m) {messages.erase(m);}
};

class Message
{
  friend class Folder;
  friend void swap(Message &, Message &);
 public:
  explicit Message(const string &str = ""): contents(str) {}
  Message(const Message &);
  Message& operator=(const Message &);
  ~Message();
  void save(Folder &);
  void remove(Folder &);
  void addFod(Folder *f) {folders.insert(f);}
  void remFod(Folder *f) {folders.erase(f);}
 private:
  string contents;
  set<Folder*> folders;
  void add_to_Folders(const Message &);
  void remove_from_Folders();
};

void Message::save(Folder &f)
{
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f)
{
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
  for(auto f : m.folders)
    f->addMsg(this);
}

Message::Message(const Message &m):
contents(m.contents), folders(m.folders)
{
  add_to_Folders(m);
}

void Message::remove_from_Folders()
{
  for(auto f : folders)
    f->remMsg(this);
}

Message::~Message()
{
  remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

  void swap(Message &lhs, Message &rhs)
  {
    using std::swap;
    for(auto f : lhs.folders)
      f->remMsg(&lhs);
    for(auto f : rhs.folders)
      f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f : lhs.folders)
      f->addMsg(&lhs);
    for(auto f : rhs.folders)
      f->addMsg(&rhs);
  }

Folder::~Folder()
{
  for(auto &m : messages)
    m->remove(*this);
}

Folder::Folder(const Folder &f)
{
  messages.clear();
  for(auto &m : messages)
    m->remove(*this);
  for(auto &m : f.messages)
    m->save(*this);
}
