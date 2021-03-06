/**
* Floyd算法：解决全源最短路径问题
**/
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAXV = 200; //最大顶点数

int n, m; //顶点数、边数
int dis[MAXV][MAXV]; //顶点i和j的最短距离

void Floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j]; //找到更短的路径
            }
        }
    }
}

int main() {
    int u, v, w;
    fill(dis[0], dis[0] + MAXV * MAXV, INF); //dis数组赋初值
    scanf("%d%d", &n, &m); //顶点数n、边数m
    for (int i = 0; i < n; i++)
        dis[i][i] = 0; //顶点i到顶点i的距离初始化为0
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = w; //以有向图为例进行输入
    }
    Floyd(); //Floyd算法入口
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
