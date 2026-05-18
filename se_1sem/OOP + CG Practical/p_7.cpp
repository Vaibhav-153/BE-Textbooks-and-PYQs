#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
    typedef map<string, int> mapType;
    mapType populationMap;

    // Insert elements into the map using different methods
    populationMap.insert(pair<string, int>("China", 1339));
    populationMap.insert(pair<string, int>("India", 1187));
    populationMap.insert(mapType::value_type("US", 310));
    populationMap.insert(mapType::value_type("Indonesia", 234));
    populationMap.insert(make_pair("Brasil", 193));
    populationMap.insert(make_pair("Pakistan", 170));

    // Erase the last element in the ordered map
    mapType::iterator iter = --populationMap.end();
    populationMap.erase(iter);

    // Output the size of the map
    cout << "Size of populationMap: " << populationMap.size() << '\n';

    // Output the contents of the map
    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
        cout << iter->first << ": " << iter->second << " million\n";
    }

    // Find the population of a specific country
    string country("Indonesia");
    iter = populationMap.find(country);
    if (iter != populationMap.end())
        cout << country << "'s population is " << iter->second << " million\n";
    else
        cout << "Key is not in populationMap" << '\n';

    // Clear the entries in the map
    populationMap.clear();

    return 0;
}
