#include <iostream>
#include <vector>

struct Plate {
    std::vector<int> cakes = { 0, 0, 0, 0, 0, 0 };
};

int main() {
    std::vector<std::vector<Plate>> Plates(3, std::vector<Plate>(4));
    
    Plates[0][0].cakes = { 1,0,0,0,0,0 };
    Plates[0][1].cakes = { 1,2,3,1,1,0 };

    return 0;
}