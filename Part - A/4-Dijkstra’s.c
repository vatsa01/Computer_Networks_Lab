// Given a graph find shortest paths from source to all nodes using Dijkstra’s shortest path
// algorithm.

#include<stdio.h>
#include<stdlib.h>
void dijkstras (int n, int cost[10][10], int s, int dist[10])
{
  int i, v, visited[10], min;
  int count = 1;
  for (i = 1; i <= n; i++)
    {
      visited[i] = 0;
      dist[i] = cost[s][i];
    }
  visited[s] = 1;
  dist[s] = 0;
  while (count <= n)
    {
      min = 999;
      for (i = 1; i <= n; i++)
	{
	  if (dist[i] < min && visited[i] == 0)
	    {
	      min = dist[i];
	      v = i;
	    }

	}
      visited[v] = 1;
      count++;
      for (i = 1; i <= n; i++)
	{
	  if (dist[i] > dist[v] + cost[v][i])
	    dist[i] = dist[v] + cost[v][i];
	}
    }
}

void main ()
{
  int n, s, cost[10][10], dist[10];
  printf ("enter the number of nodes: ");
  scanf ("%d", &n);
  printf ("enter the cost matrix:\n");
  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
	{
	  scanf ("%d", &cost[i][j]);
	  if (cost[i][j] == 0)
	    {
	      cost[i][j] = 999;
	    }
	}
      printf ("\n");
    }
  printf ("enter the source node: ");
  scanf ("%d", &s);
  dijkstras (n, cost, s, dist);
  printf ("shortest paths from the source node %d are\n", s);
  printf ("\n");
  for (int i = 1; i <= n; i++)
    {
      if (s != i)
	{
	  printf ("%d -> %d = %d", s, i, dist[i]);
	  printf ("\n");
	}
    }
}
