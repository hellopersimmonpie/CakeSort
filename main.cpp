#include <iostream>
#include <vector>
#include <unordered_set>

struct Plate {
    std::vector<int> cakes = { 0, 0, 0, 0, 0, 0 };
};

bool isFull(Plate input) {
    for (int num : input.cakes) {
        if (num == 0)
            return false;
    }
    return true;
}

std::unordered_set<int> findSimilarNumbers(Plate a, Plate b) {
    std::unordered_set<int> numSet(a.cakes.begin(), a.cakes.end());
    std::unordered_set<int> similarNumbers;

    for (int num : b.cakes) {
        if (num != 0 && numSet.find(num) != numSet.end()) {
            similarNumbers.insert(num);
        }
    }

    return similarNumbers;
}

void switchCake(Plate a, Plate b) {

    Plate current;

    while (!isFull(a) || !isFull(b) && findSimilarNumbers(a, b).empty() == false) {

        if (!isFull(a))
            current = a;
        else
            current = b;

        int i = 0;

        for (int element : a.cakes) {
            if (element != 0) break;
            else {


            }

        }

    }
}

int main() {
    std::vector<std::vector<Plate>> Plates(3, std::vector<Plate>(4));

    Plates[0][0].cakes = { 0,0,0,1,2,2 };
    Plates[0][1].cakes = { 1,1,2,2,3,3 };
    Plates[1][1].cakes = { 4,5,6,7,8,9 };

    for (int element : findSimilarNumbers(Plates[0][1], Plates[0][0])) {
        std::cout << element << " ";
    }

    std::cout << std::endl;

    if (findSimilarNumbers(Plates[0][1], Plates[1][1]).empty() == true) {
        std::cout << "Tidak ada angka yang sama" << std::endl;
    }
    return 0;
};

