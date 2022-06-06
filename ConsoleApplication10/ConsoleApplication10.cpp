﻿#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<vector<int> > dir
= { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct node {

    int height;
    int x, y;
};

struct Compare {
    bool operator()(node const& a, node const& b)
    {
        return a.height > b.height;
    }
};

int trapRainWater(vector<vector<int> >& heightMap)
{
    int M = heightMap.size();
    int N = heightMap[0].size();


    vector<vector<bool> > visited(M,
        vector<bool>(N, false));

    priority_queue<node, vector<node>, Compare> pq;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {


            if (!(i == 0 || j == 0 || i == M - 1
                || j == N - 1))
                continue;


            visited[i][j] = true;


            node t;
            t.x = i;
            t.y = j;
            t.height = heightMap[i][j];


            pq.push(t);
        }
    }
    int ans = 0;
    int max_height = INT_MIN;
    while (!pq.empty()) {

        node front = pq.top();
        pq.pop();
        max_height = max(max_height, front.height);
        int curr_x = front.x;
        int curr_y = front.y;

        for (int i = 0; i < 4; i++) {

            int new_x = curr_x + dir[i][0];
            int new_y = curr_y + dir[i][1];

            if (new_x < 0 || new_y < 0 || new_x >= M
                || new_y >= N || visited[new_x][new_y]) {
                continue;
            }

            int height = heightMap[new_x][new_y];
            if (height < max_height) {
                ans = ans + (max_height - height);
            }
            node temp;
            temp.x = new_x;
            temp.y = new_y;
            temp.height = height;
            pq.push(temp);
            visited[new_x][new_y] = true;
        }
    }
    return ans;
}

void show_vector(vector<vector<int>>& arr)
{
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
int main()
{
		vector<vector<int> > arr = { { 1, 4, 3, 1, 3, 2 },
									{ 3, 2, 1, 3, 2, 4 },
									{ 2, 3, 3, 2, 3, 1 } };
		cout << "input: \n";
		show_vector(arr);

		cout << "output: " << trapRainWater(arr) << endl << endl;
	
}

