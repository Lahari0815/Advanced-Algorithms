#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>
#include <algorithm>
#include <limits>

using namespace std;

typedef pair<char, int> pci;

void dijkstra(const unordered_map<char, vector<pci>>& graph, char start, char end) {
    unordered_map<char, int> distances;
    unordered_map<char, char> previous;
    set<pair<int, char>> pq;

    for (const auto& node : graph) {
        distances[node.first] = INT_MAX;
        previous[node.first] = '\0';
        for (const auto& neighbor : node.second) {
            if (distances.find(neighbor.first) == distances.end()) {
                distances[neighbor.first] = INT_MAX;
                previous[neighbor.first] = '\0';
            }
        }
    }

    distances[start] = 0;
    pq.insert({0, start});

    while (!pq.empty()) {
        char current = pq.begin()->second;
        pq.erase(pq.begin());

        if (current == end) {
            break;
        }

        if (graph.find(current) != graph.end()) {
            for (const auto& neighbor : graph.at(current)) {
                char next = neighbor.first;
                int weight = neighbor.second;

                int newDist = distances[current] + weight;
                if (newDist < distances[next]) {
                    pq.erase({distances[next], next});
                    distances[next] = newDist;
                    previous[next] = current;
                    pq.insert({newDist, next});
                }
            }
        }
    }

    if (distances[end] == INT_MAX) {
        cout << "No path found from node " << start << " to node " << end << "." << endl;
    } else {
        cout << "The cost of the shortest path from node " << start << " to node " << end << " is " << distances[end] << "." << endl;
        cout << "The path is: ";
        vector<char> path;
        for (char at = end; at != '\0'; at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

void displayGraph(const unordered_map<char, vector<pci>>& graph) {
    cout << "Graph:" << endl;
    set<char> nodes;
    for (const auto& node : graph) {
        nodes.insert(node.first);
        for (const auto& neighbor : node.second) {
            nodes.insert(neighbor.first);
        }
    }

    for (const auto& node : nodes) {
        cout << "Node " << node << ": ";
        if (graph.find(node) != graph.end()) {
            for (const auto& neighbor : graph.at(node)) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
        }
        cout << endl;
    }
}

unordered_map<char, vector<pci>> inputGraph() {
    unordered_map<char, vector<pci>> graph;
    int numEdges;

    while (true) {
        cout << "Enter the number of edges: ";
        cin >> numEdges;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
        } else {
            break;
        }
    }

    cout << "Please enter the edges in the following format: Node_A Node_B Weight" << endl;
    cout << "Example: A B 3" << endl<<'\n';
    
    for (int i = 0; i < numEdges; ++i) {
        char node, neighbor;
        int weight;

        cout << "Edge " << i + 1 << ": ";
        cin >> node >> neighbor >> weight;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter valid characters for nodes and an integer for weight." << endl;
            --i;
            continue;
        }

        graph[node].push_back({neighbor, weight});
    }

    return graph;
}


int main() {
    unordered_map<char, vector<pci>> graph = {
        {'A', {{'B', 3}, {'C', 2}, {'D', 2}}},
        {'B', {{'E', 4}}},
        {'C', {{'D', 1}}},
        {'D', {{'E', 3}}},
        {'E', {}}
    };

    while (true) {
        int choice;
        cout << "\nMenu:" << endl;
        cout << "1. View Graph" << endl;
        cout << "2. Find Shortest Path" << endl;
        cout << "3. Input New Graph" << endl;
        cout << "4. Exit" << endl << '\n';

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        if (choice == 1) {
            displayGraph(graph);
        } else if (choice == 2) {
            char start, end;
            cout << "Enter the starting node: ";
            cin >> start;
            cout << "Enter the ending node: ";
            cin >> end;
            dijkstra(graph, start, end);
        } else if (choice == 3) {
            graph = inputGraph(); 
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
