#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <stdint.h>

using namespace std;

struct LinkNode
{
    uint64_t key;
    uint64_t value;
    LinkNode* next = NULL;
};

struct SkipLinkNode
{
    uint64_t key;
    int count;
    LinkNode* pointer = NULL;
    SkipLinkNode* next = NULL;
};

class SkipLinkList
{
public:
    SkipLinkList(int skipStep = 128);
    ~SkipLinkList();
    bool simpleCheck();

public:
    void insert(uint64_t key, uint64_t value);
    bool find(uint64_t key, uint64_t &value);

private:
    LinkNode* _listHeader = NULL;
    SkipLinkNode* _skipListHeader = NULL;
    int _skipStep;
    int _itemCount;
};

SkipLinkList::SkipLinkList(int skipStep)
    : _skipStep(skipStep)
    , _listHeader(NULL)
    , _skipListHeader(NULL)
    , _itemCount(0)
{}


SkipLinkList::~SkipLinkList()
{
    LinkNode* node = _listHeader;
    while (node != NULL) {
        LinkNode* toDelNode = node;
        node = node->next;
        delete toDelNode;
    }

    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL) {
        SkipLinkNode* toDelNode = skipNode;
        skipNode = skipNode->next;
        delete toDelNode;
    }
}

bool SkipLinkList::simpleCheck()
{
    uint64_t lastKey = 0;
    int nodeCount = 0;
    LinkNode* node = _listHeader;
    while (node != NULL)
    {
        nodeCount++;
        if (node->key < lastKey)
        {
            return false;
        }
        lastKey = node->key;
        node = node->next;
    }
    if (nodeCount < _skipStep)
    {
        return (_skipListHeader == NULL);
    }

    lastKey = 0;
    int skipNodeCount = 0;
    int expectNodeCount = 0;
    SkipLinkNode* skipNode = _skipListHeader;
    while (skipNode != NULL)
    {
        skipNodeCount++;
        if (skipNode->key < lastKey)
        {
            return false;
        }
        lastKey = skipNode->key;
        expectNodeCount += skipNode->count;
        skipNode = skipNode->next;
    }
    return nodeCount == expectNodeCount &&
        skipNodeCount >= ((nodeCount + _skipStep - 1) / _skipStep);
}

/** 请完成下面这个函数，实现题目要求的功能 **/
void SkipLinkList::insert(uint64_t key, uint64_t value)
{
    // TODO:
    LinkNode* newNode = new LinkNode();
    newNode->key = key;
    newNode->value = value;
    auto findRes = SkipLinkList::find(key, value);
    if(_listHeader == NULL){        // 若链表为空，插入的结点为头结点
        _listHeader = newNode;
    }else if(findRes == false){     // 若链表不为空，且链表中没有相应的 key 结点，直接插入链表尾部
        _listHeader->next = newNode;
    }else if(findRes != false){
                                    // 链表中已存在相同 key 结点，直接修改 value
    }

    SkipLinkNode* newSkipNode = new SkipLinkNode();
    if(_skipListHeader == NULL){    // 跳表为空
        newSkipNode->key = _listHeader->key;
        newSkipNode->count = 1;
        newSkipNode->pointer = _listHeader;
    }else if(findRes == false){     // 跳表不为空，且需要插入结点
        SkipLinkNode* p = _skipListHeader;
        while(p->next != NULL){     // 遍历到跳表的尾结点
            p = p->next;
        }
        if(p->count % 128 == 0){    // 如果跳表尾结点的 count 是 128 的倍数，插入新的跳表结点
            newSkipNode->key = key;
            newSkipNode->count = p->count + 1;
            newSkipNode->pointer = newNode;
            p->next = newSkipNode;
        }else{
            p->count++;
        }

    }
}

bool SkipLinkList::find(uint64_t key, uint64_t &value)
{
    // TODO:
    SkipLinkNode* skipLinkP = _skipListHeader;  // 用于遍历跳表结点
    while(skipLinkP->next != NULL && key > skipLinkP->next->key ){  // 查找对应的跳表结点
        skipLinkP = skipLinkP->next;
    }
    LinkNode* linkP = skipLinkP->pointer;       // 用于遍历链表结点
    while(linkP != NULL){  // 在链表中寻找 key 值对应的结点
        if(key > linkP->key){
            linkP = linkP->next;
        }else if(key == linkP->key){
            value = linkP->value;  // 存下 value
            return linkP;          // 返回当前结点的指针
        }else{
            break;
        }
    }
    return false;
}

/** 请完成上面的函数，实现题目要求的功能 **/

vector<string> splitString(const string& text, const string &sepStr) {
    vector<string> vec;
    string str(text);
    string sep(sepStr);
    size_t n = 0, old = 0;
    while (n != string::npos)
    {
        n = str.find(sep,n);
        if (n != string::npos)
        {
            vec.push_back(str.substr(old, n-old));
            n += sep.length();
            old = n;
        }
    }
    vec.push_back(str.substr(old, str.length() - old));
    return vec;
}
template <typename T>
bool stringToInteger(const string& text, T& value) {
    const char* str = text.c_str();
    char* endPtr = NULL;
    value = (T)strtol(str, &endPtr, 10);
    return (endPtr && *endPtr == 0);
}


bool testSkipLinkList(string inputParam) {
    vector<string> inputVec = splitString(inputParam, ":");
    if (inputVec.size() != 2 || (inputVec[0] != "list" && inputVec[0] != "count"))
    {
        cout << "input format error!" << endl;
        return false;
    }
    // prepare data
    vector<pair<uint64_t, uint64_t> > keyValueVec;
    if (inputVec[0] == "list") {
        vector<string> kvVec = splitString(inputVec[1], ";");
        for (size_t i = 0; i < kvVec.size(); i++) {
            vector<string> kvStr = splitString(kvVec[i], ",");
            uint64_t key, value;
            if (kvStr.size() != 2 ||
                !stringToInteger<uint64_t>(kvStr[0], key) ||
                !stringToInteger<uint64_t>(kvStr[1], value))
            {
                cout << "key-value list format error!" << endl;
                return false;
            }
            keyValueVec.push_back(make_pair(key, value));
        }
    }

    if (inputVec[0] == "count") {
        uint64_t count;
        if (!stringToInteger<uint64_t>(inputVec[1], count)) {
            cout << "count format error!" << endl;
            return false;
        }
        for (uint64_t i = 0; i < count; i++) {
            keyValueVec.push_back(make_pair(i, i));
        }
        random_shuffle(keyValueVec.begin(), keyValueVec.end());
    }

    uint64_t maxKey = 0;
    uint64_t value;

    SkipLinkList list(4);
    for (size_t i = 0; i < keyValueVec.size(); i++)
    {
        list.insert(keyValueVec[i].first, keyValueVec[i].second);

        // test find
        bool ret = list.find(keyValueVec[i].first, value);
        if (!ret || value != keyValueVec[i].second)
        {
            cout << "test find error!" << endl;
            return false;
        }
        // test replace
        list.insert(keyValueVec[i].first, keyValueVec[i].second + 1);
        ret = list.find(keyValueVec[i].first, value);
        if (!ret || value != keyValueVec[i].second + 1)
        {
            cout << "test replace error!" << endl;
            return false;
        }
        maxKey = max(maxKey, keyValueVec[i].first);
    }

    // test not exist key
    if (list.find(maxKey + 1, value))
    {
        cout << "find not exist error!" << endl;
        return false;
    }
    return list.simpleCheck();
}

int main() {
    bool res;
    string _inputParam;
    getline(cin, _inputParam);
    res = testSkipLinkList(_inputParam);
    if (res)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    return 0;
}
