#include <iostream>
#include <string>

class CPU {
public:
    void freeze() {
        std::cout << "CPU freezing...\n";
    }
    void jump(long position) {
        std::cout << "CPU jumping to position " << position << ".\n";
    }
    void execute() {
        std::cout << "CPU executing instructions.\n";
    }
};

class Memory {
public:
    void load(long position, std::string data) {
        std::cout << "Memory loading data \"" << data << "\" at position " << position << ".\n";
    }
};

class HardDrive {
public:
    std::string read(long lba, int size) {
        return "OS Boot Data";
    }
};

class ComputerFacade {
private:
    CPU* cpu;
    Memory* memory;
    HardDrive* hardDrive;

public:
    ComputerFacade(CPU* c, Memory* m, HardDrive* h) : cpu(c), memory(m), hardDrive(h) {}

    void start() {
        cpu->freeze();
        memory->load(0, hardDrive->read(0, 1024));
        cpu->jump(0);
        cpu->execute();
    }
};

int main() {
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

    ComputerFacade computer(&cpu, &memory, &hardDrive);
    computer.start();

    return 0;
}