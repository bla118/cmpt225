using namespace std;
#include <string>

class StringSet
{
public:
    StringSet();
    StringSet(const StringSet &sSet);
    ~StringSet();
    StringSet& operator=(const StringSet & sSet);
    bool insert(std::string str);
    bool remove(std::string str);
    int find(std::string findstr) const;
    int size() const;
    StringSet unions(const StringSet & sSet) const;
    StringSet intersection(const StringSet & set) const;
    StringSet difference(const StringSet & set) const;
    void getSet();
    
private:
    int currentSize;
    int arraySize;
    string* arr;
    void copyStringSet(const StringSet & sSet);
};


