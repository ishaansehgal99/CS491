#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Element{
    int id, period, step;
    Element(int id, int period, int step) : id(id), period(period), step(step) {}
};

struct custom_comparator{
    bool operator()(const Element& e1, const Element& e2) const{
        if(e1.period == e2.period)
            return e1.id < e2.id;
        return e1.period < e2.period;
    }
};

int main() {
    string reg;
    int id = 0;
    int period = 0;

    vector<Element> elements;

    cin >> reg;
    while(reg ==  "Register") {
        cin >> id >> period;
        elements.emplace_back(Element(-id, -period, -period));

        cin >> reg;
    }

    int num_times = 0;
    cin >> num_times;

    make_heap(elements.begin(), elements.end(), custom_comparator());
    int i = 0;
    while(i < num_times){
        cout << elements.front().id*-1 << endl;

        pop_heap(elements.begin(), elements.end(), custom_comparator());
        Element min = elements.back();
        elements.pop_back();

        min.period += min.step;

        elements.push_back(min);
        std::push_heap(elements.begin(), elements.end(), custom_comparator());

        i++;
    }

    return 0;
}
