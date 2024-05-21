#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

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

std::unordered_set<int> findSimilarCakes(Plate a, Plate b) {
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

    Plate current, neighbor;
    int iterasi = 1;

    std::cout << "Iterasi ke - 0: " << std::endl;
    std::cout << "Current element   :" << std::endl;
    for (int element : a.cakes) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Neighbor element   :" << std::endl;
    for (int element : b.cakes) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    while ((!isFull(a) || !isFull(b))&& findSimilarCakes(a, b).empty() == false) {

        std::unordered_set<int> similarCakes = findSimilarCakes(a, b);

        std::cout << "Iterasi ke -" << iterasi << " :" << std::endl;

        if (!isFull(a)) {
            current = a;
            neighbor = b;
        }
        else {
            current = b;
            neighbor = a;
        }
       
        int temp = 0;

        std::sort(current.cakes.begin(), current.cakes.end());
        std::sort(neighbor.cakes.begin(), neighbor.cakes.end());

        for (int i = 0; i < 6; i++) {
            if (current.cakes[i] != 0)
                break;
            else {
                for (int j = 0; j < 6; j++) {
                    if (similarCakes.find(neighbor.cakes[j]) != similarCakes.end()) {
                        temp = neighbor.cakes[j];
                        neighbor.cakes[j] = 0;
                        current.cakes[i] = temp;
                        break;
                    }
                }
            }
        }
       
        a = current;
        b = neighbor;
        iterasi++;

        std::cout << "Similar Cakes  :" << std::endl;
        for (int element : similarCakes) {
            std::cout << element << " ";
        }

        std::cout << std::endl;

        std::cout << "Current element   :" << std::endl;
        for (int element : current.cakes) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

        std::cout << "Neighbor element   :" << std::endl;
        for (int element : neighbor.cakes) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<Plate>> Plates(3, std::vector<Plate>(4));

    Plates[0][0].cakes = { 0,0,0,1,2,2 };
    Plates[0][1].cakes = { 1,1,2,2,3,3 };
    Plates[1][1].cakes = { 4,5,6,7,8,9 };

    switchCake(Plates[0][0], Plates[0][1]);
    return 0;
};

