int parents[1001];

int find(int x)
{
  return parents[x] == x ? x : (parents[x] = find(parents[x]));
}

bool unite(int i, int j)
{
  i = find(i);
  j = find(j);

  if (i == j)
    return false;
  parents[j] = i;
  return true;
}

struct t
{
  int d;
  int i;
  int j;
};

bool compare(t a, t b)
{
  return a.d < b.d;
}

class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }

    vector<t> edges;

    t temp;

    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        temp.d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        temp.i = i;
        temp.j = j;

        edges.emplace_back(temp);
      }
    }

    sort(edges.begin(), edges.end(), compare);

    int sum = 0;
    int taked = 0;

    for (int i = 0; i < edges.size(); i++)
    {
      if (taked == n - 1)
        return sum;
      if (unite(edges[i].i, edges[i].j))
      {
        sum += edges[i].d;
      }
    }

    return sum;
  }
};