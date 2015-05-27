#include <vector>

using namespace std;

class Vertex{
    private:
        vector<Edge*> Adjacencys;
        int color;
        bool visited;
    public:
        Vertex();
        ~Vertex();
        void addEdge(Edge* ed)
        {
            Adjacencys.push_back(ed);
        }
        vector<Edge*> getVec()
        {
            return Adjacencys;
        }
};

class Edge{
    private:
        Vertex *from;
        Vertex *to;
        int weight;
    public:
        Edge()
        {
            from = 0;
            to = 0;
            weight = 0;
        }
        Edge(int weight, Vertex *from, Vertex *to)
        {
            this->weight = weight;
            this->from = from;
            this->to = to;
        }
        ~Edge()
        {
            delete from;
            delete to;
        }
};

class AdjacencyList{
    private:
        vector<Vertex*> Vertices;
    public:
        Graph();
        ~Graph();
        void add_edge(Vertex *from, Vertex *to, int weight)
        {
            bool flag = false;
            
            //Checks if dest Vertex exists
            for(auto it = Vertices.begin(); it != Vertices.end(); it++)
            {
                if(it == to)
                    flag = true;
            }
            
            if(!flag)
                Vertices.push_back(to);
            
            //Only if source exists
            for(auto it = Vertices.begin(); it != Vertices.end(); it++)
            {
                if(it == from)
                {
                    it->addEdge(new Edge(weight, *it, *to));
                    return;
                }
            }
            //Otherwise create it
            Vertices.push_back(Vertices.push_back(from->addEdge(new Edge(weight, *from, *to)));)
        }
        
        //void add_edge(int from, int to, int weight);
        //void display();
        /* etc. */
        
        bool detectCycle_(Vertex v, Vertex orig)
        {
            if(v == orig)
                return true
                
            vector<Edge*> ed = v.getVec();
            for(auto it = ed.begin(); it != ed.end(); it++)
            {
            }
           
        }
        
        bool detectCycle()
        {
            for(auto it = Vertices.begin(); it != Vertices.end(); it++)
            {
                if(detectCycle_(*it, *it))
                    return true;
            }
            return false;
        }
};