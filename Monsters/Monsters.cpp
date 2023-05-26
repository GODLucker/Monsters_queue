#include <iostream>
#include<string>
#include<list>
#include<queue>


using namespace std;
class Monster
{
private:
    string name;
    int health;
public:
    Monster(){}
    Monster(string name,int health) {
        this->name = name;
        this->health = health;
    }
    Monster(const Monster& name)
    {
        this->name = name.name;
        this->health = name.health;
    }
    friend bool operator>(const Monster& n1, const Monster& n2)
    {
        
            return n1.health>n2.health;
    }
    friend bool operator<(const Monster& n1, const Monster& n2)
    {

        return n1.health > n2.health;
    }
    friend ostream& operator << (ostream & out, const Monster & unit)
    {
        out << unit.name << " - Name" << endl;
        out << unit.health << "- Health" << endl;
            return out;
    }
};
void Battle_priority(priority_queue<Monster, vector<Monster>, greater<Monster>>Monster_queue, list<Monster>Monsters_list)
{
    while (!Monster_queue.empty()) 
    {
        std::cout << Monster_queue.top() << std::endl;
        Monster_queue.pop();
    }
    std::cout << "New Battle list by HP:" << std::endl;
    for (auto it = Monsters_list.begin(); it != Monsters_list.end(); it++)
    {
        std::cout << *it << std::endl;
    }

}
int main()
{
    Monster Demon("Demon", 1000);
    Monster Skeleton("Skeleton", 10);
    Monster Orc("Orc", 50);
    list<Monster>Monsters_list;
    Monsters_list.push_back(Demon);
    Monsters_list.push_back(Orc);
    Monsters_list.push_back(Skeleton);
    priority_queue<Monster, vector<Monster>, greater<Monster>> Monster_queue;
    Monster_queue.push(Demon);
    Monster_queue.push(Orc);
    Monster_queue.push(Skeleton);
    cout << "Old battle list" << endl;
    Battle_priority(Monster_queue, Monsters_list);
}

