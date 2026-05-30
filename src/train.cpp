// Copyright 2026 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* car = new Car{ light, nullptr, nullptr };

    if (first == nullptr) {
        first = car;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = car;
        car->prev = last;
        car->next = first;
        first->prev = car;
    }
}

int Train::getLength() {
    if (first == nullptr) return 0;
    countOp = 0;
    first->light = false;
    Car* current = first->next;
    countOp++;
    while (true) {
        if (current->light) {
            current->light = false;
            while (current != first) {
                current = current->prev;
                countOp++;
            }
            current = first->next;
            countOp++;
        } else {
            current = current->next;
            countOp++;
        }

        if (current == first && !current->light) {
            break;
        }
    }

    int length = 0;
    const Car* temp = first;
    do {
        length++;
        temp = temp->next;
        countOp++;
    } while (temp != first);

    return length;
}

int Train::getOpCount() const {
    return countOp;
}
