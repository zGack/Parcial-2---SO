#ifndef SCHEDULING_H
#define SCHEDULING_H
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
#include "gantt.h"
#include <stdio.h>
struct process {
    std::string pid;
    int priority;
    int arrivalT;
    int burstT;
    int remainingT;
    int responseT;
    int completionT;
};

void printTitle(std::string str);
void printAverage(std::vector<process*> procVec);
int turnAroundT(process p);
int waitT(process p);
int responseT(process p);
int avgWaitT(std::vector<process*> procVec);
int avgTurnAroundT(std::vector<process*> procVec);
int avgResponseT(std::vector<process*> procVec);

class scheduleSJF {
    private:
        std::vector<process*> processes;
        int elapsed;
        process* fetch();
        bool finished();
    public:
        std::vector<process*> getProcesses();
        scheduleSJF(std::vector<process*> processes);
        void executeNonPreemptive(std::vector<gantt*>* g, int cct);
        void executePreemptive(std::vector<gantt*>* g, int cct);
};


class scheduleFCFS {
    private:
        std::vector<process*> processes;
        int elapsed;
        process* fetch();
        bool finished();
    public:
        std::vector<process*> getProcesses();
        scheduleFCFS(std::vector<process*> processes);
        void executeNonPreemptive(std::vector<gantt*>* g, int cct);
};

class schedulePrio {
    private:
        std::vector<process*> processes;
        int elapsed;
        process* fetch();
        bool finished();
    public:
        std::vector<process*> getProcesses();
        schedulePrio(std::vector<process*> processes);
        void executeNonPreemptive(std::vector<gantt*>* g, int cct);
        void executePreemptive(std::vector<gantt*>* g, int cct);
};
#endif
