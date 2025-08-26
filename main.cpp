#include "inventory.h"
#include <iostream>

int main() {
    Inventory<Item> inv(2);

    std::cout << "[추가 + 자동 확장]\n";
    inv.AddItem({"포션", 50});
    inv.AddItem({"칼", 120});
    inv.AddItem({"활", 90}); // 여기서 Resize(2→4) 발생
    std::cout << "size=" << inv.GetSize() << ", cap=" << inv.GetCapacity() << "\n";
    inv.PrintAllItems();

    std::cout << "\n[정렬: 가격 오름차순]\n";
    inv.SortItems();
    inv.PrintAllItems();

    std::cout << "\n[깊은 복사: 복사 생성자]\n";
    Inventory<Item> copyInv(inv); // 복사 생성
    inv.RemoveLastItem();          // 원본 변경
    std::cout << "- 원본:\n";      inv.PrintAllItems();
    std::cout << "- 복사본(영향없음):\n"; copyInv.PrintAllItems();

    std::cout << "\n[깊은 복사: Assign(=대입)]\n";
    Inventory<Item> other(1);
    other.AddItem({"철괴", 300});
    other.PrintAllItems();
    cout << "대입\n";
    other.Assign(inv);             // 대입
    other.PrintAllItems();

    std::cout << "\n[Resize 축소 테스트]\n";
    inv.Resize(1); // 축소 시 size_도 보정
    std::cout << "size=" << inv.GetSize() << ", cap=" << inv.GetCapacity() << "\n";
    inv.PrintAllItems();

    return 0;
}
