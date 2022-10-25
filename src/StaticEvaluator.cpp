//
// Created by richa on 24/10/2022.
//

#include <queue>
#include "StaticEvaluator.h"

StaticEvaluator::StaticEvaluator() {
    // Initialise hashmap?


    nodes = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124};
    adjacencyMatrix = std::vector<std::vector<bool>> (125);
    for (int i = 0; i < 125; i++) {
        adjacencyMatrix[i] = std::vector<bool> (125, false);
    }

    // Set the adjacency matrix bools for an empty hex board
    for (int i = 0; i <= 124; i++) {
        if (i >= 121) { continue; }

        // Get offsets for all 6 surrounding hex pieces of any position
        std::vector<int> offsetIndex = {-11, -10, -1, 1, 10, 11};

        // Fix offsets for edge cases around sides of board
        // General case of left edge
        if (i % 11 == 0) { offsetIndex = {-11, -10, 1, 11}; }
        // General case of right edge
        if ((i+1) % 11 == 0) { offsetIndex = {-11, -1, 10, 11}; }
        // Specific corner cases
        switch (i) {
            case 0: offsetIndex = {1, 11}; break;
            case 10: offsetIndex = {-1, 10, 11}; break;
            case 110: offsetIndex = {-11, -10, 1}; break;
            case 120: offsetIndex = {-11, -1}; break;
            default: break;
        }

        // Go through all the offsets and connect the adjacent nodes in the matrix.
        for (int offset : offsetIndex) {
            if ((i+offset <0) || (i+offset >= 121)) {continue;}
            adjacencyMatrix[i][i+offset] = true;
        }

        // Connect nodes to side end nodes
        if (i % 11 == 0) { adjacencyMatrix[i][121] = true; adjacencyMatrix[121][i] = true; }
        if ((i+1) % 11 == 0) { adjacencyMatrix[i][122] = true; adjacencyMatrix[122][i] = true; }
        if (i < 11) { adjacencyMatrix[i][123] = true; adjacencyMatrix[123][i] = true; }
        if (i >= 110) { adjacencyMatrix[i][124] = true; adjacencyMatrix[124][i] = true; }
    }


    // print out empty board if needed
//    for (int i = 0; i < adjacencyMatrix.size(); i++)
//    {
//        int count = 0;
//        for (int j = 0; j < adjacencyMatrix[i].size(); j++)
//        {
//            if (adjacencyMatrix[i][j]) {
//                count++;
//            }
//        }
//        std::cout << i << " connects to " << count << " nodes" << std::endl;
//    }
}

// Takes a board layout, and computes the static evaluation of it
int StaticEvaluator::getEvaluation(HexBoard board) {

    int AScore = GetEvaluationForPlayer(board, 'A');
    if (AScore == -1) {
        return -INT16_MAX;
    }
    int BScore = GetEvaluationForPlayer(board, 'B');
    if (BScore == -1) {
        return INT16_MAX;
    }
    return BScore-AScore;

    // check if game is won and return -infinity or +infinity depending.

    // do a bfs and find the shortest distance to the end for each side

    // return distance(A)-distance(B)
    // possibly store in a hashmap as a pseudo-cache? for efficiency later




    // TEMP IMPLEMENTATION:
    // Take the number of pieces that are adjacent to other pieces of the same colour and subtract from each other.
    int ACount = 0, BCount = 0;

    // These are the offsets to find all adjacent cells.
    std::vector<int> offsetIndex = {-11, -10, -1, 1, 10, 11};

    for (int i = 0; i < 121; i++) {
        if (board.getBoard()[i] != '.') {
            // Piece is not empty
            for (int offset : offsetIndex) {
                try {
                    if (board.getBoard().at(i+offset) == board.getBoard()[i]) {
                        if (board.getBoard()[i] == 'A') {
                            ACount++;
                        } else {
                            BCount++;
                        }
                        break;
                    }
                } catch (...) {

                }
            }
        }
    }
    return ACount - BCount;
}



