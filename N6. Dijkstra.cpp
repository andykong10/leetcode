// ***
//
// Dijkstra's algorithm. Return the mininum distance from start to each node.
//
// ***

template <typename T>
unordered_map<T, int> dijkstra(unordered_map<T, unordered_set<T>>& neighbors,
                               unordered_map<T, unordered_map<T, int>>& weights, T start) {
    struct NodeState {
        T id;
        int distFromStart;
    };

    // min distance from start to each node
    unordered_map<T, int> minDistTo;
    minDistTo[start] = 0;

    // smallest distance has the highest priority
    auto compare = [](const NodeState& a, const NodeState& b) { return a.distFromStart > b.distFromStart; };
    priority_queue<NodeState, vector<NodeState>, decltype(compare)> pq(compare);
    pq.push({start, 0});

    while (not pq.empty()) {
        NodeState curState = pq.top();
        pq.pop();

        T curID = curState.id;
        int distToCur = curState.distFromStart;

        // already obtained a shorter distance to reach curID, continue.
        if (minDistTo.count(curID) and distToCur > minDistTo[curID]) {
            continue;
        }

        for (int neighID : neighbors[curID]) {
            int distToNeigh = minDistTo[curID] + weights[curID][neighID];

            if (not minDistTo.count(neighID) or distToNeigh < minDistTo[neighID]) {
                minDistTo[neighID] = distToNeigh;
                pq.push({neighID, distToNeigh});
            }
        }
    }

    return minDistTo;
}
