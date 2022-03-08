#include <iostream>
#include "Conway.h"

using namespace std;

int main() {
    Conway *conway = new Conway(10, 5, 0.45, 3);
    conway->seed(146);
    conway->generate();
    conway->printMap();

    return 0;
}