int StaticEvaluator::GetEvaluationForPlayer(HexBoard board, char player) {
    int startNode;
    int endNode;
    std::vector<int> ignoreNodes;
    if (player == 'A') {
        startNode = 121;
        endNode = 122;
    } else {
        startNode = 123;
        endNode = 124;
    }

    Graph g = generateGraphRepresentation(board, player);
    std::vector<int> localNodes = g.nodes;
    std::vector<std::vector<bool>> localAdjacencyMatrix = g.adjacencyMatrix;


    // Do a BFS to find the shortest path between goal states

    std::vector<bool> visited(localAdjacencyMatrix.size(), false);
    // Queue contains index , depth
    std::queue<std::pair<int,int>> q;
    q.push(std::pair(startNode,0));
    // Set source as visited
    visited[startNode] = true;
    for (int ignoreNode : ignoreNodes) {
        visited[ignoreNode] = true;
    }

    // BFS loop
    while(q.size() != 0){
        // do bfs through localAdjacencyMatrix to find depth to endNode
        std::pair node = q.front();
        if (node.first == endNode) {
            //std::cout << "connected to " << node.first << std::endl;
            return node.second;
        }
        //std::cout << node.first << std::endl;

        // get all adjacent adjacent nodes and add to queue
        for (int i = 0; i < 125; i++) {
            // Checks whether it is connected to a node
            if (!localAdjacencyMatrix[node.first][i]) {
                continue;
            }

            //std::cout << "connected to " << i << std::endl;
            // Checks whether the connected node is a visited node
            if (visited[i]) { continue; }

            // Adds to the queue
            q.push(std::pair(i, node.second+1));
            visited[i] = true;
            //std::cout << node.first << " -> " << i << " depth: " << node.second << std::endl;
        }
        q.pop();
    }

    // Return -1 if connection not possible
    return -1;
}

int StaticEvaluator::isGameOver(HexBoard board) {
    return 0;
}

Graph StaticEvaluator::generateGraphRepresentation(HexBoard board, char player) {
    char opposingPlayer;
    std::vector<int> ignoreNodes;
    if (player == 'A') {
        opposingPlayer = 'B';
        ignoreNodes = {123, 124};
    } else {
        opposingPlayer = 'A';
        ignoreNodes = {121, 122};
    }

    // Take a hardcoded representation of an empty board.
    std::vector<int> localNodes(nodes);
    std::vector<std::vector<bool>> localAdjacencyMatrix(adjacencyMatrix);

    // First get rid of opposing player piece connections
    for (int i = 0; i < 121; i++) {
        if (board.getBoard()[i] == opposingPlayer) {
            // Get rid of all connections to this piece
            for (int j = 0; j < localAdjacencyMatrix[i].size(); j++) {
                if (localAdjacencyMatrix[i][j]) {
                    localAdjacencyMatrix[j][i] = false;
                }
            }
            // Get rid of all connections out of this piece
            localAdjacencyMatrix[i] = std::vector<bool> (125, false);
        }
    }

    // Connect up player piece nodes
    for (int i = 0; i < 121; i++) {
        if (board.getBoard()[i] == player) {
            // Get list of all nodes the piece connects to
            std::vector<int> connections = {};
            for (int j = 0; j < 125; j++) {
                if (!localAdjacencyMatrix[i][j]) { continue; }
                connections.push_back(j);
            }

            // Connect each of those connections with each other
            for (int connectionStart : connections) {
                for (int connectionEnd : connections) {
                    localAdjacencyMatrix[connectionStart][connectionEnd] = true;
                }
            }

            // Remove connections from all of those pieces to i
            for (int connection : connections) {
                localAdjacencyMatrix[connection][i] = false;
            }

            // Set all of i's connections to false
            localAdjacencyMatrix[i] = std::vector<bool> (125, false);
        }
    }

    Graph g;
    g.nodes = localNodes;
    g.adjacencyMatrix = localAdjacencyMatrix;
    return g;
}
