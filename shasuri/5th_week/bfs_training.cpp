// #include <iostream>
#define MAX_MAZE_SIZE 10
using namespace std;

int mazeSize;
bool checkCoord(int x, int y);
void visitedClear(void);
void bfs_init(int map_size, int map[10][10]);
int bfs(int x1, int y1, int x2, int y2);

struct MazeCoord
{
    int x;
    int y;
    int step;
    bool wall;
    bool visited;
};
MazeCoord mazeMap[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
class CoordQueue
{
private:
    MazeCoord container[MAX_MAZE_SIZE * MAX_MAZE_SIZE];
    int head = -1;
    int tail = -1;

public:
    CoordQueue();
    ~CoordQueue();
    void enqueue(MazeCoord);
    MazeCoord dequeue(void);
};

CoordQueue::CoordQueue() {}
CoordQueue::~CoordQueue()
{
    visitedClear();
    head = -1;
    tail = -1;
}
void CoordQueue::enqueue(MazeCoord m)
{
    if (tail >= MAX_MAZE_SIZE * MAX_MAZE_SIZE)
    {
        // cout << "full!" << endl;
        return;
    }
    container[++tail] = m;
}

MazeCoord CoordQueue::dequeue(void)
{

    if (head == tail)
        return MazeCoord{-1, -1, -1, 0, 0};
    return container[++head];
}

bool checkCoord(int x, int y)
{
    // cout << endl
    // << x << " : " << y;
    if (x > -1 &&
        x < mazeSize &&
        y > -1 &&
        y < mazeSize &&
        !mazeMap[y][x].wall &&
        !mazeMap[y][x].visited)
    {
        // cout << "T" << endl;
        return true;
    }
    return false;
}

void visitedClear(void)
{
    for (int i = 0; i < mazeSize; i++)
        for (int j = 0; j < mazeSize; j++)
        {
            mazeMap[i][j].step = 0;
            mazeMap[i][j].visited = false;
        }
}

void bfs_init(int map_size, int map[10][10])
{
    mazeSize = map_size;

    for (int i = 0; i < mazeSize; i++)
    {
        for (int j = 0; j < mazeSize; j++)
        {
            mazeMap[i][j].x = j;
            mazeMap[i][j].y = i;
            mazeMap[i][j].step = 0;
            mazeMap[i][j].wall = map[i][j];
            mazeMap[i][j].visited = false;
        }
    }
}
int bfs(int x1, int y1, int x2, int y2)
{
    // visitedClear();

    int srcX = x1 - 1;
    int srcY = y1 - 1;
    int dstX = x2 - 1;
    int dstY = y2 - 1;

    CoordQueue coordQueue;
    int tmpStep;
    MazeCoord presentCoord = mazeMap[srcY][srcX];
    mazeMap[srcY][srcX].visited = true;
    // cout << endl;
    while (true)
    {
        // cout << endl
        // << presentCoord.x << " : " << presentCoord.y << " : " << presentCoord.step;

        if (presentCoord.x == dstX && presentCoord.y == dstY)
            return presentCoord.step;

        if (checkCoord(presentCoord.x - 1, presentCoord.y))
        {
            mazeMap[presentCoord.y][presentCoord.x - 1].visited = true;
            mazeMap[presentCoord.y][presentCoord.x - 1].step = presentCoord.step + 1;
            coordQueue.enqueue(mazeMap[presentCoord.y][presentCoord.x - 1]);
        }
        if (checkCoord(presentCoord.x, presentCoord.y - 1))
        {
            mazeMap[presentCoord.y - 1][presentCoord.x].visited = true;
            mazeMap[presentCoord.y - 1][presentCoord.x].step = presentCoord.step + 1;
            coordQueue.enqueue(mazeMap[presentCoord.y - 1][presentCoord.x]);
        }
        if (checkCoord(presentCoord.x + 1, presentCoord.y))
        {
            mazeMap[presentCoord.y][presentCoord.x + 1].visited = true;
            mazeMap[presentCoord.y][presentCoord.x + 1].step = presentCoord.step + 1;
            coordQueue.enqueue(mazeMap[presentCoord.y][presentCoord.x + 1]);
        }
        if (checkCoord(presentCoord.x, presentCoord.y + 1))
        {
            mazeMap[presentCoord.y + 1][presentCoord.x].visited = true;
            mazeMap[presentCoord.y + 1][presentCoord.x].step = presentCoord.step + 1;
            coordQueue.enqueue(mazeMap[presentCoord.y + 1][presentCoord.x]);
        }

        presentCoord = coordQueue.dequeue();

        if (presentCoord.step == -1)
            return -1;
    }
    return 0;
}