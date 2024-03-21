#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue> 
using namespace std;

// < 2178. 미로 탐색 >

/* N×M크기의 배열로 표현되는 미로가 있다.
 * 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
 * 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 
 * (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
 * 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
*/

#pragma region BFS

const int DIRECTIONS_NUM = 4;
int n, m;
int totalCount = INT32_MAX;

struct Position
{
	int x, y;
};

enum Status
{
	Wall,
	NotVisit,
	Visited,
	End
};

Status maze[101][101] = { Wall, };
int dist[101][101] = { 0, };

const int DIR_Y[4] = { -1, 1, 0, 0 };  // y축 상하좌우
const int DIR_X[4] = { 0, 0, -1, 1 };  // x축 상하좌우


void bfs(Position startPos)
{
	queue<Position> que;

	maze[startPos.y][startPos.x] = Visited;
	dist[startPos.y][startPos.x]++;
	que.push(startPos);

	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			Position newPos;
			newPos.y = y + DIR_Y[i];
			newPos.x = x + DIR_X[i];

			if ((0 <= newPos.y && n > newPos.y) && (0 <= newPos.x && m > newPos.x) &&
				Visited != maze[newPos.y][newPos.x] && Wall != maze[newPos.y][newPos.x])
			{
				maze[newPos.y][newPos.x] = Visited;
				que.push(newPos);
				dist[newPos.y][newPos.x] = dist[y][x] + 1;
			}
		}
	}
}

int main()
{
	string line;

	scanf("%d %d", &n, &m);
	getline(cin, line);

	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		for (int j = 0; j < m; j++)
			maze[i][j] = (Status)(line[j] - '0');
	}

	Position start;
	start.x = 0;
	start.y = 0;

	bfs(start);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//		printf("%d ", maze[i][j]);
	//	printf("\n");
	//}
	//printf("\n");

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//		printf("%d ", dist[i][j]);
	//	printf("\n");
	//}

	printf("\n%d", dist[n - 1][m - 1]);

	return 0;
}

#pragma endregion

#pragma region DFS: Time Out

//struct Position
//{
//	int x, y;
//};
//
//int maze[100][100] = { -1, };
//int n, m;
//
//int totalCount = 1000;
//
//bool isCanGo(Position curPos, int newX, int newY, vector<Position> &pTracks)
//{
//	if (maze[newX][newY] == 1)
//	{
//		bool canGo = true;
//
//		for (int i = 0; i < pTracks.size(); i++)
//			if (pTracks.at(i).x == newX && pTracks.at(i).y == newY)
//				canGo = false;
//
//		if (false != canGo)
//		{
//			Position newPos;
//			newPos.x = newX, newPos.y = newY;
//			pTracks.push_back({ newPos });
//			return true;
//		}
//	}
//	return false;
//}
//
//void countMovement(int count, Position curPos, vector<Position> pTracks)
//{
//	if (curPox.X >= n - 1 && curPox.Y >= m - 1)
//	{
//		if (curPox.X != pTracks[pTracks.size()-2].x && curPox.Y == pTracks[pTracks.size()-2].y) count++;
//		if (curPox.X == pTracks[pTracks.size()-2].x && curPox.Y != pTracks[pTracks.size()-2].y) count++;
//		if (totalCount > count) 
//			totalCount = count;
//		return;
//	}
//
//	if (isCanGo(curPos, curPox.X + 1, curPox.Y, pTracks))
//		countMovement(count + 1, pTracks.back(), pTracks);
//
//	if (isCanGo(curPos, curPox.X - 1, curPox.Y, pTracks))
//		countMovement(count + 1, pTracks.back(), pTracks);
//
//	if (isCanGo(curPos, curPox.X, curPox.Y + 1, pTracks))
//		countMovement(count + 1, pTracks.back(), pTracks);
//
//	if (isCanGo(curPos, curPox.X, curPox.Y - 1, pTracks))
//		countMovement(count + 1, pTracks.back(), pTracks);
//
//}

#pragma endregion