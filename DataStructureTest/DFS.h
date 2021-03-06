#pragma once
#include "Stack.h"
#include <vector>

class DFS
{
public:
	std::vector<int> VisitVertex(std::vector<std::vector<int>> v)
	{
		Stack<int> stack(v.size());
		std::vector<int> visited;
		stack.Push(0);

		int cur;
		while (stack.Count() != 0)
		{
			cur = stack.Pop();
			for (int Neighbor : v[cur])
				if (std::find(visited.begin(), visited.end(), Neighbor) == visited.end())
					stack.Push(Neighbor);
			visited.push_back(cur);
		}
		return visited;
	}
};