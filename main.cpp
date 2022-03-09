#include <iostream>
#include "Conway.h"

using namespace std;

int main() {
    Conway *conway = new Conway(40, 20, 0.5, 3);
    conway->seed(146);
    conway->generate();
    conway->printMap();

    return 0;
}
