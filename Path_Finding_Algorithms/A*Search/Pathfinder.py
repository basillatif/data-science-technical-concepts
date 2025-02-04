'''
The Pathfinder class is responsible for finding a solution (i.e., a
sequence of actions) that takes the agent from the initial state to all
of the goals with optimal cost.

This task is done in the solve method, as parameterized
by a maze pathfinding problem, and is aided by the SearchTreeNode DS.
'''
from queue import PriorityQueue
import unittest
from MazeProblem import MazeProblem
from SearchTreeNode import SearchTreeNode

def manhattan_cost(state, goal):
    return abs(state[0] - goal[0]) + abs(state[1] - goal[1])

def createPath(node):
    result = []
    while node.parent:
        result.insert(0, node.action)
        node = node.parent
    return result

def solve(problem, initial, goals):

    heuristic_cost_from_initial = manhattan_cost(initial, goals[0])
    initial_node = SearchTreeNode(initial, None, None, 0, heuristic_cost_from_initial)
    closed_list = []
    cost_to_get_there = 0

    frontier = PriorityQueue()
    frontier.put(initial_node)

    while frontier:
        parent = frontier.get()

        if parent.heuristicCost == 0:
            return createPath(parent)

        closed_list.append(parent.state)
        possible_nodes = problem.transitions(parent.state) #allowable axns w initial

        for node_we_are_evaluating in possible_nodes:
            if node_we_are_evaluating[2] not in closed_list:
                cost_to_get_there = problem.cost(node_we_are_evaluating[2]) + parent.totalCost
                heuristic_cost = manhattan_cost(node_we_are_evaluating[2], goals[0])
                new_node = SearchTreeNode(node_we_are_evaluating[2], node_we_are_evaluating[0], parent, cost_to_get_there, heuristic_cost)
                frontier.put(new_node)
    return "No solution"

class PathfinderTests(unittest.TestCase):

    def test_maze1(self):
        maze = ["XXXXXXX",
                "X.....X",
                "X.M.M.X",
                "X.X.X.X",
                "XXXXXXX"]
        problem = MazeProblem(maze)
        initial = (1, 3)
        goals = [(5, 3)]
        soln = solve(problem, initial, goals)
        (soln_cost, is_soln) = problem.soln_test(soln, initial, goals)
        self.assertTrue(is_soln)
        self.assertEqual(soln_cost, 8)

    # def test_maze2(self):
    #     maze = ["XXXXXXX",
    #             "X.....X",
    #             "X.M.M.X",
    #             "X.X.X.X",
    #             "XXXXXXX"]
    #     problem = MazeProblem(maze)
    #     initial = (1, 3)
    #     goals   = [(3, 3),(5, 3)]
    #     soln = solve(problem, initial, goals)
    #     (soln_cost, is_soln) = problem.soln_test(soln, initial, goals)
    #     self.assertTrue(is_soln)
    #     self.assertEqual(soln_cost, 12)
    #
    # def test_maze3(self):
    #     maze = ["XXXXXXX",
    #             "X.....X",
    #             "X.M.MMX",
    #             "X...M.X",
    #             "XXXXXXX"]
    #     problem = MazeProblem(maze)
    #     initial = (5, 1)
    #     goals   = [(5, 3), (1, 3), (1, 1)]
    #     soln = solve(problem, initial, goals)
    #     (soln_cost, is_soln) = problem.soln_test(soln, initial, goals)
    #     self.assertTrue(is_soln)
    #     self.assertEqual(soln_cost, 12)
    #
    # def test_maze4(self):
    #     maze = ["XXXXXXX",
    #             "X.....X",
    #             "X.M.XXX",
    #             "X...X.X",
    #             "XXXXXXX"]
    #     problem = MazeProblem(maze)
    #     initial = (5, 1)
    #     goals   = [(5, 3), (1, 3), (1, 1)]
    #     soln = solve(problem, initial, goals)
    #     self.assertTrue(soln == None)


if __name__ == '__main__':
    unittest.main()
