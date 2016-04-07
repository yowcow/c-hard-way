#include <cstring>
#include "test.h"

char* hoge() {
    char* hoge = const_cast<char*>("HOGEHOGE");
    return hoge;
}
