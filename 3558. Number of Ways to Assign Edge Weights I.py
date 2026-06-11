class Solution:
    def assignEdgeWeights(
        self,
        edge_list: List[List[int]]
    ) -> int:

        MODULO = 10**9 + 7

        total_nodes = len(edge_list) + 1

        # Adjacency list representation of the tree
        adjacency_list = [
            [] for _ in range(total_nodes + 1)
        ]

        # Build the graph
        for source_node, destination_node in edge_list:

            adjacency_list[source_node].append(
                destination_node
            )

            adjacency_list[destination_node].append(
                source_node
            )

        # Maximum depth found in the tree
        maximum_depth = 0

        # (node, depth)
        dfs_stack = [(1, 0)]

        visited_nodes = [False] * (
            total_nodes + 1
        )

        visited_nodes[1] = True

        # Iterative DFS
        while dfs_stack:

            current_node, current_depth = (
                dfs_stack.pop()
            )

            maximum_depth = max(
                maximum_depth,
                current_depth
            )

            for neighbor_node in adjacency_list[current_node]:

                if not visited_nodes[neighbor_node]:

                    visited_nodes[neighbor_node] = True

                    dfs_stack.append(
                        (
                            neighbor_node,
                            current_depth + 1
                        )
                    )

        # Return 2^(maximum_depth - 1) mod MODULO
        return pow(
            2,
            maximum_depth - 1,
            MODULO
        )
