#include <iostream>
#include <queue>

using namespace std;

//바이러스 클래스 선언
//second초에 (y, x)에 존재하는 index번호의 바이러스
class Virus {
public:
    int index;
    int second;
    int x;
    int y;
    Virus(int index, int second, int x, int y) {
        this->index = index;
        this->second = second;
        this->x = x;
        this->y = y;
    }

    // 정렬 기준은 '번호가 낮은 순서'
    bool operator <(Virus& other) {
        return this->index < other.index;
    }
};

int N, K;
int graph[200][200];
int S, X, Y;

vector<Virus> viruses;
//바이러스가 움직일 수 있는 경로
//좌, 상, 우, 하
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
    //N, K 입력
    cin >> N >> K;
    //시험관 정보 입력
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> graph[x][y];
            //시험관의 (i, j)칸에 바이러스가 존재할 경우
            if (graph[x][y] != 0)
            {
                //바이러스의 종류, 시간, 위치 입력
                viruses.push_back(Virus(graph[x][y], 0, x, y));
            }
        }
    }
    //S, X, Y 입력
    cin >> S >> X >> Y;
    //낮은 번호의 바이러스가 앞에 오도록 정렬
    sort(viruses.begin(), viruses.end());

    //BFS수행
    queue<Virus> q;
    for (int i = 0; i < viruses.size(); i++)
    {
        q.push(viruses[i]);
    }
    while (!q.empty())
    {
        Virus virus = q.front();
        q.pop();

        if (virus.second == S) break;

        for (int i = 0; i < 4; i++)
        {
            //바이러스가 퍼질 수 있는 네방향의 가능성 검사
            int next_x = virus.x + dx[i];
            int next_y = virus.y + dy[i];

            //다음 방향이 시험관을 벗어나지 않으며
            if (0 <= next_x && 0 <= next_y && N > next_x && N > next_y)
            {
                //아직 방문하지 않은 시험관 이라면
                if (graph[next_x][next_y] == 0)
                {
                    //해당 시험관에 바이러스 삽입
                    graph[next_x][next_y] = virus.index;
                    //바이러스를 관리하는 queue에 새로 증식한 바이러스 삽입
                    q.push(Virus(virus.index, virus.second + 1, next_x, next_y));
                }
            }
        }
    }

    cout << graph[X - 1][Y - 1];
}