#include "sort.h"
#include <vector>

namespace PL04 {
    template <class BiDirIt>
    void sort(BiDirIt begin, BiDirIt end) {
        // insert sort
        for (BiDirIt i = begin; i != end; ++i) {
            for (BiDirIt j = i; j != begin && *j > *(j - 1); --j) {
                std::iter_swap(j, j - 1);
            }
        }
    }

    template void sort(std::vector<int>::iterator, std::vector<int>::iterator);
}