// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
}graph_t;

typedef struct graph_node{
    int data;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
}graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}

// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
    if(g == NULL)
        return NULL;
    dll_t* nodes = g->nodes;
    node_t* curr = nodes->head;
    while(curr != NULL){
        if(((graph_node_t*) (curr->data))->data == value)
            return (graph_node_t*)curr->data;
        curr = curr->next;
    }
    return NULL;
}

// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return -1;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

// 
int position_node(dll_t* l, int value){
    if(dll_empty(l) == -1)
        return -1;
    node_t* cur = l->head;
    int position = 0;
    while(cur != NULL){
        if(((graph_node_t*) (cur->data))->data == value){
            return position;
        }
        cur = cur->next;
    }
    return -1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    // The function removes the node from the graph along with any edges associated with it.
    // That is, this node would have to be removed from all the in and out neighbor's lists that countain it.
    if(g == NULL)
        return -1;
    graph_node_t* gnode = find_node(g, value);
    if(gnode == NULL)
        return 0;
    dll_t* outNeigh = gnode->outNeighbors;
    node_t* curr = outNeigh->head;
    while(curr != NULL){
        int dest = ((graph_node_t*)(curr->data))->data;
        curr = curr->next;

        graph_remove_edge(g, value, dest);
    }

    // free(outNeigh);
    dll_t* inNeigh = gnode->inNeighbors;
    curr = inNeigh->head;

    while(curr != NULL){
        int source = ((graph_node_t*)(curr->data))->data;
        curr = curr->next;
        graph_remove_edge(g, source, value);
    }

    int pos = position_node(g->nodes, value);
    dll_remove(g->nodes, pos);
    g->numNodes -= 1;

    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    // The function adds an edge from source to destination but not the other way.
    // Make sure you are not adding the same edge multiple times.
    // Make sure you modify the in and out neighbors appropriatelly. destination will be an out neighbor of source.
    // Source will be an in neighbor of destination.
    if(g == NULL){
        return -1;
    }
    graph_node_t* source_node = find_node(g, source);
    graph_node_t* dest_node = find_node(g, destination);
    if(source_node == NULL || dest_node == NULL){
        return 0;
    }
    if(position_node(source_node->outNeighbors, destination) >= 0){
        return 1;
    }
    dll_push_back(source_node->outNeighbors, dest_node);
    dll_push_back(dest_node->inNeighbors, source_node);
    g->numEdges += 1;
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    //The function removes an edge from source to destination but not the other way.
    //Make sure you remove destination from the out neighbors of source.
    //Make sure you remove source from the in neighbors of destination.
    if(contains_edge(g, source, destination) <= 0)
        return contains_edge(g, source, destination);
    dll_t* outNeigh = getOutNeighbors(g, source);
    dll_t* inNeigh = getInNeighbors(g, destination);
    dll_remove(inNeigh, position_node(inNeigh, source));
    dll_remove(outNeigh, position_node(outNeigh, destination));
    g->numEdges -= 1;
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destination){
    if(g == NULL)
        return -1;
    graph_node_t* source_node = find_node(g, source);
    if(source_node == NULL)
        return 0;
    graph_node_t* dest_node = find_node(g, destination);
    if(dest_node == NULL)
        return 0;
    if(position_node(source_node->outNeighbors, destination) < 0)
        return 0;
    return 1;
}

// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){
    if(g == NULL)
        return NULL;
    graph_node_t* source = find_node(g, value);
    if(source == NULL)
        return NULL;
    return source->inNeighbors;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    dll_t* inNeigh = getInNeighbors(g, value);
    if(inNeigh == NULL)
        return -1;
    return inNeigh->count;
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    if(g == NULL)
        return NULL;
    graph_node_t* source = find_node(g, value);
    if(source == NULL)
        return NULL;
    return source->outNeighbors;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    dll_t* outNeigh = getOutNeighbors(g, value);
    if(outNeigh == NULL)
        return -1;
    return outNeigh->count;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    return g->numEdges;
}
// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){

}



#endif
